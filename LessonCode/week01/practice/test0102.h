#pragma once
#include<iostream>

class Product
{
public:
	virtual void showProduct() const = 0;  //注意纯虚函数加上const，那么派生类也需要在函数末尾加上const
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

