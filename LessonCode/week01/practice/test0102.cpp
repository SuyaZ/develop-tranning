
#include"test0102.h"
#include<iostream>

int main()
{
	int id;
	std::cout << "����һ��ֵ:\n" << "id = 1, �������\nid = 2, ���ɼ���\n";
	std::cin >> id;

	Product* p;
	ProductFactory pf;
	p = pf.CreateProduct(id);
	p->showProduct();

	return 0;
}
