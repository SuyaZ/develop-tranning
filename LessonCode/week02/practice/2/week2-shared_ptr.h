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
	
	//指针解引用，拿到内存当中的数据。
	T& operator* ();

	//返回的是成员指针
	T* operator->();

	//拿到引用计数
	int useCount();

	//拿到裸指针
	T* get();

	

	~MySharedPtr();
};


