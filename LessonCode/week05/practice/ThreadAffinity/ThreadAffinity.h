#ifndef __THREADAFFINITY_H__
#define __THREADAFFINITY_H__

#include<QtWidgets>
#include<Qwidget>
#include<QEvent>
#include<QObject>
#include<QCoreApplication>
#include<Qthread>
#include<QDebug>

class SenderObject : public QObject
{
	Q_OBJECT;

public:
	SenderObject(){}

signals:
	void sendMessage(const QString& message);

public slots:
	void send()
	{
		emit sendMessage("Hello from SendObject.");
	}


};



class receiverObject : public QObject
{
	Q_OBJECT;

public:
	receiverObject(){}

public slots:
	void recieveMessage(const QString& qstr)
	{
		qDebug() << "Reiceved Message int the receiverObject : " << qstr;
	}

};










#endif