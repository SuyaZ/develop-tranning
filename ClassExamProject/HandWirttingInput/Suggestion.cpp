#include "Suggestion.h"

void Suggestion::setErrorcode(int code)
{
	m_errorcode = code;
}

void Suggestion::setExt(QString ext)
{
	m_ext = ext;
}

void Suggestion::setQuery(QString que)
{
	m_query = que;
}

void Suggestion::setSugresult(QVector<SugResult> sugr)
{
	m_result = sugr;
}


void Suggestion::setSrc(QString src)
{
	m_src = src;
}

void Suggestion::setSsid(QString ssid)
{
	m_ssid = ssid;
}

void Suggestion::setVersion(QString ver)
{
	m_version = ver;
}


//__________________________________
int Suggestion::getErrorcode()
{
	return m_errorcode;
}

QString Suggestion::getExt()
{
	return m_ext;
}

QString Suggestion::getQuery()
{
	return m_query;
}


QVector<SugResult> Suggestion::getSugresult()
{
	return m_result;
}


QString Suggestion::getSrc()
{
	return m_src;
}

QString Suggestion::getSsid()
{
	return m_ssid;
}

QString Suggestion::getVersion()
{
	return m_version;
}

void Suggestion::operator = (const Suggestion& other)
{
	if (this != &other)
	{ // 自我赋值检查
		m_errorcode = other.m_errorcode;
		m_ext = other.m_ext;
		m_query = other.m_query;

		m_result.clear();
		m_result = other.m_result;

		m_src = other.m_src;
		m_ssid = other.m_ssid;
		m_version = other.m_version;

	}
}


void Suggestion::toNULL()
{
	m_errorcode = 0;
	m_ext = "";
	m_query = "";

	m_result.clear();

	m_src = "";
	m_ssid = "";
	m_version = "";
}
 