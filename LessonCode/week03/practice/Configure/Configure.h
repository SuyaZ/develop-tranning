#pragma once
#include<vector>
#include<string>

#ifndef CONFIGURE_H
#define CONFIGURE_H

class Configure
{
private:
	std::vector<std::string> m_vec;

public:
    Configure();
    Configure(const std::string& str);

    int additem(std::string str);
    std::string getitem(int index);
    int getsize()const;

};

#endif