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

//AC自动机，多模式匹配算法
class AcAutomation
{
private:
	//Tire树上的节点
	struct AcNode
	{
		bool end_flag; //如果读到这个节点能够匹配到一个模式串,就为true,否则为false
		std::unordered_map<char, std::shared_ptr<AcNode>> next; //指向所有子节点的指针集
		std::shared_ptr<AcNode> fail; //fail指针，失配指针
		std::string path;

		AcNode()
		{
			end_flag = false;
			fail = nullptr;
		}

	};

	std::shared_ptr<AcNode> root; //Tire树当中的根节点

	//在Tire树当中插入模式串word
	void Insert(const std::string& word);

	//BFS 实现Tire树的构建
	void BuildFailPointer();


public:
	void AcInit(const std::vector<std::string>& keyword); //Keyword来构建ac自动机中的Tire树

	//返回值是一个<keyword, keyword出现的个数>
	std::unordered_map<std::string, std::vector<long long>>
		AcSearch(const char* const ptr, const size_t bufferSize);

	AcAutomation() {}
	AcAutomation(const AcAutomation& oher);

};


#endif
