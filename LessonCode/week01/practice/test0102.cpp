
#include"test0102.h"
#include<iostream>

int main()
{
	int id;
	std::cout << "输入一个值:\n" << "id = 1, 生成鼠标\nid = 2, 生成键盘\n";
	std::cin >> id;

	Product* p;
	ProductFactory pf;
	p = pf.CreateProduct(id);
	p->showProduct();

	return 0;
}
