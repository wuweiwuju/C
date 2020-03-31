#pragma once
#include"util.hpp"
#include<boost/filesystem.hpp>
#include<thread>
#include<string>
#include"httplib.h"

#define P2P_PORT 9000
#define MAX_IPBUFFER 16
#define MAX_RANGE (100 * 1024 * 1024)
#define SHARED_PATH "./Shared/"
#define DOWNLOAD_PATH "./Download/"

class Host
{
public:
	uint32_t _ip_addr;//要配对的主机ip地址
	bool _pair_ret;//用于存放配对结果
};
class Client 
{
public:
	bool Start()
	{
		//客户端程序需要循环运行，因为下载文件不是只下载一次
		//循环运行每次下载一个文件之后都会重新进行主机配对---不合理
		while(1)
		{
			GetOnlineHost();
		}
		return true;
	}
	//主机配对的线程入口函数
	void HostPair(Host* host)
	{
		//1.组织http协议格式的请求数据
		//2.搭建一个tcp客户端，将数据发送
		//3.等待服务器端的回复，并进行解析
		//这个过程使用第三方库httplib实现
		host->_pair_ret = false;
		char buf[MAX_IPBUFFER] = { 0 };
		//将网络字节序IP地址转换成字符串点分十进制IP地址
		inet_ntop(AF_INET, &host->_ip_addr, buf, MAX_IPBUFFER);
		//实例化httplib客户端对象
		httplib::Client cli(buf, P2P_PORT);
		//向服务端发送资源为/hostpair的GET请求//若连接失败Get会返回NULL
		auto rsp = cli.Get("/hostpair");
		//判断响应结果是否正确
		if (rsp && rsp->status == 200)
		{
			//重置配对请求
			host->_pair_ret = true;
		}
		return;
	}
	//获取在线主机
	bool GetOnlineHost()
	{
		//是否重新匹配，默认是进行匹配的，若已经匹配过，online主机不为空则让用户选择
		char ch = 'Y';
		if (!_online_host.empty()) 
		{
			std::cout << "是否重新查看在线主机（Y/N）: ";
			fflush(stdout);
			std::cin >> ch;
		}
		if (ch == 'Y')
		{
			std::cout << "开始主机匹配...\n";
			//1.获取网卡信息，进而得到局域网中所有的IP地址列表
			std::vector<Adapter> list;
			AdapterUtil::GetAllAdapter(&list);
			std::vector<Host> host_list;
			//得到所有主机的IP地址列表
			for (int i = 0; i < list.size(); ++i)
			{
				uint32_t ip = list[i]._ip_addr;
				uint32_t mask = list[i]._mask_addr;
				//计算网络号
				uint32_t net = ntohl(ip & mask);
				//计算最大主机号
				uint32_t max_host = (~ntohl(mask));
				for (int j = 1; j < (int32_t)max_host; ++j)
				{
					//这个主机IP的计算应该使用主机字节序的网络号和主机号
					uint32_t host_ip = net + j;
					Host host;
					host._ip_addr = htonl(host_ip);//将这个主机字节序转换成网络字节序
					host._pair_ret = false;
					host_list.push_back(host);
				}
			}
			//2.对host_list中的主机创建线程进行配对
			std::vector<std::thread*> thr_list(host_list.size());
			for (int i = 0; i < host_list.size(); ++i)
			{
				thr_list[i] = new std::thread(&Client::HostPair, this, &host_list[i]);
			}
			std::cout << "正在主机匹配中，请稍后...\n";
			//3.等待所有线程主机配对完毕，判断配对结果，将在线主机添加到online_host中
			for (int i = 0; i < host_list.size(); ++i)
			{
				thr_list[i]->join();
				if (host_list[i]._pair_ret == true)
				{
					_online_host.push_back(host_list[i]);
				}
				delete thr_list[i];
			}
		}
		//将所有在线主机的IP地址打印出来，供用户选择
		for (int i = 0; i < _online_host.size(); ++i)
		{
			char buf[MAX_IPBUFFER] = { 0 };
			inet_ntop(AF_INET, &_online_host[i]._ip_addr, buf, MAX_IPBUFFER);
			std::cout << "\t" << buf << std::endl;
		}
		std::cout << "请选择配对主机，读取共享文件列表：";
		fflush(stdout);
		std::string select_ip;
		std::cin >> select_ip;
		//用户选择主机之后，调用获取文件列表接口
		GetShareList(select_ip);
		return true;
	}
	//获取文件列表
	bool GetShareList(const std::string &host_ip)
	{
		//1.先发送请求
		//2.得到响应之后，解析正文（文件名称）
		httplib::Client cli(host_ip.c_str(), P2P_PORT);
		auto rsp = cli.Get("/list");
		if (rsp == NULL || rsp->status != 200)
		{
			std::cerr << "获取文件列表响应错误\n";
			return false;
		}
		//打印正文-打印服务器响应的文件名称列表供用户选择
		//body: filename1 /r/n filename2...
		std::cout << rsp->body << std::endl;
		std::cout << "\n请选择要下载的文件：";
		fflush(stdout);
		std::string filename;
		std::cin >> filename;
		RangeDownload(host_ip, filename);
		return true;
	}
	//下载文件
	bool DownloadFile(const std::string &host_ip, const std::string &filename)
	{
		//若文件一次性下载，遇到大文件比较危险
		//1.向服务端发送文件下载请求
		//2.得到响应结果，响应结果中的body正文就是文件数据
		//3.创建文件，将文件数据写入文件中，关闭文件
		std::string req_path = "/download/" + filename;
		httplib::Client cli(host_ip.c_str(), P2P_PORT);
		auto rsp = cli.Get(req_path.c_str());
		if (rsp == NULL || rsp->status != 200)
		{
			std::cout << "下载文件，获取响应信息失败:" << rsp->status << std::endl;
			return false;
		}
		if (!boost::filesystem::exists(DOWNLOAD_PATH))
		{
			boost::filesystem::create_directory(DOWNLOAD_PATH);
		}
		std::string realpath = DOWNLOAD_PATH  + filename;
		if (FileUtil::Write(realpath, rsp->body, 0) == false)
		{
			std::cerr << "文件下载失败\n";
			return false;
		}
		std::cout << "文件下载成功\n";
		return true;
	}
	bool RangeDownload(const std::string &host_ip, const std::string &filename)
	{
		//1.发送Head请求，通过响应中的Content_Length获取文件大小	
		std::string req_path = "/download/" + filename;
		httplib::Client cli(host_ip.c_str(), P2P_PORT);
		auto rsp = cli.Head(req_path.c_str());
		if (rsp == NULL || rsp->status != 200)
		{
			std::cout << "获取文件大小失败\n";
			return false;
		}
		std::string clen = rsp->get_header_value("Content-Length");
		int filesize = StringUtil::Str2Dig(clen);

		//2.根据文件大小进行分块
		//int range_count = filesize / MAX_RANGE;
		//a.若文件大小小于块大小，则直接下载文件
		if (filesize < MAX_RANGE)
		{
			std::cout << "文件较小，直接下载文件\n";
			return DownloadFile(host_ip, filename);
		}
		//b.若文件大小不能整除块大小,则分块个数为文件大小除以块大小+1
		std::cout << "文件过大，分块进行下载\n";
		std::cout << filesize << std::endl;
		int range_count = 0;
		if (filesize % MAX_RANGE == 0)
		{
			range_count = filesize / MAX_RANGE;
		}
		else
		{
			range_count = (filesize / MAX_RANGE) + 1;
		}
		int range_start = 0, range_end = 0;
		for (int i = 0; i < range_count; i++)
		{
			range_start = i * MAX_RANGE;
			if (i == (range_count - 1))
			{//末尾分块
				range_end = filesize - 1;
			}
			else
			{
				range_end = ((i + 1) * MAX_RANGE) - 1;
			}
			std::cout << "客户端请求分块下载" << range_start << "-" << range_end << std::endl;
			//c.若文件大小刚好整除块大小，则分块个数为文件大小除以块大小
			//3.逐一请求分块区间的数据，得到响应后写入文件的指定位置

			//header.insert(httplib::make_range_header({ { range_start, range_end } }));//设置一个range区间
			std::stringstream tmp;
			tmp << "byte=" << range_start << "-" << range_end;
			httplib::Client cli(host_ip.c_str(), P2P_PORT);
			httplib::Headers header;
			header.insert(std::make_pair("Range", tmp.str()));
			auto rsp = cli.Get(req_path.c_str(), header);//向服务端发送一个分段请求
			if (rsp == NULL || rsp->status != 206)
			{
				std::cout << "区间下载文件失败\n";
				return false;
			}
			std::string real_path = DOWNLOAD_PATH + filename;
			if (!boost::filesystem::exists(DOWNLOAD_PATH))
			{
				boost::filesystem::create_directory(DOWNLOAD_PATH);
			}
			//获取文件成功，向文件中分块写入数据
			FileUtil::Write(real_path, rsp->body, range_start);
		}
		std::cout << "文件下载成功\n";
		return true;
	}

private:
	std::vector<Host> _online_host;
};

