#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<algorithm>

#ifndef __ACAUTOMATION_H__
#define __ACAUTOMATION_H__

//AC�Զ�������ģʽƥ���㷨
class AcAutomation
{
private:
	//Tire���ϵĽڵ�
	struct AcNode
	{
		bool end_flag; //�����������ڵ��ܹ�ƥ�䵽һ��ģʽ��,��Ϊtrue,����Ϊfalse
		std::unordered_map<char, std::shared_ptr<AcNode>> next; //ָ�������ӽڵ��ָ�뼯
		std::shared_ptr<AcNode> fail; //failָ�룬ʧ��ָ��
		std::string path;

		AcNode()
		{
			end_flag = false;
			fail = nullptr;
		}

	};

	std::shared_ptr<AcNode> root; //Tire�����еĸ��ڵ�

	//��Tire�����в���ģʽ��word
	void Insert(const std::string& word);

	//BFS ʵ��Tire���Ĺ���
	void BuildFailPointer();


public:
	void AcInit(const std::vector<std::string>& keyword); //Keyword������ac�Զ����е�Tire��

	//����ֵ��һ��<keyword, keyword���ֵĸ���>
	std::unordered_map<std::string, std::vector<long long>>
		AcSearch(const char* const ptr, const size_t bufferSize);

	AcAutomation() {}
	AcAutomation(const AcAutomation& oher);

};


#endif
