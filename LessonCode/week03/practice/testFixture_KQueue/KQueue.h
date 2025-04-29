#ifndef __KQueue_H__
#define __KQueue_H__

#include"kqueuenode.h"

class KQueue
{
public:
    explicit KQueue();
    ~KQueue();

    void clear();

    int getSize()const;

    int isEmptyQueue()const;

    KQueuenode* getHead()const;
    KQueuenode* getTail()const;

    void enterDataQueue(const int& data);
    int deleteDataQueue();

private:
    KQueuenode* m_head;
    KQueuenode* m_tail;

    int m_size;

};

#endif