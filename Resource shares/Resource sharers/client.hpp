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
	uint32_t _ip_addr;//Ҫ��Ե�����ip��ַ
	bool _pair_ret;//���ڴ����Խ��
};
class Client 
{
public:
	bool Start()
	{
		//�ͻ��˳�����Ҫѭ�����У���Ϊ�����ļ�����ֻ����һ��
		//ѭ������ÿ������һ���ļ�֮�󶼻����½����������---������
		while(1)
		{
			GetOnlineHost();
		}
		return true;
	}
	//������Ե��߳���ں���
	void HostPair(Host* host)
	{
		//1.��֯httpЭ���ʽ����������
		//2.�һ��tcp�ͻ��ˣ������ݷ���
		//3.�ȴ��������˵Ļظ��������н���
		//�������ʹ�õ�������httplibʵ��
		host->_pair_ret = false;
		char buf[MAX_IPBUFFER] = { 0 };
		//�������ֽ���IP��ַת�����ַ������ʮ����IP��ַ
		inet_ntop(AF_INET, &host->_ip_addr, buf, MAX_IPBUFFER);
		//ʵ����httplib�ͻ��˶���
		httplib::Client cli(buf, P2P_PORT);
		//�����˷�����ԴΪ/hostpair��GET����//������ʧ��Get�᷵��NULL
		auto rsp = cli.Get("/hostpair");
		//�ж���Ӧ����Ƿ���ȷ
		if (rsp && rsp->status == 200)
		{
			//�����������
			host->_pair_ret = true;
		}
		return;
	}
	//��ȡ��������
	bool GetOnlineHost()
	{
		//�Ƿ�����ƥ�䣬Ĭ���ǽ���ƥ��ģ����Ѿ�ƥ�����online������Ϊ�������û�ѡ��
		char ch = 'Y';
		if (!_online_host.empty()) 
		{
			std::cout << "�Ƿ����²鿴����������Y/N��: ";
			fflush(stdout);
			std::cin >> ch;
		}
		if (ch == 'Y')
		{
			std::cout << "��ʼ����ƥ��...\n";
			//1.��ȡ������Ϣ�������õ������������е�IP��ַ�б�
			std::vector<Adapter> list;
			AdapterUtil::GetAllAdapter(&list);
			std::vector<Host> host_list;
			//�õ�����������IP��ַ�б�
			for (int i = 0; i < list.size(); ++i)
			{
				uint32_t ip = list[i]._ip_addr;
				uint32_t mask = list[i]._mask_addr;
				//���������
				uint32_t net = ntohl(ip & mask);
				//�������������
				uint32_t max_host = (~ntohl(mask));
				for (int j = 1; j < (int32_t)max_host; ++j)
				{
					//�������IP�ļ���Ӧ��ʹ�������ֽ��������ź�������
					uint32_t host_ip = net + j;
					Host host;
					host._ip_addr = htonl(host_ip);//����������ֽ���ת���������ֽ���
					host._pair_ret = false;
					host_list.push_back(host);
				}
			}
			//2.��host_list�е����������߳̽������
			std::vector<std::thread*> thr_list(host_list.size());
			for (int i = 0; i < host_list.size(); ++i)
			{
				thr_list[i] = new std::thread(&Client::HostPair, this, &host_list[i]);
			}
			std::cout << "��������ƥ���У����Ժ�...\n";
			//3.�ȴ������߳����������ϣ��ж���Խ����������������ӵ�online_host��
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
		//����������������IP��ַ��ӡ���������û�ѡ��
		for (int i = 0; i < _online_host.size(); ++i)
		{
			char buf[MAX_IPBUFFER] = { 0 };
			inet_ntop(AF_INET, &_online_host[i]._ip_addr, buf, MAX_IPBUFFER);
			std::cout << "\t" << buf << std::endl;
		}
		std::cout << "��ѡ�������������ȡ�����ļ��б�";
		fflush(stdout);
		std::string select_ip;
		std::cin >> select_ip;
		//�û�ѡ������֮�󣬵��û�ȡ�ļ��б�ӿ�
		GetShareList(select_ip);
		return true;
	}
	//��ȡ�ļ��б�
	bool GetShareList(const std::string &host_ip)
	{
		//1.�ȷ�������
		//2.�õ���Ӧ֮�󣬽������ģ��ļ����ƣ�
		httplib::Client cli(host_ip.c_str(), P2P_PORT);
		auto rsp = cli.Get("/list");
		if (rsp == NULL || rsp->status != 200)
		{
			std::cerr << "��ȡ�ļ��б���Ӧ����\n";
			return false;
		}
		//��ӡ����-��ӡ��������Ӧ���ļ������б��û�ѡ��
		//body: filename1 /r/n filename2...
		std::cout << rsp->body << std::endl;
		std::cout << "\n��ѡ��Ҫ���ص��ļ���";
		fflush(stdout);
		std::string filename;
		std::cin >> filename;
		RangeDownload(host_ip, filename);
		return true;
	}
	//�����ļ�
	bool DownloadFile(const std::string &host_ip, const std::string &filename)
	{
		//���ļ�һ�������أ��������ļ��Ƚ�Σ��
		//1.�����˷����ļ���������
		//2.�õ���Ӧ�������Ӧ����е�body���ľ����ļ�����
		//3.�����ļ������ļ�����д���ļ��У��ر��ļ�
		std::string req_path = "/download/" + filename;
		httplib::Client cli(host_ip.c_str(), P2P_PORT);
		auto rsp = cli.Get(req_path.c_str());
		if (rsp == NULL || rsp->status != 200)
		{
			std::cout << "�����ļ�����ȡ��Ӧ��Ϣʧ��:" << rsp->status << std::endl;
			return false;
		}
		if (!boost::filesystem::exists(DOWNLOAD_PATH))
		{
			boost::filesystem::create_directory(DOWNLOAD_PATH);
		}
		std::string realpath = DOWNLOAD_PATH  + filename;
		if (FileUtil::Write(realpath, rsp->body, 0) == false)
		{
			std::cerr << "�ļ�����ʧ��\n";
			return false;
		}
		std::cout << "�ļ����سɹ�\n";
		return true;
	}
	bool RangeDownload(const std::string &host_ip, const std::string &filename)
	{
		//1.����Head����ͨ����Ӧ�е�Content_Length��ȡ�ļ���С	
		std::string req_path = "/download/" + filename;
		httplib::Client cli(host_ip.c_str(), P2P_PORT);
		auto rsp = cli.Head(req_path.c_str());
		if (rsp == NULL || rsp->status != 200)
		{
			std::cout << "��ȡ�ļ���Сʧ��\n";
			return false;
		}
		std::string clen = rsp->get_header_value("Content-Length");
		int filesize = StringUtil::Str2Dig(clen);

		//2.�����ļ���С���зֿ�
		//int range_count = filesize / MAX_RANGE;
		//a.���ļ���СС�ڿ��С����ֱ�������ļ�
		if (filesize < MAX_RANGE)
		{
			std::cout << "�ļ���С��ֱ�������ļ�\n";
			return DownloadFile(host_ip, filename);
		}
		//b.���ļ���С�����������С,��ֿ����Ϊ�ļ���С���Կ��С+1
		std::cout << "�ļ����󣬷ֿ��������\n";
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
			{//ĩβ�ֿ�
				range_end = filesize - 1;
			}
			else
			{
				range_end = ((i + 1) * MAX_RANGE) - 1;
			}
			std::cout << "�ͻ�������ֿ�����" << range_start << "-" << range_end << std::endl;
			//c.���ļ���С�պ��������С����ֿ����Ϊ�ļ���С���Կ��С
			//3.��һ����ֿ���������ݣ��õ���Ӧ��д���ļ���ָ��λ��

			//header.insert(httplib::make_range_header({ { range_start, range_end } }));//����һ��range����
			std::stringstream tmp;
			tmp << "byte=" << range_start << "-" << range_end;
			httplib::Client cli(host_ip.c_str(), P2P_PORT);
			httplib::Headers header;
			header.insert(std::make_pair("Range", tmp.str()));
			auto rsp = cli.Get(req_path.c_str(), header);//�����˷���һ���ֶ�����
			if (rsp == NULL || rsp->status != 206)
			{
				std::cout << "���������ļ�ʧ��\n";
				return false;
			}
			std::string real_path = DOWNLOAD_PATH + filename;
			if (!boost::filesystem::exists(DOWNLOAD_PATH))
			{
				boost::filesystem::create_directory(DOWNLOAD_PATH);
			}
			//��ȡ�ļ��ɹ������ļ��зֿ�д������
			FileUtil::Write(real_path, rsp->body, range_start);
		}
		std::cout << "�ļ����سɹ�\n";
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
		//�����Կͻ�������Ĵ���ʽ��Ӧ��ϵ
		_srv.Get("/hostpair", HostPair);
		_srv.Get("/list", ShareList);
		//.��ʾƥ���г���\r��\n֮��������ַ�
		//*��ʾƥ��ǰ����ַ������
		//��ֹ���Ϸ��������ͻ������������м���download·��
		_srv.Get("/download.*",Download); //������ʽ

		_srv.listen("0.0.0.0", P2P_PORT);

		return true;
	}
private:
    static void HostPair(const httplib::Request &req, httplib::Response &rsp)
	{
		rsp.status = 200;
		return;
	}
	//��ȡ�����ļ��б�---������������һ������Ŀ¼���������Ŀ¼�µĶ��ǹ����ļ�
	static void ShareList(const httplib::Request &req, httplib::Response &rsp)
	{
		//1.�鿴Ŀ¼�Ƿ���ڣ���Ŀ¼�����ڣ��򴴽����Ŀ¼
		if (!boost::filesystem::exists(SHARED_PATH))
		{
			//����Ŀ¼
			boost::filesystem::create_directory(SHARED_PATH);
		}
		//ʵ����Ŀ¼������
		boost::filesystem::directory_iterator begin(SHARED_PATH);
		//ʵ����Ŀ¼��������ĩβ
		boost::filesystem::directory_iterator end;

		//��ʼ����Ŀ¼
		for (; begin != end; ++begin)
		{
			if (boost::filesystem::is_directory(begin->status()))
			{
				//��ǰ�汾����ֻ��ȡ��ͨ�ļ����ƣ��������Ŀ¼�Ĳ���
				continue;
			}
			//ֻҪ�ļ�����Ҫ·��
			std::string name = begin->path().filename().string();
			//filename1 \r\n filename2 \r\n
			rsp.body += name + "\r\n";
		}
		rsp.status = 200;
		return;
	}
	static void Download(const httplib::Request &req, httplib::Response &rsp)
	{
		std::cout << "������յ��ļ���������:" << req.path << std::endl;
		//req.path---�ͻ����������Դ·��   /download/filename.txt
		boost::filesystem::path req_path(req.path);
		std::string name = req_path.filename().string(); //ֻ��ȡ�ļ����ƣ�  filename.txt
		std::cout << "������յ�ʵ�ʵ��ļ���������:" << name << std::endl;
		std::string realpath = SHARED_PATH + name;  //ʵ���ļ�·��Ӧ�����ڹ���Ŀ¼�µ�
		std::cout << "������յ�ʵ�ʵ��ļ�����·��:" << realpath << std::endl;
		if (!boost::filesystem::exists(realpath) || boost::filesystem::is_directory(realpath))
		{
			rsp.status = 404;
			return;
		}
		if (req.method == "GET")
		{
			//�ж��Ƿ��Ƿֿ鴫������ݣ���������������Ƿ���rangeͷ���ֶ�
			if (req.has_header("Range"))
			{//�ж�����ͷ���Ƿ����Range�ֶ�
				//�����һ���ֿ鴫��
				//��Ҫ֪���ֿ������Ƕ���
				std::string range_str = req.get_header_value("Range");
				int range_start;
				int range_end;
				FileUtil::GetRange(range_str, &range_start, &range_end);
				int range_len = range_end - range_start + 1;

				std::cout << "Range:" << range_start << "-" << range_end << std::endl;
				FileUtil::ReadRange(realpath, &rsp.body, range_len, range_start);
				rsp.status = 206;
				std::cout << "�������Ӧ�����������\n";
			}
			else
			{
				//û��Rangeͷ��������һ����ɵ��ļ�����
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
			//��������HEAD����Ŀͻ���ֻҪͷ����Ҫ����
			uint64_t filesize = FileUtil::GetFileSize(realpath);
			rsp.set_header("Content-Length", std::to_string(filesize).c_str());//������Ӧheaderͷ����Ϣ�ӿ�
			rsp.status = 200;
		}
		return;
	}
private:
	httplib::Server _srv;
};
