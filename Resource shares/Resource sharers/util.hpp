#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<boost/filesystem.hpp>
#ifdef _WIN32
#include<stdlib.h>
#include<ws2tcpip.h>
//获取网卡信息的头文件
#include<Iphlpapi.h>
//获取网卡信息接口的库文件包含
#pragma comment(lib, "Iphlpapi.lib")
//windows下的socket库
#pragma comment(lib, "ws2_32.lib")
#else
//Linux头文件
#endif

class StringUtil
{
public:
	static int64_t Str2Dig(const std::string &num)
	{
		std::stringstream tmp;
		tmp << num;
		int64_t res;
		tmp >> res;
		return res;
	}
};

class FileUtil
{
public:
	static int64_t GetFileSize(const std::string &name)
	{
		return boost::filesystem::file_size(name);
	}
	static bool Write(const std::string &name, const std::string &body, int64_t offset)
	{
		std::ofstream ofs(name, std::ios::binary);
		if (ofs.is_open() == false)
		{
			std::cerr << "打开文件失败\n";
			return false;
		}
		//相对于文件起始位置偏移offset的偏移量
		ofs.seekp(offset, std::ios::beg);
		ofs.write(&body[0], body.size());

		if (ofs.good() == false)
		{
			std::cerr << "向文件写入数据失败\n";
			return false;
		}
		return true;
	}
	//指针参数表示这是一个输出型参数
	//const & 表示是一个输入型参数
	//& 输入输出型参数
	static bool Read(const std::string &name, std::string *body)
	{
		std::ifstream ifs(name, std::ios::binary);
		if (ifs.is_open() == false)
		{
			std::cerr << "打开文件失败\n";
			return false;
		}
		int64_t filesize = boost::filesystem::file_size(name);
		body->resize(filesize);
		//std::cout << "要读取的文件大小：" << name << ":" << filesize << std::endl;
		ifs.read(&(*body)[0], filesize);
		ifs.close();
		return true;
	}
	static bool ReadRange(const std::string &name, std::string *body, int64_t len, int64_t offset)
	{
		body->resize(len);
		FILE *fp = nullptr;
		fopen_s(&fp, name.c_str(), "rb+");
		if (fp == nullptr)
		{
			std::cerr << "打开文件失败\n";
			return false;
		}
		fseek(fp, offset, SEEK_SET);
		int ret = fread(&(*body)[0], 1, len, fp);
		if (ret != len)
		{
			std::cerr << "从文件读取数据失败\n";
			fclose(fp);
			return false;
		}
		fclose(fp);
		return true;
	}
	//获取分块下载
	static bool GetRange(const std::string& range_str, int* start, int* end)
	{
		size_t  pos1 = range_str.find('-');
		size_t pos2 = range_str.find('=');
		*start = std::atol(range_str.substr(pos2 + 1, pos1 - pos2 - 1).c_str());
		std::cout << "range_str.substr(pos1 + 1, pos1 - pos2 - 1):" << range_str.substr(pos1 + 1, pos1 - pos2 - 1) << std::endl;
		*end = std::atol(range_str.substr(pos1 + 1).c_str());
		std::cout << "range_str.substr(pos1 + 1):" << range_str.substr(pos1 + 1) << std::endl;
		return true;
	}
};

class Adapter
{
public:
	uint32_t _ip_addr;//网卡上的ip地址
	uint32_t _mask_addr;//网卡上的子网掩码
};

class AdapterUtil
{
#ifdef _WIN32
public:
	//Windows下的获取网卡信息实现
	static bool GetAllAdapter(std::vector<Adapter> *list) 
	{
		//开辟一块网卡信息结构的空间
		PIP_ADAPTER_INFO p_adapters = new IP_ADAPTER_INFO();
		//GetAdapterInfo windows下获取网卡信息的接口--网卡信息有可能有多个，因此传入一个指针
		//获取网卡信息有可能会失败，因为空间不足，因此有一个输出型参数，用于向用户返回所有网卡信息占用大小
		uint64_t all_adpter_size = sizeof(IP_ADAPTER_INFO);
		//all_adpter_size用于获取实际所有网卡信息所占空间大小
		int ret = GetAdaptersInfo(p_adapters, (PULONG)&all_adpter_size);
		if (ret == ERROR_BUFFER_OVERFLOW)//这个错误表示缓冲区空间不足
		{
			delete p_adapters;
			p_adapters = (PIP_ADAPTER_INFO)new BYTE[all_adpter_size];
			//重新获取网卡信息
			GetAdaptersInfo(p_adapters, (PULONG)&all_adpter_size);
		}
		while (p_adapters)
		{
			Adapter adapter;
			inet_pton(AF_INET,p_adapters->IpAddressList.IpAddress.String,&adapter._ip_addr);
			inet_pton(AF_INET,p_adapters->IpAddressList.IpMask.String,&adapter._mask_addr);
			//因为有些网卡并没有启用，导致IP地址为0
			if (adapter._ip_addr != 0) {
				//添加网卡信息添加到vector中返回给用户
				list->push_back(adapter);
				//std::cout << "网卡名称：" << p_adapters->AdapterName << std::endl;
				//std::cout << "网卡描述：" << p_adapters->Description << std::endl;
				//std::cout << "ip地址：" << p_adapters->IpAddressList.IpAddress.String << std::endl;
				//std::cout << "子网掩码：" << p_adapters->IpAddressList.IpMask.String << std::endl;
				//std::cout << std::endl;
			}
			p_adapters = p_adapters->Next;
		}
		delete p_adapters;
		return true;
	}
#else
	//Linux下的获取网卡信息实现
	bool GetAllAdapter(std::vector<Adapter> *list);
#endif
};