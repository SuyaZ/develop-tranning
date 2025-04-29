#ifndef __OBJECTTREE_H__
#define __OBJECTTREE_H__

#include<QObject>
#include<QtWidgets/QApplication>
#include<QDebug>
#include<iostream>

class A : public QObject
{
public:
	A() {}
	A(QObject* p) :QObject(p) {}

	~A()
	{
		//qDebug() << (objectName().toStdString()) << " = ~A" << std::endl;
		std::cout << (objectName().toStdString()) << " = ~A" << std::endl;
	}

};


class B : public QObject
{
public:
	B(){}
	B(QObject* p):QObject(p){}

	~B()
	{
		std::cout << (objectName().toStdString()) << " = ~B" << std::endl;
	}

};



#endif