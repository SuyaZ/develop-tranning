#ifndef __K_STUDENT_H_
#define __K_STUDENT_H_

#include <QString>
class KStudent
{

public:
	KStudent(const QString& name, int age, const QString& gender, int score);
	~KStudent();

	void setName(const QString& name);
	void setAge(const int age);
	void setScore(const int score);
	void setGender(const QString& gender);

	QString getName() const;
	int getAge() const;
	int getScore() const;

	QString getGender() const;


private:
	QString m_name;
	QString m_gender;
	int m_age;

	int m_score;
};

#endif
