#include<iostream>
#include"KCircle.h"

int main()
{
	KCircle c(1.9);

	std::cout << "���Ϊ��" << c.getArea() << std::endl;
	std::cout << "�ܳ�Ϊ��" << c.getLeng() << std::endl;

	return 0;
}