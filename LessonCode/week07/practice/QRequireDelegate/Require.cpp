#include "Require.h"

Require::Require(const QString& requireName, const QString& requireSource) //需求   需求来源
	: m_name(requireName)
	, m_source(requireSource)
{

}

Require::~Require()
{

}

void Require::setName(const QString& rName)
{
	m_name = rName;
}

void Require::setSource(const QString& rSource)
{
	m_source = rSource;
}

QString Require::getName() const
{
	return m_name;
}

QString Require::getSource() const
{
	return m_source;
}