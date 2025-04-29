#pragma once
#include<string>

#ifndef Task_H

class Task
{
private:

	std::string m_name;//任务名称
	int m_duration; //执行时间
	int m_priority; //任务优先级

public:
	//仅仅只是获取值而不希望对值进行修改 函数使用 const
	std::string getName() const { return m_name; };
	int getDuration() const { return m_duration; };
	int getPriority() const { return m_priority; };

	void setName(std::string name) { this->m_name = name; };
	void setDuration(int d) { this->m_duration = d; };
	void setPriority(int p) { this->m_priority = p; };

	//五法则
	Task() noexcept {}//无参构造
	Task(std::string n, int d, int p)
		:m_name(n), m_duration(d), m_priority(p) {}//有参构造

	Task (const Task& other) // 拷贝构造函数
    {
        if (this != &other) // 防止自复制
        {
            this->m_name = other.m_name;
            this->m_duration = other.m_duration;
            this->m_priority = other.m_priority;
        }
    }

	//拷贝赋值运算符，是在已经构造过对象，分配了内存空间的基础上进行赋值的
	//返回值加上引用，避免重复构造
	Task& operator = (const Task& other)
	{
		if (this != &other)//防止自赋值
		{
			this->m_name = other.m_name;
			this->m_duration = other.m_duration;
			this->m_priority = other.m_priority;

		}
		return *this;//返回已有对象的引用
	}

	//析构函数
	~Task() {}

	//移动构造函数
	Task(Task&& other) noexcept :
		m_name(std::move(other.m_name)), //移动语义将other.m_name转换成右值引用而不是进行深拷贝
		m_duration(other.m_duration), //基本数据类型（int），它们的复制成本很低，因此不需要移动语义。
		m_priority(other.m_priority)
	{
		//避免悬空引用
		//other.m_name = "" //错误，char*无法赋值给string
		//一个std::string对象使用赋值运算符（=）来赋值一个字符串字面量，编译器会寻找一个接受const std::string&或std::string&&作为参数的赋值运算符。然而，std::string类的赋值运算符并不接受一个const char*`类型的参数，因为它可能会引起悬挂指针问题。
		other.m_name = std::string();
		other.m_duration = 0;
		other.m_priority = 0;
	}

	/*
	* 如果形参列表采用 const 的右值引用，那么对后续的避免悬空操作会有影响
	* //因为悬空和操作试图将原来的资源置为“空”
	* //而const是不允许被改写的
	Task(const Task&& other) noexcept :
		...
	{
	//报错
		other.m_name = std::string();//没有与这些操作数匹配的 "=" 运算符

	}
	*/

	//移动赋值运算符
	Task& operator = (Task&& other) noexcept
	{
		if (this != &other)
		{
			this->m_name = other.m_name;
			this->m_duration = other.m_duration;
			this->m_priority = other.m_priority;


			//避免悬空引用
			other.m_name = std::string();
			other.m_duration = 0;
			other.m_priority = 0;
		}
		return *this;
	}


};



class TaskComparetor
{
public:
	//const Task& lhs  对应  int getPriority() const  要么都有const修饰，要么都没有
	bool operator () (const Task& lhs, const Task& rhs)
	{
		if (lhs.getPriority() == rhs.getPriority()) 
		{
			return lhs.getDuration() < rhs.getDuration();
		}
		else
		{
			return lhs.getPriority() > rhs.getPriority();
		}
	}
};


#endif
