#include"ACautomation.h"

//��Tire�����в���ģʽ��word
void AcAutomation::Insert(const std::string& word) //ģʽ��Ĭ����û�л��з���
{
	std::shared_ptr<AcNode> temp = this->root; //�Ӹ��ڵ㿪ʼ����

	for (const auto& c : word) //ֱ�Ӳ����ַ����е��ַ��������Ǵ����ַ��ĸ���
	{
		//tmp���ӽڵ㵱����û���ַ� c
		if (temp->next.find(c) == temp->next.end()) //���û�У�˵������ַ�Ҫ�����뵽������
		{
			//����һ���ڵ㣬������path
			std::shared_ptr<AcNode> new_node(new(AcNode));
			new_node->path = temp->path + c; //·��
			temp->next.insert({ c, new_node });
		}

		//temp���ӽڵ㵱�����ַ�c ��ֱ������
		temp = temp->next[c];
	}
	//�����ؼ��ֱ������֮�󣬾���Ҫ���ñ�־
	temp->end_flag = true;

}

//BFS ����Failָ��
void AcAutomation::BuildFailPointer()
{
	std::queue<std::shared_ptr<AcNode>> qu;
	qu.push(this->root); //���ڵ������ָ��Ĭ����nullptr
	while (!qu.empty())
	{
		std::shared_ptr<AcNode> cur = qu.front();
		qu.pop();
		for (const auto& it : cur->next)//����cur�������ӽڵ�
		{
			char c = it.first;
			std::shared_ptr<AcNode> son = it.second;

			if (cur == this->root) //���ڵ�
			{
				son->fail = this->root;
			}
			else
			{
				std::shared_ptr<AcNode> p = cur->fail;
				while (p != nullptr) //ֻ�и��ڵ��failָ����nullptr
				{
					if (p->next.find(c) != p->next.end()) //p �к��� c
					{
						son->fail = p->next[c];
						break;
					}
					p = p->fail;
				}

				if (p == root->fail) //һֱ�ң� �����˶�ָ����root->fail�˻���û���ҵ�
					son->fail = this->root;
			}

			qu.push(son);

		}
	}
}



void AcAutomation::AcInit(const std::vector<std::string>& keywords) //Keyword������ac�Զ����е�Tire��
{
	this->root = std::make_shared<AcNode>();

	//����ؼ���
	for (auto key : keywords)
	{
		this->Insert(key);
	}

	//����Failָ��
	this->BuildFailPointer();

}

//ƥ���ַ��� mains ��ʾ������ģʽ���Ѿ���ʼ������Tire��
//����ֵ�� <keyword, keyword���ֵĸ���>
std::unordered_map<std::string, std::vector<long long>>
AcAutomation::AcSearch(const char* const ptr, const size_t bufferSize)
{
	std::unordered_map<std::string, std::vector<long long>> res;

	//���λ��countliine��ʼֵΪ0�� ÿ������һ�����з���+1
	long long countline = 0;
	
	std::shared_ptr<AcNode> p = this->root;

	for (long long i = 0; i < bufferSize; i++)
	{
		if (*(ptr + i) == '\n')
		{
			countline++; //���Ի��з� �ؼ��ֿ��Կ���ƥ��
			continue; 
		}

		//ʧ��
		while (p && p->next.find(*(ptr + i)) == p->next.end()) //p �ĺ�����û���ҵ���mains��ƥ���mains[i]
		{
			p = p->fail;
		}
		if (p == nullptr) //˵����������û�ж�Ӧ���ӽڵ㣬pָ����root��failָ��
		{
			p = this->root;
		}
		else //˵�� p ��ʱ�� mains[i]ƥ��  pָ���� mains[i]
		{
			p = p->next[*(ptr + i)];
		}

		//������ڵ��·���Ƿ��Ӧ�˹ؼ���
		std::shared_ptr<AcNode> temp = p;
		while (temp != this->root)
		{
			if (temp->end_flag == true)
			{
				if (res.find(temp->path) == res.end()) //��һ���ҵ�������
				{
					res.insert({ temp->path, {countline} });
				}
				else
				{
					res[temp->path].push_back(countline);
				}
			}
			temp = temp->fail; //������������ǰ׺�ǲ��ǹؼ���
		}

	}

	//��ÿһ�������countline��������
	res.insert({ "__MAX__LINES__", {countline}});



	return res;

}


//ǳ����
AcAutomation::AcAutomation(const AcAutomation& oher)
{
	this->root = oher.root;
}