class Server
{
public:
	bool Start()
	{
		//添加针对客户端请求的处理方式对应关系
		_srv.Get("/hostpair", HostPair);
		_srv.Get("/list", ShareList);
		//.表示匹配中除了\r或\n之外的任意字符
		//*表示匹配前面的字符任意次
		//防止与上方的请求冲突，因此在请求中加入download路径
		_srv.Get("/download.*",Download); //正则表达式

		_srv.listen("0.0.0.0", P2P_PORT);

		return true;
	}
private:
    static void HostPair(const httplib::Request &req, httplib::Response &rsp)
	{
		rsp.status = 200;
		return;
	}
	//获取共享文件列表---在主机上设置一个共享目录，凡是这个目录下的都是共享文件
	static void ShareList(const httplib::Request &req, httplib::Response &rsp)
	{
		//1.查看目录是否存在，若目录不存在，则创建这个目录
		if (!boost::filesystem::exists(SHARED_PATH))
		{
			//创建目录
			boost::filesystem::create_directory(SHARED_PATH);
		}
		//实例化目录迭代器
		boost::filesystem::directory_iterator begin(SHARED_PATH);
		//实例化目录迭代器的末尾
		boost::filesystem::directory_iterator end;

		//开始迭代目录
		for (; begin != end; ++begin)
		{
			if (boost::filesystem::is_directory(begin->status()))
			{
				//当前版本我们只获取普通文件名称，不做多层目录的操作
				continue;
			}
			//只要文件名不要路径
			std::string name = begin->path().filename().string();
			//filename1 \r\n filename2 \r\n
			rsp.body += name + "\r\n";
		}
		rsp.status = 200;
		return;
	}
	static void Download(const httplib::Request &req, httplib::Response &rsp)
	{
		std::cout << "服务端收到文件下载请求:" << req.path << std::endl;
		//req.path---客户端请求的资源路径   /download/filename.txt
		boost::filesystem::path req_path(req.path);
		std::string name = req_path.filename().string(); //只获取文件名称；  filename.txt
		std::cout << "服务端收到实际的文件下载名称:" << name << std::endl;
		std::string realpath = SHARED_PATH + name;  //实际文件路径应该是在共享目录下的
		std::cout << "服务端收到实际的文件下载路径:" << realpath << std::endl;
		if (!boost::filesystem::exists(realpath) || boost::filesystem::is_directory(realpath))
		{
			rsp.status = 404;
			return;
		}
		if (req.method == "GET")
		{
			//判断是否是分块传输的依据，就是这次请求中是否有range头部字段
			if (req.has_header("Range"))
			{//判断请求头中是否包含Range字段
				//这就是一个分块传输
				//需要知道分块区间是多少
				std::string range_str = req.get_header_value("Range");
				int range_start;
				int range_end;
				FileUtil::GetRange(range_str, &range_start, &range_end);
				int range_len = range_end - range_start + 1;

				std::cout << "Range:" << range_start << "-" << range_end << std::endl;
				FileUtil::ReadRange(realpath, &rsp.body, range_len, range_start);
				rsp.status = 206;
				std::cout << "服务端响应区间数据完毕\n";
			}
			else
			{
				//没有Range头部，则是一个完成的文件下载
				if (FileUtil::Read(realpath, &rsp.body) == false)
				{
					rsp.status = 500;
					return;
				}
				rsp.status = 200;
			}
		}
		else
		{
			//这个是针对HEAD请求的客户端只要头部不要正文
			uint64_t filesize = FileUtil::GetFileSize(realpath);
			rsp.set_header("Content-Length", std::to_string(filesize).c_str());//设置响应header头部信息接口
			rsp.status = 200;
		}
		return;
	}
private:
	httplib::Server _srv;
};
