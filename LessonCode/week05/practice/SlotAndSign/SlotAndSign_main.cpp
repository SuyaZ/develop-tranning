#include"SlotAndSign.h"
#include<QtWidgets/QApplication>
#include<QWidget>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv); // 创建QApplication对象

	A ma;
	B mb;

	QObject::connect(&ma, &A::a_signal, &mb, &B::b_slot); 

	ma.a_g();  //调用函数，发送信号，验证是否能通信

	app.exec(); // 进入事件循环

	return 0;
}