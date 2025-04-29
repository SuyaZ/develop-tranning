#include<iostream>
#include"test0103Schedual.h"
#include"test0103Task.h"

int main()
{
	Scheduler scheduler;

	scheduler.addTask(Task("Task A", 99, 4));//ÿ�ε���add�����Զ��ź���
	scheduler.addTask(Task("Task B", 10, 2));//���ȼ���Խ�����ȼ�Խ��
	scheduler.addTask(Task("Task C", 36, 1));
	scheduler.addTask(Task("Task D", 70, 3));
	scheduler.addTask(Task("Task E", 20, 4));
	scheduler.addTask(Task("Task F", 13, 5));

	scheduler.printTasks();


	//ʹ��lambda���ʽ������ȼ����ڸ���ֵ����������
	int minPriority = 3;

	std::cout << "\n������ȼ����� " << minPriority << " ��������Ϣ��" << std::endl;

	//ʹ��forѭ����lambda���ʽɸѡ����ӡ����
	auto printTaskHigherPriority = [minPriority](const Task& task)
	{
		if (task.getPriority() > minPriority) 
		{
			std::cout << "TaskName: " << task.getName() << ",   TaskDuration: " << task.getDuration() << ",   TaskPriority: " << task.getPriority() << std::endl;
		}
	};

	//��������ʹ��lambda���ʽ
	for (auto it : scheduler.getTasks())
	{
		printTaskHigherPriority(it);
	}

	return 0;
}
