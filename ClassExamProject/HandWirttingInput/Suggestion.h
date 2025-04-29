#pragma once
#ifndef __SUGESTION_H__
#define __SUGESTION_H__


#include "SugResult.h"
#include <QObject>
#include <QWidget>
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
#include <QPoint>
#include <Qt>
#include <QBitmap>
#include <QString>

//联想词类，用于封装联想词的结果的类

class Suggestion
{
private:
	int m_errorcode;
	QString m_ext;
	QString m_query;

	QVector<SugResult> m_result;

	QString m_src;
	QString m_ssid;
	QString m_version;


public:
	void setErrorcode(int code);
	void setExt(QString ext);
	void setQuery(QString que);

	void setSugresult(QVector<SugResult> sugr);

	void setSrc(QString src);
	void setSsid(QString ssid);
	void setVersion(QString ver);

	//将对象恢复至无内容的状态
	void toNULL();

	 

	//__________________________________
	int getErrorcode();
	QString getExt();
	QString getQuery();

	QVector<SugResult> getSugresult();

	QString getSrc();
	QString getSsid();
	QString getVersion();

	//___________________________________
	//赋值运算符重载
	void operator = (const Suggestion& other);


};

#endif