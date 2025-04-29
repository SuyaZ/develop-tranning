#include"KQueue.h"
#include"KQueuenode.h"

KQueue::KQueue()
{
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

KQueue::~KQueue()
{
    clear();
}

void KQueue::clear()
{
    KQueuenode* p = m_head;
    KQueuenode* q = nullptr;

    while(p != nullptr)
    {
        q = p;
        if(p != nullptr) p = p->next();
        delete q;
    }
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

int KQueue::getSize()const
{
    return m_size;
}

int KQueue::isEmptyQueue()const
{
    if(m_size == 0) return 1;
    else return 0;
}

KQueuenode* KQueue::getHead()const
{
    return m_head;
}

KQueuenode* KQueue::getTail()const
{
    return m_tail;
}

void KQueue::enterDataQueue(const int& data)
{
    KQueuenode* newNode = new KQueuenode(data);
    if(m_size == 0)
    {
        m_head = newNode;
        m_tail = newNode;
    }
    else
    {
        m_tail->setNextAddr(newNode);
        //m_tail->m_next = newNode; m_next is private
        
        m_tail = newNode;
    }
    m_size++;
}

int KQueue::deleteDataQueue()
{
    if(m_size == 0) return -1;
    else
    {
        KQueuenode* p = m_head;
        m_head = m_head->next();
        int tmp = p->getDate();
        delete p;
        m_size--;
        return tmp;
    }
}