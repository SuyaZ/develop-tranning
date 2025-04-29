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

	// 获取学生姓名
	std::string getName() const { return name; }

	// 获取学生分数
	int getScore() const { return score; }

};

#endif
