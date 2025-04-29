#pragma once

#include<iostream>
#include<cstdio>

class File_ptr
{
private:
	FILE* fileptr;

public:
	File_ptr() 
		:fileptr(nullptr)
	{
		std::cout << "���� File_ptr " << std::endl;
	}

	File_ptr(std::string& path)
	{
		//fopen_s ���Ӱ�ȫ
		errno_t err = fopen_s(&fileptr, path.c_str(), "r");

		if(err != 0)
			std::cout << "�޷����ļ�" << path << std::endl;
		else
			std::cout << "�ɹ����ļ�" << path << std::endl;
	
	}

	~File_ptr()
	{
		std::cout << "�ļ��ѹر�" << std::endl;

		if (fileptr == nullptr)
			fclose(fileptr);
		else
		{
			fclose(fileptr);
			fileptr = nullptr;
		}
	}

};