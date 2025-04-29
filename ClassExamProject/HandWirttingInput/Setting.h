#pragma once

#include <QWidget>
#include "ui_Setting.h"
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
#include <QSignalMapper>
#include <QDialog> 

class Setting : public QWidget
{
	Q_OBJECT

public:
	Setting(QWidget *parent = nullptr);
	~Setting();


signals:
	void btnblackclicked();
	void btnredclicked();
	void btnyellowclicked();
	void btnblueclicked();
	void btngreenclicked();
	void btnpurpleclicked();

	
	void btn1clicked();
	void btn2clicked();
	void btn3clicked();
	void btn4clicked();
	void btn5clicked();
	void btn6clicked();


	void btn10clicked();
	void btn15clicked();
	void btn20clicked();
	void btn25clicked();
	void btn30clicked();
	void btn35clicked();


	void reSetBtnclicked();



private:
	QGridLayout* setplay = nullptr;

	//三个提示标签
	QLabel* color = nullptr;  //墨迹颜色
	QLabel* width = nullptr;  //墨迹粗细
	QLabel* size = nullptr;   //候选字字号
	QLabel* padding = nullptr; 



	//墨迹颜色
	QPushButton* btnblack = nullptr;
	QPushButton* btnred = nullptr;
	QPushButton* btnyellow = nullptr;
	QPushButton* btnblue = nullptr;
	QPushButton* btngreen = nullptr;
	QPushButton* btnpurple = nullptr;

	//墨迹粗细  标号越大，墨迹越粗
	QPushButton* btn1 = nullptr;
	QPushButton* btn2 = nullptr;
	QPushButton* btn3 = nullptr;
	QPushButton* btn4 = nullptr;
	QPushButton* btn5 = nullptr;
	QPushButton* btn6 = nullptr;

	//候选字号  编号表示字号的大小
	QPushButton* btn10 = nullptr;
	QPushButton* btn15 = nullptr;
	QPushButton* btn20 = nullptr;
	QPushButton* btn25 = nullptr;
	QPushButton* btn30 = nullptr;
	QPushButton* btn35 = nullptr;

	//恢复默认
	QPushButton* reSetbtn = nullptr;


	Ui::SettingClass ui;

};
