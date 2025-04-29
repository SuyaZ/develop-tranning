#pragma once
#ifndef __HERO_H__
#define __HERO_H__


#include "IObserver.h"
#include <string>

class Hero : public IObserver
{
private:
	std::string m_name;

public:
	explicit Hero(std::string value)
	{
		m_name = value;
	}

	std::string getName() const override
	{
		return m_name;
	}

	void update(std::string msg) override
	{
		std::cout << m_name << "  reciever:  " << msg << std::endl;
	}



};

#endif