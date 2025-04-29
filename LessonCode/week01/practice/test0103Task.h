#pragma once
#include<string>

#ifndef Task_H

class Task
{
private:

	std::string m_name;//��������
	int m_duration; //ִ��ʱ��
	int m_priority; //�������ȼ�

public:
	//����ֻ�ǻ�ȡֵ����ϣ����ֵ�����޸� ����ʹ�� const
	std::string getName() const { return m_name; };
	int getDuration() const { return m_duration; };
	int getPriority() const { return m_priority; };

	void setName(std::string name) { this->m_name = name; };
	void setDuration(int d) { this->m_duration = d; };
	void setPriority(int p) { this->m_priority = p; };

	//�巨��
	Task() noexcept {}//�޲ι���
	Task(std::string n, int d, int p)
		:m_name(n), m_duration(d), m_priority(p) {}//�вι���

	Task (const Task& other) // �������캯��
    {
        if (this != &other) // ��ֹ�Ը���
        {
            this->m_name = other.m_name;
            this->m_duration = other.m_duration;
            this->m_priority = other.m_priority;
        }
    }

	//������ֵ������������Ѿ���������󣬷������ڴ�ռ�Ļ����Ͻ��и�ֵ��
	//����ֵ�������ã������ظ�����
	Task& operator = (const Task& other)
	{
		if (this != &other)//��ֹ�Ը�ֵ
		{
			this->m_name = other.m_name;
			this->m_duration = other.m_duration;
			this->m_priority = other.m_priority;

		}
		return *this;//�������ж��������
	}

	//��������
	~Task() {}

	//�ƶ����캯��
	Task(Task&& other) noexcept :
		m_name(std::move(other.m_name)), //�ƶ����彫other.m_nameת������ֵ���ö����ǽ������
		m_duration(other.m_duration), //�����������ͣ�int�������ǵĸ��Ƴɱ��ܵͣ���˲���Ҫ�ƶ����塣
		m_priority(other.m_priority)
	{
		//������������
		//other.m_name = "" //����char*�޷���ֵ��string
		//һ��std::string����ʹ�ø�ֵ�������=������ֵһ���ַ�������������������Ѱ��һ������const std::string&��std::string&&��Ϊ�����ĸ�ֵ�������Ȼ����std::string��ĸ�ֵ�������������һ��const char*`���͵Ĳ�������Ϊ�����ܻ���������ָ�����⡣
		other.m_name = std::string();
		other.m_duration = 0;
		other.m_priority = 0;
	}

	/*
	* ����β��б���� const ����ֵ���ã���ô�Ժ����ı������ղ�������Ӱ��
	* //��Ϊ���պͲ�����ͼ��ԭ������Դ��Ϊ���ա�
	* //��const�ǲ�������д��
	Task(const Task&& other) noexcept :
		...
	{
	//����
		other.m_name = std::string();//û������Щ������ƥ��� "=" �����

	}
	*/

	//�ƶ���ֵ�����
	Task& operator = (Task&& other) noexcept
	{
		if (this != &other)
		{
			this->m_name = other.m_name;
			this->m_duration = other.m_duration;
			this->m_priority = other.m_priority;


			//������������
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
	//const Task& lhs  ��Ӧ  int getPriority() const  Ҫô����const���Σ�Ҫô��û��
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
