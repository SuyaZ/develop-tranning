#include<iostream>
#include "radio.h"
#include "phone.h"
#include "interphone.h"


int main()
{
	//创建主题类具体对象：无线点
	Radio theRadio;

	//创建观察者对象 ： 对讲机、手机
	Interphone testInterphone("Interphone user1");
	Phone testPhone("phone user2");

	//注册监听设备
	theRadio.Register(&testInterphone);
	theRadio.Register(&testPhone);

	//发布无线电
	theRadio.Notify("SOS");

	std::cout << "____________________" << std::endl;

	//卸载设备
	theRadio.unregister(&testPhone);

	theRadio.Notify("hello");


	return 0;
}