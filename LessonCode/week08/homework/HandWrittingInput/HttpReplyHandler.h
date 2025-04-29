#pragma once
#ifndef __HW_HTTPREPLYHANDLER_H__
#define __HW_HTTPREPLYHANDLER_H__

#include <QObject>
#include <QVector>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>  
#include <QJsonArray>  
#include <QDebug>  
#include <QtGlobal>
#include "Suggestion.h"


class HttpReplyHandler  : public QObject
{
	Q_OBJECT

signals:
    void suggestionsReady(Suggestion);

public:
    HttpReplyHandler(QObject* parent = nullptr);
    ~HttpReplyHandler();

    void onHandleHttpReply(QNetworkReply* reply);

    //QVector<Suggestion> getComments() const;

private:
    QJsonDocument m_jsonDoc;
    //QVector<Suggestion> m_suggestions;
    Suggestion m_suggestions;

    //将m_jsonDoc转换为类Comment的实例 的方法
    void PaserComment();


};


#endif
