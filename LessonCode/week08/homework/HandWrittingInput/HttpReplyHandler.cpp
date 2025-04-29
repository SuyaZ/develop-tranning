# pragma execution_character_set("utf-8")

#include "HttpReplyHandler.h"

HttpReplyHandler::HttpReplyHandler(QObject *parent)
	: QObject(parent)
{
	
}

HttpReplyHandler::~HttpReplyHandler()
{
	
}

//**************************************************尚未完善，只是打了一个框架出来
//将响应的的结果转换成json数据
//reply指向网络应答的结果
void HttpReplyHandler::onHandleHttpReply(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray responssBytes = reply->readAll();
        QString response = QString::fromUtf8(responssBytes);

        //由于网站是JSonp模式的响应，所以reply返回的响应结果转成字符串不是严格类型的json格式
        //需要去掉开头的 [0,13] 个字符，和结尾的后2个字符
        QString newresponse = response.mid(14, -1); //从下标14开始的所有字符  -1表示到结尾
        newresponse.chop(2);  //去掉最后两个字符

        qDebug() << "newresponse: " << newresponse;

        //处理之后，newresponse就是标准的json格式的字符串
        m_jsonDoc = QJsonDocument::fromJson(newresponse.toUtf8());

        if (!m_jsonDoc.isObject()) //顶层类不是数组
        {
            qWarning() << "Invalid m_jsonDoc";
            return;
        }

        PaserComment(); //对jsonDoc解析，将结果保存在Suggestions当中


    }
    else
    {
        qDebug() << "reply -> error() == true";
    }


}
 

//将m_jsonDoc转换为类Comment的实例 的方法
void HttpReplyHandler::PaserComment()
{
    //联想词的解析逻辑
    QJsonObject jsonObject = m_jsonDoc.object();

    m_suggestions.setErrorcode(jsonObject["errorcode"].toInt());
    m_suggestions.setExt(jsonObject["ext"].toString());
    m_suggestions.setQuery(jsonObject["query"].toString());

    QVector<SugResult> tmp;

    //处理result数组
    QJsonArray resultArr = jsonObject["result"].toArray();
    for (const QJsonValue& resValue : resultArr)
    {
        if (!resValue.isObject())
        {
            qWarning() << "Invalid resValue Data.";
            continue;
        }

        QJsonObject ArrObj = resValue.toObject();
        SugResult res;
        res.m_word = ArrObj["word"].toString();
        
        tmp.push_back(res);
    }
    m_suggestions.setSugresult(tmp);

    qDebug() << "tmp.size(): " << tmp.size();

    m_suggestions.setSrc(jsonObject["src"].toString());
    m_suggestions.setSsid(jsonObject["ssid"].toString());
    m_suggestions.setVersion(jsonObject["version"].toString());

    emit suggestionsReady(m_suggestions);  //发出准备信号

}
