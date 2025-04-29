#pragma once
#ifndef __REQUIRE_H__
#define __REQUIRE_H__

#include <QString>

class Require
{
public:
	Require(const QString& requireName, const QString& requireSource); //需求   需求来源
	~Require();

	void setName(const QString& rName);
	void setSource(const QString& rSource);

	QString getName() const;
	QString getSource() const;


private:
	QString m_name;
	QString m_source;

};

#endif // !__REQUIRE_H__