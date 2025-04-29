#ifndef __DRAGON_H__
#define __DRAGON_H__

#include "IObserver.h"
#include "ISubject.h"
#include <iostream>
#include <string>
#include <list>

class Dragon :public ISubject
{
private:
	std::string m_name;

public:
	Dragon()
	{
		std::cout << "Dragon construct" << std::endl;
	}
	~Dragon() = default;

	void Register(IObserver* pobj) override //注册观察者  小写register不可以
	{
		if (pobj == nullptr)
		{
			std::cout << "pobj is not Valid" << std::endl;
		}
		else
		{
			m_ObserverList.push_back(pobj);
		}
	}

	void unregister(IObserver* pobj) override //注销观察者 
	{
		if (pobj == nullptr)
		{
			std::cout << "pobj is not Valid" << std::endl;
		}
		else
		{
			m_ObserverList.remove(pobj);
		}
	}

	void Notify(std::string msg) override //通知观察者
	{
		//向所有观察者发布主题情况
		for (const auto& it : m_ObserverList)
		{
			it->update(msg);
		}
	}


private:
	//观察者列表
	std::list<IObserver* > m_ObserverList;

};

#endif