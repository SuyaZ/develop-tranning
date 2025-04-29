
#include<iostream>
#include<malloc.h>

struct monkey
{
	int data;
	monkey* next;
};

int main()
{
	int m = 5, n = 6;//n只猴子，报数为m

	monkey* head = (monkey*)malloc(sizeof(monkey));
	head->data = 1;
	head->next = nullptr;

	monkey* pre = head;
	monkey* q = nullptr;
	int count = 2;
	while (count <= n)
	{
		q = (monkey*)malloc(sizeof(monkey));
		pre->next = q;
		q->data = count;
		pre = q;
		count++;
	}
	if(q != nullptr) q->next = head; //q指向末尾

	count = n; //count 模拟猴子的数量
	int mod = 1;//报数模拟
	pre = q; //指向head的前一个节点
	q = head;//指向头节点 

	std::cout << "淘汰的序号依次为： " << std::endl;
	while (count > 1)
	{
		pre = q;
		q = q->next;
		mod++;
		if (mod == m)
		{
			std::cout << q->data << "  ";

			pre->next = q->next;
			delete q;
			q = pre->next;

			mod = 1;
			count--;
		}
	}

	std::cout << std::endl << "最后剩下的猴王为： " << pre->data << std::endl;

	return 0;
}