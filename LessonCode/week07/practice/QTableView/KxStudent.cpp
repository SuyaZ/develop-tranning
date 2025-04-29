#include "KxStudent.h"

KxStudent::KxStudent(const QString& name, qint32 age, qint32 score)
    :m_name(name)
    , m_age(age)
    , m_score(score)
{
}

KxStudent::~KxStudent()
{
}

void KxStudent::setName(const QString& name)
{
    m_name = name;
}

void KxStudent::setAge(const qint32 age)
{
    m_age = age;
}

void KxStudent::setScore(const qint32 score)
{
    m_score = score;
}

QString KxStudent::getName() const
{
    return m_name;
}

qint32 KxStudent::getAge() const
{
    return m_age;
}

qint32 KxStudent::getScore() const
{
    return m_score;
}
