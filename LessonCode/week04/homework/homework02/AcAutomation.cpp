#include"ACautomation.h"

//在Tire树当中插入模式串word
void AcAutomation::Insert(const std::string& word) //模式串默认是没有换行符的
{
	std::shared_ptr<AcNode> temp = this->root; //从根节点开始遍历

	for (const auto& c : word) //直接操作字符串中的字符，而不是创建字符的副本
	{
		//tmp的子节点当中有没有字符 c
		if (temp->next.find(c) == temp->next.end()) //如果没有，说明这个字符要被插入到树当中
		{
			//创建一个节点，并更新path
			std::shared_ptr<AcNode> new_node(new(AcNode));
			new_node->path = temp->path + c; //路径
			temp->next.insert({ c, new_node });
		}

		//temp的子节点当中有字符c 就直接往下
		temp = temp->next[c];
	}
	//整个关键字遍历完成之后，就需要设置标志
	temp->end_flag = true;

}

//BFS 构建Fail指针
void AcAutomation::BuildFailPointer()
{
	std::queue<std::shared_ptr<AcNode>> qu;
	qu.push(this->root); //根节点的适配指针默认是nullptr
	while (!qu.empty())
	{
		std::shared_ptr<AcNode> cur = qu.front();
		qu.pop();
		for (const auto& it : cur->next)//遍历cur的所有子节点
		{
			char c = it.first;
			std::shared_ptr<AcNode> son = it.second;

			if (cur == this->root) //根节点
			{
				son->fail = this->root;
			}
			else
			{
				std::shared_ptr<AcNode> p = cur->fail;
				while (p != nullptr) //只有根节点的fail指针是nullptr
				{
					if (p->next.find(c) != p->next.end()) //p 有孩子 c
					{
						son->fail = p->next[c];
						break;
					}
					p = p->fail;
				}

				if (p == root->fail) //一直找， 找完了都指向了root->fail了还是没有找到
					son->fail = this->root;
			}

			qu.push(son);

		}
	}
}



void AcAutomation::AcInit(const std::vector<std::string>& keywords) //Keyword来构建ac自动机中的Tire树
{
	this->root = std::make_shared<AcNode>();

	//插入关键字
	for (auto key : keywords)
	{
		this->Insert(key);
	}

	//建立Fail指针
	this->BuildFailPointer();

}

//匹配字符串 mains 表示主串，模式串已经初始化成了Tire树
//返回值是 <keyword, keyword出现的个数>
std::unordered_map<std::string, std::vector<long long>>
AcAutomation::AcSearch(const char* const ptr, const size_t bufferSize)
{
	std::unordered_map<std::string, std::vector<long long>> res;

	//相对位置countliine初始值为0， 每次碰到一个换行符就+1
	long long countline = 0;
	
	std::shared_ptr<AcNode> p = this->root;

	for (long long i = 0; i < bufferSize; i++)
	{
		if (*(ptr + i) == '\n')
		{
			countline++; //忽略换行符 关键字可以跨行匹配
			continue; 
		}

		//失配
		while (p && p->next.find(*(ptr + i)) == p->next.end()) //p 的孩子中没有找到与mains相匹配的mains[i]
		{
			p = p->fail;
		}
		if (p == nullptr) //说明主串当中没有对应的子节点，p指向了root的fail指针
		{
			p = this->root;
		}
		else //说明 p 此时与 mains[i]匹配  p指向孩子 mains[i]
		{
			p = p->next[*(ptr + i)];
		}

		//看这个节点的路径是否对应了关键字
		std::shared_ptr<AcNode> temp = p;
		while (temp != this->root)
		{
			if (temp->end_flag == true)
			{
				if (res.find(temp->path) == res.end()) //第一查找到这个结果
				{
					res.insert({ temp->path, {countline} });
				}
				else
				{
					res[temp->path].push_back(countline);
				}
			}
			temp = temp->fail; //继续查找它的前缀是不是关键词
		}

	}

	//将每一块里面的countline保存起来
	res.insert({ "__MAX__LINES__", {countline}});



	return res;

}


//浅拷贝
AcAutomation::AcAutomation(const AcAutomation& oher)
{
	this->root = oher.root;
}