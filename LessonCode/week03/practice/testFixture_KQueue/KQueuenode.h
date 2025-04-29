#ifndef __KQUEUENODE_H__
#define __KQUEUENODE_H__

class KQueuenode
{
private:
    int m_data;
    KQueuenode* m_next;


public:
    
    explicit KQueuenode(const int& data);

    int getDate()const;

    KQueuenode* next()const;

    void setNextAddr(KQueuenode* temp);//this->next = temp;

    KQueuenode& operator=(const KQueuenode) = delete;
    KQueuenode(const KQueuenode&) = delete;


};

#endif