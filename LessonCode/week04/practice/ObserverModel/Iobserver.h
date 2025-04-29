#ifndef __IOBSERVER_H__
#define __IOBSERVER_H__

#include<iostream>
#include<string>

//抽象的观察者类
class IObserver
{
public:
	virtual void update(std::string msg) = 0; //虚函数接口
	virtual std::string getName() const = 0;  //返回观察者对象的名称
	
	//不能自动析构观察者  后面会定义注销观察者的方法
	virtual ~IObserver() = default;

};



#endif