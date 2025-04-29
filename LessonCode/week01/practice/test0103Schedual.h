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
	std::vector<Task> m_tasks;//�洢������Ϣ

public:
	void sortTask()
	{
		std::sort(m_tasks.begin(), m_tasks.end(), TaskComparetor());
	}

	//printTasks �����������Ͷ���Ϊһ��������Ա����������ζ�ţ�
	//������ const ���͵Ķ����ϵ��� printTasks��
	//printTasks �����޸� Scheduler ����κγ�Ա������
	void printTasks() const
	{
		for (auto it : m_tasks)
		{
			std::cout << "TaskName: " << it.getName() << ",   TaskDuration: " << it.getDuration() << ",   TaskPriority: " << it.getPriority() << std::endl;
		}
	}

	void addTask(const Task& task)//ÿһ����Ӷ����Զ�����
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