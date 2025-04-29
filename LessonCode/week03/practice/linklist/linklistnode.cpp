#include"linklistnode.h"

linklistnode::linklistnode()
{
    m_data = 0;
    m_next = nullptr;
}

linklistnode::linklistnode(int data)
{
    m_data = data;
    m_next = nullptr;
}
    
linklistnode::linklistnode(int data, linklistnode* next)
{
    this->m_data = m_data;
    this->m_next = m_next;
}
    
int linklistnode::getData()const
{
    return m_data;
}

void linklistnode::setData(int data)
{
    m_data = data;
}
    
linklistnode* linklistnode::getNext()const
{
    return m_next;
}
    
void linklistnode::setNextAddr(linklistnode* temp)
{
    m_next = temp;
}
