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
		std::cout << "构造 File_ptr " << std::endl;
	}

	File_ptr(std::string& path)
	{
		//fopen_s 更加安全
		errno_t err = fopen_s(&fileptr, path.c_str(), "r");

		if(err != 0)
			std::cout << "无法打开文件" << path << std::endl;
		else
			std::cout << "成功打开文件" << path << std::endl;
	
	}

	~File_ptr()
	{
		std::cout << "文件已关闭" << std::endl;

		if (fileptr == nullptr)
			fclose(fileptr);
		else
		{
			fclose(fileptr);
			fileptr = nullptr;
		}
	}

};