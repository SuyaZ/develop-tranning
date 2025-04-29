#include"KQueuenode.h"

KQueuenode::KQueuenode(const int& data)
{
    m_data = data;
    m_next = nullptr;
}

int KQueuenode::getDate()const
{
    return m_data;
}

KQueuenode* KQueuenode::next()const
{
    return m_next;
}

void KQueuenode::setNextAddr(KQueuenode* temp)//this->next = temp;
{
    m_next = temp;
}
