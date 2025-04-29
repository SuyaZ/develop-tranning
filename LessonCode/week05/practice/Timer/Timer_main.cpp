#include"Timer.h"
#include<QtWidgets/QApplication>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	QWidget window;

	QTime t = QTime::currentTime();

	myTimer* mt = new myTimer(t, &window);
	mt->move(55, 44);
	mt->setDisplayFormat("hh/mm/ss"); //设置时间格式  //QTimeEdit 类提供了一个方法 setDisplayFormat(const QString &format)，允许你设置时间显示的格式。

	window.resize(300, 200);
	window.show();
	app.exec();

	return 0;
}