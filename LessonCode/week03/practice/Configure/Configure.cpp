#include"Configure.h"
#include<algorithm>

Configure::Configure()
{
    
}

int Configure::additem(std::string str)
{
    auto it = std::find(m_vec.begin(), m_vec.end(), str);
    if(it == m_vec.end()) //str not exists
    {
        m_vec.push_back(str);
        return (m_vec.size()-1); //return index
    }
    else //str exists
    {
        return std::distance(m_vec.begin(), it); 
    }
}

std::string Configure::getitem(int index)
{
    if(index >= m_vec.size() || index < 0) return "";
    else return m_vec[index];
}

int Configure::getsize()const
{
    return m_vec.size();
}



