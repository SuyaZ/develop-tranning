#include<iostream>
#include"week2-shared_ptr.h"

// ���캯��
template<typename T>
MySharedPtr<T>::MySharedPtr(T* ptr)
{
	//���θ�ֵ����ʹ����ָ�븳ֵ
	// ��������ָ�벻Ϊ�գ����ʼ�����ü���Ϊ1
	if (ptr != nullptr)
	{
		this->ptr = ptr;
		count = new int(1);
	}
}

//�������캯��
template<typename T>
MySharedPtr<T>::MySharedPtr(const MySharedPtr<T>& sp)
{
	ptr = sp.ptr;
	//(*count)++;
	count = sp.count;
	(*count)++;
}


template<typename T>
MySharedPtr<T>& MySharedPtr<T>::operator = (const MySharedPtr<T>& sp)
{
	ptr = sp.ptr;
	//(*count)++;
	count = sp.count;
	(*count)++;

	return *this;
}

template<typename T>
T& MySharedPtr<T>::operator* ()
{
	return (*this);
}

template<typename T>
T* MySharedPtr<T>::operator->()
{
	return this;
}

template<typename T>
int MySharedPtr<T>::useCount()
{
	return (*count);
}

template<typename T>
T* MySharedPtr<T>::get()
{
	return ptr;
}

template<typename T>
MySharedPtr<T>::~MySharedPtr()
{
	if (ptr != nullptr)
	{
		*count--;
		if (*count == 0)
		{
			delete ptr;
			delete count;
		}
		else ptr = nullptr;
	}
}


int main()
{
	MySharedPtr<int> ptr1(new int(1028));
	MySharedPtr<int> ptr2(ptr1);

	std::cout << ptr1.useCount() << std::endl;
	std::cout << ptr2.useCount() << std::endl;

	std::cout << "======================" << std::endl;

	MySharedPtr<int> ptr5(new int(1029));
	MySharedPtr<int> ptr6;

	ptr6 = ptr5;

	std::cout << ptr5.useCount() << std::endl;
	std::cout << ptr6.useCount() << std::endl;

	return 0;
}