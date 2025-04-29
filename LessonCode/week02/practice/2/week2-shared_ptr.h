#pragma once


class Base
{

};

template<typename T>
class MySharedPtr
{
private:
	T* ptr = nullptr;
	int* count = nullptr;

public:
	MySharedPtr():ptr(nullptr), count(new int(0)){}
	MySharedPtr(T* ptr);

	MySharedPtr(const MySharedPtr<T>& sp);
	MySharedPtr<T>& operator = (const MySharedPtr<T>& sp);
	
	//ָ������ã��õ��ڴ浱�е����ݡ�
	T& operator* ();

	//���ص��ǳ�Աָ��
	T* operator->();

	//�õ����ü���
	int useCount();

	//�õ���ָ��
	T* get();

	

	~MySharedPtr();
};


