
#include<iostream>
#include<malloc.h>

struct monkey
{
	int data;
	monkey* next;
};

int main()
{
	int m = 5, n = 6;//nֻ���ӣ�����Ϊm

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
	if(q != nullptr) q->next = head; //qָ��ĩβ

	count = n; //count ģ����ӵ�����
	int mod = 1;//����ģ��
	pre = q; //ָ��head��ǰһ���ڵ�
	q = head;//ָ��ͷ�ڵ� 

	std::cout << "��̭���������Ϊ�� " << std::endl;
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

	std::cout << std::endl << "���ʣ�µĺ���Ϊ�� " << pre->data << std::endl;

	return 0;
}