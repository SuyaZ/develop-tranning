
#include<iostream>
#include<map>
#include<vector>

//using namespace std;

int main()
{
	std::map < std::string, std::vector<int>> data =
	{
		{"a", {1, 4, 10}},
		{"b", {5, 7, 9}},
		{"d", {7, 8, 9}}
	};

	std::map<std::string, double> res;

	for (const auto it : data)//自动类型转换 it自动匹配data的内容类型
	{
		int average = 0;
		for (const auto t : it.second)//it.second 转换为int类型
		{
			average += t;
		}

		res.insert({ it.first, average / 3.0 });
	}

	for (const auto it : res)
	{
		std::cout << it.first << "   " << it.second << std::endl;
	}

	return 0;
}

