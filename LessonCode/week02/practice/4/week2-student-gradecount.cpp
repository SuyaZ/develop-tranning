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

    // 使用 std::for_each 算法和一个自定义的打印函数，输出每个学生的姓名和分数。
    std::for_each(v.begin(), v.end(), [](const Student& s) 
    {
        std::cout << "Student Name: " << s.getName() << ", Score: " << s.getScore() << std::endl;
    });
    std::cout << std::endl;

    // 使用 std::accumulate 算法计算所有学生的总分，并输出结果。
    int totalScore = std::accumulate(v.begin(), v.end(), 0, [](int sum, const Student& s) 
    {
         return sum + s.getScore();
    });
    std::cout << "Total Score: " << totalScore << std::endl;
    std::cout << std::endl;

    // 使用 std::count_if 算法统计分数大于等于60分的学生人数，并输出结果。
    int passingCount = std::count_if(v.begin(), v.end(), [](const Student& s) 
    {
        return s.getScore() >= 60;
    });
    std::cout << "Passing Count: " << passingCount << std::endl;
    std::cout << std::endl;

    // 使用 std::max_element 算法找到分数最高的学生，并输出该学生的姓名和分数。
    auto highestScoringStudent = std::max_element(v.begin(), v.end(), [](const Student& a, const Student& b) 
    {
        return a.getScore() < b.getScore();
    });
    std::cout << "Highest Scoring Student: " << highestScoringStudent->getName() << ", Score: " << highestScoringStudent->getScore() << std::endl;
    std::cout << std::endl;

    // 使用 std::sort 算法对学生按照分数进行降序排序，并输出排序后的学生信息（姓名和分数）。
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