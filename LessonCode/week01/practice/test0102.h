#pragma once
#include<iostream>

class Product
{
public:
	virtual void showProduct() const = 0;  //ע�ⴿ�麯������const����ô������Ҳ��Ҫ�ں���ĩβ����const
};

class ProductMouse : public Product
{
public:
	void showProduct() const;
};

class ProductKeyboard :public Product
{
public:
	void showProduct() const;
};

class ProductFactory
{
public:
	Product* CreateProduct(int id);
};



void ProductMouse::showProduct() const
{
	std::cout << "create Mouse Product" << std::endl;
}

void ProductKeyboard::showProduct() const 
{
	std::cout << "create KeyBoard Product" << std::endl;
}

Product* ProductFactory::CreateProduct(int id)
{
	if (id == 1)
	{
		return new ProductMouse();
	}
	else
		return new ProductKeyboard();
}

