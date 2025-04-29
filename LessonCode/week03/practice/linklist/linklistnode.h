#ifndef __LINKLISTNODE_H__
#define __LINKLISTNODE_H__

class linklistnode
{
private:
    int m_data;
    linklistnode* m_next;

public:
    linklistnode();
    linklistnode(int data);
    linklistnode(int data, linklistnode* next);
    
    int getData()const;
    void setData(int data);
    
    linklistnode* getNext()const;
    
    void setNextAddr(linklistnode* temp);


};

#endif