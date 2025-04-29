#pragma once
#ifndef __INTEROHONE_H__
#define __INTERPHONE_H__


#include "Iobserver.h"
#include <string>

class Interphone : public IObserver
{
private:
	std::string m_name;

public:
	explicit Interphone(std::string value)
	{
		m_name = value;
	}

	std::string getName() const override
	{
		return m_name;
	}

	void update(std::string msg) override
	{
		std::cout << m_name << "  reciever:  " <<msg<< std::endl;
	}



};

//具体观察者，对讲机

#endif