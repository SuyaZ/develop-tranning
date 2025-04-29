#include"linklist.h"
#include"linklistnode.h"

linklist::linklist()
{
    m_head = new linklistnode(0);
    m_tail = m_head;
    m_size = 0;
}

int linklist::getSize() const
{
    return m_size;
}

linklistnode* linklist::getHead() const
{
    return m_head;
}

linklistnode* linklist::getTail() const
{
    return m_tail;
}

int linklist::insert(int index, int data)
{
    if (index > m_size + 1 || index < 1)
    {
        return -1;
    }
    int j = 0;
    linklistnode* p = m_head;
    while (j < index - 1)
    {
        p = p->getNext();
        j++;
    }
    linklistnode* s = new linklistnode(data);
    linklistnode* temp = p->getNext();
    p->setNextAddr(s);
    s->setNextAddr(temp);
    if(temp == nullptr) m_tail = s;
    m_size++;

    return index;
}

int linklist::remove(int index)
{
    if(index > m_size || index < 1) return -999;
    int j=0;
    linklistnode* p = m_head;
    while(j < index-1)
    {
        p = p->getNext();
        j++;
    }
    linklistnode* s = p->getNext();
    p->setNextAddr(s->getNext());
    int tmp = s->getData();
    delete s;
    m_size--;

    if(index == m_size) m_tail = p;

    return tmp;
}

int linklist::get(int index)
{
    if(index > m_size || index < 1) return -999;
    int j=0;
    linklistnode* p = m_head;
    while(j < index-1)
    {
        p = p->getNext();
        j++;
    }
    linklistnode* s = p->getNext();
    return s->getData();
}

int linklist::Update(int index, int data)
{
    if(index > m_size || index < 1) return -999;
    int j=0;
    linklistnode* p = m_head;
    while(j < index-1)
    {
        p = p->getNext();
        j++;
    }
    linklistnode* s = p->getNext();
    s->setData(data);
    return s->getData();
}