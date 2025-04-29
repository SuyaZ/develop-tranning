#include"ObjectTree.h"
#include<iostream>
#include<QWidget>
#include<QtWidgets/QApplication>


int main(int argc, char* argv[])
{
	A ma;  //父对象通常创建在栈区
	A* pa1 = new A(&ma);  //子对象在堆区，并且在初始化的同时指定父对象
	A* pa2 = new A(&ma);

	B* pb1 = new B(pa1);
	B* pb2 = new B(pa1);

	A* pa3 = new A(pb2);
	B* pb3 = new B(pb2);

	//为各个对象设置名称
	ma.setObjectName("ma");
	pa1->setObjectName("pa1"); pa2->setObjectName("pa2");
	pb1->setObjectName("pb1"); pb2->setObjectName("pb2");
	pa3->setObjectName("pa3"); pb3->setObjectName("pb3");

	A ma1; B mb1;  //在栈上为堆指定对象
	mb1.setParent(&ma1);
	mb1.setObjectName("mb1");
	ma1.setObjectName("ma1");


	delete pa1;

	return 0;
}


/*
* 输出结果：
pa1 = ~A
pb1 = ~B
pb2 = ~B
pa3 = ~A
pb3 = ~B
mb1 = ~B
ma1 = ~A
ma = ~A
pa2 = ~A
*/