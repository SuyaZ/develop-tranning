#pragma once
#include<string>

#ifndef STUDENT_H

class Student
{
private:
	std::string name;
	int score;

public:
	Student(){}
	Student(std::string ss, int s)
		:name(ss), score(s){}

	// ��ȡѧ������
	std::string getName() const { return name; }

	// ��ȡѧ������
	int getScore() const { return score; }

};

#endif
