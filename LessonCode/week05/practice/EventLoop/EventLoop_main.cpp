#include "EventLoop.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    QWidget window;
    window.resize(600, 600);

    MyButton* button = new MyButton(&window);  //指定控件的父对象

    button->setText("Hover over me!");
    button->move(100, 175);

    window.show();

    return app.exec();
}
