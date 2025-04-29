#include<iostream>
#include<sstream>
#include<fstream>
#include"KJson.h"

using namespace kjsonh::json;

int main()
{
	//std::ifstream fin("./input.json");
	std::ifstream fin("./input.txt");
	std::stringstream ss;
	ss << fin.rdbuf();
	const std::string& str = ss.str();

	KJson top;
	top.parse(str);

	// 将解析后的JSON字符串保存到文件
	std::ofstream fout("./output.txt");
	if (fout.is_open())
	{
		fout << top.str2();
		fout.close();
		std::cout << "File 'output.txt' has been written successfully.\n" << std::endl;
	}
	else
	{
		std::cerr << "Unable to open file 'output.txt' for writing.\n" << std::endl;
	}

	//既然可以这样访问，就意味着用户只需要提供参数就好了
	//首先解析字符串 “ "key1" "key2" "key3"... (int)数字 "key4" ”

	//首先实现有用户需要的增删改查，然后将修改后的结果全部打印并输出到output.txt文件当中
	int op;//对应的操作, 当op = 0时退出操作

	std::cout << "Now You can work on the file." << std::endl;

	std::cout << "Options:" << std::endl
		<< "Enter the number \"1\" : to Query the content of a certain key;" << std::endl
		<< "Enter the number \"2\" : to Update a key-value pair" << std::endl
		<< "Enter the number \"3\" : to Delete a key-value pair" << std::endl
		<< "Enter the number \"4\" : to add a key-value pair;" << std::endl
		<< "Enter the number \"0\" : to exit the operation, we will print the content into the file \"output.txt\"." << std::endl;

	std::cout << std::endl << "Please Print your Option-Number here: " << std::endl;


	while (std::cin >> op && op != 0)
	{
		switch (op)
		{
		case 1:top.QQuery();//查询
			break;

		case 2:top.Update();//修改
			break;

		case 3:top.Delete();//删除
			break;

		case 4:top.Create();//增加
			break;


		default:
			break;
		}

		std::cout << std::endl << "Please Print your Option-Number here: " << std::endl;
	}



	// 将解析后的JSON字符串保存到文件
	std::ofstream fout2("./UpdateOutput.txt");
	if (fout2.is_open())
	{
		fout2 << top.str2();
		fout2.close();
		std::cout << "File 'UpdateOutput.txt' has been written successfully." << std::endl;
	}
	else
	{
		std::cerr << "Unable to open file 'UpdateOutput.txt' for writing." << std::endl;
	}

	return 0;
}