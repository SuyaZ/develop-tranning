#include<iostream>
#include<string>
#include"wee2-FILE-RALL.h"

int main()
{
	std::string filepath = "./file.txt";

	File_ptr fptr(filepath);

	return 0;
}