#include "Kxstudent.h"


KStudent::KStudent(const QString& name, int age, const QString& gender, int score)
	:m_name(name)
	, m_age(age)
	, m_gender(gender)
	, m_score(score)
{
}

KStudent::~KStudent()
{
}

void KStudent::setName(const QString& name)
{
	m_name = name;
}

void KStudent::setAge(const int age)
{
	m_age = age;
}

void KStudent::setScore(const int score)
{
	m_score = score;
}

void KStudent::setGender(const QString& gender)
{
	m_gender = gender;
}

QString KStudent::getName() const
{
	return m_name;
}

int KStudent::getAge() const
{
	return m_age;
}

int KStudent::getScore() const
{
	return m_score;
}

QString KStudent::getGender() const
{
	return m_gender;
}
