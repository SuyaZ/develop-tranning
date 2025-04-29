# pragma execution_character_set("utf-8")

#include "HttpRequestManager.h"

HttpRequestManager::HttpRequestManager(QObject *parent)
	: QObject(parent)
{
	//信号链接信号
	(void)QObject::connect(&m_httpManager, &QNetworkAccessManager::finished, this, &HttpRequestManager::requestFinished);
	//QNetworkAccessManager::finished 信号确实带有一个参数。这个参数是一个指向 QNetworkReply 对象的指针
}

HttpRequestManager::~HttpRequestManager()
{
	
} 

//向指定的url发送http get请求
void HttpRequestManager::sendGetRequest(const QUrl& url)  //该url要在传参之前做好自定义查询
{
	QNetworkRequest request(url);
	m_httpManager.get(request);//m_httpManager是一个QNetworkAccessManager对象，负责管理网络请求和响应
	//get方法会发起一个HTTP GET请求，对应的QNetworkRequest对象包含了请求的详细信息

}
