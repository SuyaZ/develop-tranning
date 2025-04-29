
#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include"linklistnode.h"

class linklist
{
private:
    linklistnode* m_head;
    linklistnode* m_tail;
    int m_size;

public:
    linklist();

    int getSize() const;
    linklistnode* getHead() const;
    linklistnode* getTail() const;

    int insert(int index, int data);
    int remove(int index);
    int get(int index);
    int Update(int index, int data);

};

#endif