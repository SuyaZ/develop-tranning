#pragma once
#include<iostream>
#include<vector>
#include"test0103Task.h"
#include<algorithm>
#include<string>

#ifndef SCHEULER_H

class Scheduler
{
private:
	std::vector<Task> m_tasks;//存储任务信息

public:
	void sortTask()
	{
		std::sort(m_tasks.begin(), m_tasks.end(), TaskComparetor());
	}

	//printTasks 函数被声明和定义为一个常量成员函数。这意味着：
	//可以在 const 类型的对象上调用 printTasks。
	//printTasks 不能修改 Scheduler 类的任何成员变量。
	void printTasks() const
	{
		for (auto it : m_tasks)
		{
			std::cout << "TaskName: " << it.getName() << ",   TaskDuration: " << it.getDuration() << ",   TaskPriority: " << it.getPriority() << std::endl;
		}
	}

	void addTask(const Task& task)//每一次添加都会自动排序
	{
		m_tasks.push_back(task);
		sortTask();
	}

	std::vector<Task>& getTasks()
	{
		return m_tasks;
	}


};










#endif