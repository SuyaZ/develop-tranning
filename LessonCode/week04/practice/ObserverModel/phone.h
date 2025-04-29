#pragma once

#ifndef __PHONE_H__
#define __PHONE_H__

#include "IObserver.h"
#include <iostream>
#include <string>


class Phone : public IObserver
{
private:
	std::string m_name;

public:
	explicit Phone(std::string value)
	{
		m_name = value;
	}

	std::string getName() const override
	{
		return m_name;
	}

	void update(std::string msg) override
	{
		std::cout << m_name << "  receiver : " << msg << std::endl;
	}

};

#endif