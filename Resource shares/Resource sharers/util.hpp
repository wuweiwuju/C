#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<boost/filesystem.hpp>
#ifdef _WIN32
#include<stdlib.h>
#include<ws2tcpip.h>
//��ȡ������Ϣ��ͷ�ļ�
#include<Iphlpapi.h>
//��ȡ������Ϣ�ӿڵĿ��ļ�����
#pragma comment(lib, "Iphlpapi.lib")
//windows�µ�socket��
#pragma comment(lib, "ws2_32.lib")
#else
//Linuxͷ�ļ�
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
			std::cerr << "���ļ�ʧ��\n";
			return false;
		}
		//������ļ���ʼλ��ƫ��offset��ƫ����
		ofs.seekp(offset, std::ios::beg);
		ofs.write(&body[0], body.size());

		if (ofs.good() == false)
		{
			std::cerr << "���ļ�д������ʧ��\n";
			return false;
		}
		return true;
	}
	//ָ�������ʾ����һ������Ͳ���
	//const & ��ʾ��һ�������Ͳ���
	//& ��������Ͳ���
	static bool Read(const std::string &name, std::string *body)
	{
		std::ifstream ifs(name, std::ios::binary);
		if (ifs.is_open() == false)
		{
			std::cerr << "���ļ�ʧ��\n";
			return false;
		}
		int64_t filesize = boost::filesystem::file_size(name);
		body->resize(filesize);
		//std::cout << "Ҫ��ȡ���ļ���С��" << name << ":" << filesize << std::endl;
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
			std::cerr << "���ļ�ʧ��\n";
			return false;
		}
		fseek(fp, offset, SEEK_SET);
		int ret = fread(&(*body)[0], 1, len, fp);
		if (ret != len)
		{
			std::cerr << "���ļ���ȡ����ʧ��\n";
			fclose(fp);
			return false;
		}
		fclose(fp);
		return true;
	}
	//��ȡ�ֿ�����
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
	uint32_t _ip_addr;//�����ϵ�ip��ַ
	uint32_t _mask_addr;//�����ϵ���������
};

class AdapterUtil
{
#ifdef _WIN32
public:
	//Windows�µĻ�ȡ������Ϣʵ��
	static bool GetAllAdapter(std::vector<Adapter> *list) 
	{
		//����һ��������Ϣ�ṹ�Ŀռ�
		PIP_ADAPTER_INFO p_adapters = new IP_ADAPTER_INFO();
		//GetAdapterInfo windows�»�ȡ������Ϣ�Ľӿ�--������Ϣ�п����ж������˴���һ��ָ��
		//��ȡ������Ϣ�п��ܻ�ʧ�ܣ���Ϊ�ռ䲻�㣬�����һ������Ͳ������������û���������������Ϣռ�ô�С
		uint64_t all_adpter_size = sizeof(IP_ADAPTER_INFO);
		//all_adpter_size���ڻ�ȡʵ������������Ϣ��ռ�ռ��С
		int ret = GetAdaptersInfo(p_adapters, (PULONG)&all_adpter_size);
		if (ret == ERROR_BUFFER_OVERFLOW)//��������ʾ�������ռ䲻��
		{
			delete p_adapters;
			p_adapters = (PIP_ADAPTER_INFO)new BYTE[all_adpter_size];
			//���»�ȡ������Ϣ
			GetAdaptersInfo(p_adapters, (PULONG)&all_adpter_size);
		}
		while (p_adapters)
		{
			Adapter adapter;
			inet_pton(AF_INET,p_adapters->IpAddressList.IpAddress.String,&adapter._ip_addr);
			inet_pton(AF_INET,p_adapters->IpAddressList.IpMask.String,&adapter._mask_addr);
			//��Ϊ��Щ������û�����ã�����IP��ַΪ0
			if (adapter._ip_addr != 0) {
				//���������Ϣ��ӵ�vector�з��ظ��û�
				list->push_back(adapter);
				//std::cout << "�������ƣ�" << p_adapters->AdapterName << std::endl;
				//std::cout << "����������" << p_adapters->Description << std::endl;
				//std::cout << "ip��ַ��" << p_adapters->IpAddressList.IpAddress.String << std::endl;
				//std::cout << "�������룺" << p_adapters->IpAddressList.IpMask.String << std::endl;
				//std::cout << std::endl;
			}
			p_adapters = p_adapters->Next;
		}
		delete p_adapters;
		return true;
	}
#else
	//Linux�µĻ�ȡ������Ϣʵ��
	bool GetAllAdapter(std::vector<Adapter> *list);
#endif
};