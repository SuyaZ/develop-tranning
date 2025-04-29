#pragma once

#ifndef __KXSTUDENT_H__
#define __KXSTUDENT_H__

#include <QString>


class KxStudent
{
public:
    KxStudent(const QString& name, qint32 age, qint32 score);
    ~KxStudent();

    void setName(const QString& name);
    void setAge(const qint32 age);
    void setScore(const qint32 score);

    QString getName() const;
    qint32 getAge() const;
    qint32 getScore() const;


private:
    QString m_name;
    qint32 m_age;
    qint32 m_score;


};

#endif // !__KXSTUDENT_H__