#ifndef __SLOTANDSIGN_H__
#define __SLOTANDSIGN_H__

#include<QObject>
#include<iostream>
#include<QDebug>

class A : public QObject  //型号和槽必须继承自QOBject
{
	Q_OBJECT;

signals:   //信号的返回值只能是void类型
	void a_signal();   //信号只能声明不能被定义

public:
	void a_g() //普通的成员函数
	{
		qDebug() << "Normal Function.\n";

		//信号位于类中，发射信号的位置需要位于该类的成员函数中
		emit a_signal();
	}

};

class B : public QObject
{
	Q_OBJECT;

public slots:
	void b_slot()
	{
		qDebug() << "A send a signal to B\n";
	}

public:
	void b_g() {}

};


#endif