#pragma once

#ifndef __ISSUBJECT_H__
#define ___ISSUBJECT_H__

#include "Iobserver.h"
#include <list>

//抽象主题类，用于管理观察者

class ISubject
{
public:
	virtual void Register(IObserver* pobj) = 0;  //注册观察者  小写register不可以
	virtual void unregister(IObserver* pobj) = 0;  //注销观察者 
	virtual void Notify(std::string msg) = 0;  //通知观察者

	virtual ~ISubject() = default;
};



#endif