#include<iostream>
#include"test0103Schedual.h"
#include"test0103Task.h"

int main()
{
	Scheduler scheduler;

	scheduler.addTask(Task("Task A", 99, 4));//每次调用add都会自动排好序
	scheduler.addTask(Task("Task B", 10, 2));//优先级数越大优先级越高
	scheduler.addTask(Task("Task C", 36, 1));
	scheduler.addTask(Task("Task D", 70, 3));
	scheduler.addTask(Task("Task E", 20, 4));
	scheduler.addTask(Task("Task F", 13, 5));

	scheduler.printTasks();


	//使用lambda表达式输出优先级高于给定值的所有任务
	int minPriority = 3;

	std::cout << "\n输出优先级大于 " << minPriority << " 的任务信息：" << std::endl;

	//使用for循环和lambda表达式筛选并打印任务
	auto printTaskHigherPriority = [minPriority](const Task& task)
	{
		if (task.getPriority() > minPriority) 
		{
			std::cout << "TaskName: " << task.getName() << ",   TaskDuration: " << task.getDuration() << ",   TaskPriority: " << task.getPriority() << std::endl;
		}
	};

	//遍历任务使用lambda表达式
	for (auto it : scheduler.getTasks())
	{
		printTaskHigherPriority(it);
	}

	return 0;
}
