#pragma execution_character_set("utf-8")

#include "HandWirttingInput.h"
#include <QtWidgets/QApplication>
#include <QTextCodec>
#include <Windows.h>
#include <Qscreen>
#include <QSslSocket> 

int main(int argc, char *argv[])
{
    // 增加全局支持 Uicode 识别支持，解决中文乱码问题
    SetConsoleOutputCP(65001); // 设置控制台输出为UTF-8编码
    QTextCodec * code = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(code);

    QApplication a(argc, argv);
    HandWirttingInput w;

    
    // 获取主屏幕的几何信息
    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    // 计算窗口的位置，使其显示在屏幕中央
    int x = (screenGeometry.width() - w.width()) / 2;
    int y = (screenGeometry.height() - w.height()) / 2;
    w.move(x/2, y/2); // 移动窗口到计算出的位置

#if 0
    qDebug() << "QSslSocket=" << QSslSocket::sslLibraryBuildVersionString();
    qDebug() << "OpenSSL支持情况:" << QSslSocket::supportsSsl();
#endif

    w.show();
    return a.exec();
}
