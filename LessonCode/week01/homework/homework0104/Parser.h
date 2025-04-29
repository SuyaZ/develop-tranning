#pragma once

#include"KJson.h"
#include<string>
#include<iostream>

namespace kjsonh
{
	namespace json //解析器类型
	{
		class Parser
		{
		public:
			//构造函数
			Parser();

			void load(const std::string& str); //撰写一个预加载函数

			//解析器的parse函数
			KJson parse();

		private:
			std::string m_str;//数据保存到字符串
			int m_index; //解析之后设计到的索引，就保存到index里面

			void white_skip();//解析式跳过空格 制表符 回车等无意义的空白键
			char get_next_char();//获取下一个字符
			//对于字符串，双引号也包含在了字符串当中。

			//分别判断值的类型调用不同的解析函数，返回m_type不同的KJson对象
			KJson parse_null();
			KJson parse_bool();
			KJson parse_number();

			//对一个键值对对象，解析key的时候需要返回string， 解析value的时候，需要返回KJson
			//其实解析的步骤都差不多，就两个功能放在一起实现，即解析之后返回值为string 
			std::string parse_string();

			KJson parse_array();
			KJson parse_object();

		};

	}
}