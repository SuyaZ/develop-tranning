#pragma once

#include <QWidget>
#include "ui_MapEngList.h"
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

class MapEngList : public QWidget
{
	Q_OBJECT

public:
	MapEngList(QWidget *parent = nullptr);
	~MapEngList();

signals:
	void doclicked(const QString& text);  //Map()发出信号之后，会转发信号到doclicked信号，携带一个按钮文本作为参数


public slots:

	//一个信号可以与多个槽函数链接，测试一下Map信号有没有被正确发出
	void Maptest(const QString& text)
	{
		qDebug() << "map success.";
		qDebug() << text;
	}


private:

	QGridLayout* engplay = nullptr;
	QSignalMapper* signalMapper = nullptr;

	Ui::MapEngListClass ui;


};
