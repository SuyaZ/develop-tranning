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

	// ���������JSON�ַ������浽�ļ�
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

	//��Ȼ�����������ʣ�����ζ���û�ֻ��Ҫ�ṩ�����ͺ���
	//���Ƚ����ַ��� �� "key1" "key2" "key3"... (int)���� "key4" ��

	//����ʵ�����û���Ҫ����ɾ�Ĳ飬Ȼ���޸ĺ�Ľ��ȫ����ӡ�������output.txt�ļ�����
	int op;//��Ӧ�Ĳ���, ��op = 0ʱ�˳�����

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
		case 1:top.QQuery();//��ѯ
			break;

		case 2:top.Update();//�޸�
			break;

		case 3:top.Delete();//ɾ��
			break;

		case 4:top.Create();//����
			break;


		default:
			break;
		}

		std::cout << std::endl << "Please Print your Option-Number here: " << std::endl;
	}



	// ���������JSON�ַ������浽�ļ�
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