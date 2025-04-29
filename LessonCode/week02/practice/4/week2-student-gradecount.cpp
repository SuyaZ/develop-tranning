#include<iostream>
#include"week2-student-gradecount.h"
#include<vector>
#include<algorithm>
#include <numeric>

int main()
{
	std::vector<Student> v;
	v.push_back(Student("Bob", 59));
	v.push_back(Student("Marry", 96));
	v.push_back(Student("Mike", 77));
	v.push_back(Student("Harry", 98));
	v.push_back(Student("Ron", 99));
	v.push_back(Student("Herminnoe", 100));

    // ʹ�� std::for_each �㷨��һ���Զ���Ĵ�ӡ���������ÿ��ѧ���������ͷ�����
    std::for_each(v.begin(), v.end(), [](const Student& s) 
    {
        std::cout << "Student Name: " << s.getName() << ", Score: " << s.getScore() << std::endl;
    });
    std::cout << std::endl;

    // ʹ�� std::accumulate �㷨��������ѧ�����ܷ֣�����������
    int totalScore = std::accumulate(v.begin(), v.end(), 0, [](int sum, const Student& s) 
    {
         return sum + s.getScore();
    });
    std::cout << "Total Score: " << totalScore << std::endl;
    std::cout << std::endl;

    // ʹ�� std::count_if �㷨ͳ�Ʒ������ڵ���60�ֵ�ѧ������������������
    int passingCount = std::count_if(v.begin(), v.end(), [](const Student& s) 
    {
        return s.getScore() >= 60;
    });
    std::cout << "Passing Count: " << passingCount << std::endl;
    std::cout << std::endl;

    // ʹ�� std::max_element �㷨�ҵ�������ߵ�ѧ�����������ѧ���������ͷ�����
    auto highestScoringStudent = std::max_element(v.begin(), v.end(), [](const Student& a, const Student& b) 
    {
        return a.getScore() < b.getScore();
    });
    std::cout << "Highest Scoring Student: " << highestScoringStudent->getName() << ", Score: " << highestScoringStudent->getScore() << std::endl;
    std::cout << std::endl;

    // ʹ�� std::sort �㷨��ѧ�����շ������н������򣬲����������ѧ����Ϣ�������ͷ�������
    std::sort(v.begin(), v.end(), [](const Student& a, const Student& b) 
    {
        return a.getScore() > b.getScore();
    });
    std::cout << "Sorted Students:" << std::endl;

    std::for_each(v.begin(), v.end(), [](const Student& s) 
    {
        std::cout << "Student Name: " << s.getName() << ", Score: " << s.getScore() << std::endl;
    });

	return 0;
}