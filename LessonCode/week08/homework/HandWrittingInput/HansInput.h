#pragma once

#ifndef __HANDSINPUT_H__
#define __HANDSINPUT_H__
 
#include <windows.h>
#include <QWidget>
#include "ui_HansInput.h"
#include <QtWidgets/QMainWindow>
#include <QLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QWidget>
#include <QDebug>
#include <QTextEdit>
#include <QLabel>
#include <QEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <msinkaut.h>
#include <msinkaut_i.c>
#include <windows.h>
#include <comdef.h>
#include <WinUser.h>
#include <vector>


struct InputRes
{
	char res[128]; //用于保存每一次识别的结果
};

typedef std::vector<InputRes> InPutResS; //保存候选项

class HansInput : public QWidget
{
	Q_OBJECT

public:
	explicit HansInput(QWidget *parent = nullptr);  
	~HansInput();

	//定义接口指针 p_前缀表示指针 构造函数时去初始化
	IInkCollector* p_IInkCollector = nullptr; //墨迹收集和管理
	IInkDisp* p_IInkDisp = nullptr;  //墨迹显示
	IInkRecognizerContext* p_IInkRecognizerContext = nullptr;  //墨迹识别

	void inputInit(HWND hwnd);  //初始化接口等，需要传入一个ui组件的指针，来指定墨水收集和识别的区域
	void RecogData(InPutResS& Res); //墨迹识别
	void releaseUp();  //释放与墨迹输入相关的接口资源，清理COM
	void clear(); //清除所有笔划

	void clearNew(); //清除最新的一笔，回退一笔


signals:
	//发出信号，表示已经正确删除笔划集合并且更新了UI界面，希望main窗口能够再次调用一次识别函数，将结果反馈给用户
	void deleteLast();



private:
	Ui::HansInputClass ui;
};


#endif