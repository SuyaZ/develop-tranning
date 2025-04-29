#include"ThreadAffinity.h"
#include<QtWidgets/QApplication>
#include<QCoreApplication>
#include<QWidget>

int main(int argc, char* argv[])
{
	QCoreApplication app(argc, argv);

	SenderObject so;
	QThread thread1;
	so.moveToThread(&thread1);  //发送对象移动到子线程1当中

	receiverObject ro;
	QThread thread2;
	ro.moveToThread(&thread2);

	//链接信号和槽
	QObject::connect(&so, &SenderObject::sendMessage, &ro, &receiverObject::recieveMessage);

	//启动子线程
	thread1.start();
	thread2.start();

	//发送信号
	so.send();

	//主线程等待子线程1、2结束
	thread1.quit();
	thread2.quit();
	thread1.wait();
	thread2.wait();


	app.exec();

	return 0;
}