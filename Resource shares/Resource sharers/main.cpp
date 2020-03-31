#include"client.hpp"

void helloworld(const httplib::Request &req, httplib::Response &rsp)
{
	printf("httplib server recv a req:%s\n", req.path.c_str());
	rsp.set_content("<html><h1>HelloWorld</h1></html>", "text/html");
	rsp.status = 200;
}

void Scandir()
{
	const char *ptr = "./";
	//定义一个目录迭代器对象
	boost::filesystem::directory_iterator begin(ptr);
	boost::filesystem::directory_iterator end;

	for (; begin != end; ++begin)
	{
		//begin->status() 目录中当前文件的状态信息
		//boost::filesystem::is_directory() 判断当前文件是否是一个目录
		if (boost::filesystem::is_directory(begin->status()))
			std::cout << begin->path().string() << "是一个目录\n";//获取当前迭代文件的文件名
		else
		{
			std::cout << begin->path().string() << "是一个普通文件\n";
			//begin->path().filename() 获取文件路径名中的文件名称，而不要路径
			std::cout << "文件名：" << begin->path().filename().string() << std::endl;
		}
			
	}
}
void test()
{
		Scandir();

	//std::vector<Adapter> list;
	//AdapterUtil::GetAllAdapter(&list);

	/*httplib::Server srv;

	srv.Get("/", helloworld);

	srv.listen("0.0.0.0", 9000);*/
}
void ClientRun()
{
	Client cli;
	cli.Start();
}
int main(int argc, char *argv[])
{
	//在主线程中要运行客户端模块以及服务端模块
	//创建一个线程运行客户端模块，主线程运行服务端模块

	//若客户端运行的时候，服务端还没有启动
	std::thread thr_client(ClientRun);

	Server srv;
	srv.Start();
	system("pause");
	return 0;
}