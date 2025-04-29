#include"parser.h"
#include"KJson.h"
#include<string>

using namespace kjsonh::json;

//构造函数
//默认构造函数
Parser::Parser() :
	m_str(""), m_index(0) {}

//预加载函数
void Parser::load(const std::string& str)
{
	m_str = str;
	m_index = 0;
}

void Parser::white_skip()//解析式跳过空格 制表符 回车等无意义的空白键
{
	while (m_str[m_index] == ' ' || m_str[m_index] == '\t' || m_str[m_index] == '\n' || m_str[m_index] == '\r')
	{
		m_index++;
	}
}

char Parser::get_next_char()//获取下一个字符
{
	white_skip(); //如果 Parser 中的索引m_index指向空白符，就跳过；否则就什么也不会做
	char ch = m_str[m_index];
	m_index++;
	return ch;

}



//解析器的parse函数
KJson Parser::parse()
{
	char ch = get_next_char();//特殊字符只有数字、null、true、false，其他的字符串是以双引号开头的
	//m_index--;
	switch (ch)
	{
	case 'n':
		m_index--;
		return parse_null();
		break;
	case 't':
	case 'f':
		m_index--;
		return parse_bool();
		break;
	case '-': //数字类型有可能以负号开头或者数字开头
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		m_index--;
		return parse_number(); //解析数字，分浮点型和整型两种情况讨论
		break;
	case '"':
		//m_index--;
		return KJson(parse_string());  //字符串类型不需要回退
		break;
	case '[':
		//m_index--;
		return parse_array();  //数组类型不需要回退
		break;
	case '{':
		//m_index--;
		return parse_object();
		break;

	default: return KJson(); 
		std::cout << "数据错误存在未定义类型\n";
		break;
	}
}


KJson Parser::parse_null()
{
	//compare 方法返回 0 表示两个字符串相等
	if (m_str.compare(m_index, 4, "null") == 0)
	{
		m_index += 4;
		return KJson();
	}
	else
	{
		std::cout << "数据类型错误\n";
	}
}


KJson Parser::parse_bool()
{
	if (m_str.compare(m_index, 4, "true") == 0)
	{
		m_index += 4;
		return KJson(true);
	}
	else if (m_str.compare(m_index, 5, "false") == 0)
	{
		m_index += 5;
		return KJson(false);
	}
	else
	{
		std::cout << "数据类型错误\n";
	}
}

KJson Parser::parse_number()
{
	int pos = m_index;
	if (m_str[m_index] == '-')
	{
		m_index++;
	}
	if (!isdigit(m_str[m_index]))
	{
		std::cout << "parser number error, not number" << std::endl;
	}
	while (isdigit(m_str[m_index]))
	{
		m_index++;
	}

	if (m_str[m_index] != '.')
	{
		int n = std::atoi(m_str.c_str() + pos);
		return KJson(n);
	}
	m_index++;

	while (isdigit(m_str[m_index]))
	{
		m_index++;
	}

	double f = std::atof(m_str.c_str() + pos);
	return KJson(f);
}

std::string Parser::parse_string()
{
	std::string res;
	while (true)
	{
		char ch = m_str[m_index++];
		if (ch == '"') //到末尾
		{
			break;
		}
		if (ch == '\\') //考虑转义字符
		{
			ch = m_str[m_index++];
			switch (ch)
			{
			case '\n':
				res += '\n';
				break;
			case '\r':
				res += '\r';
				break;
			case '\t':
				res += '\t';
				break;
			case '\b':
				res += '\b';
				break;
			case '\f':
				res += '\f';
				break;
			case '"':
				res += "\\\"";
				break;
			case '\\':
				res += "\\\\";
				break;
			case 'u':
				res += "\\u";
				for (int i = 0; i < 4; i++)
				{
					res += m_str[m_index++];
				}
				break;
			default:
				break;
			}
		}
		else
		{
			res += ch;
		}
	}
	return res;
}

KJson Parser::parse_array()
{
	KJson arr(KJson::json_array);//根据类型构造，此时会将m_type赋值为json_array,然后创建一个vector<KJson>, 并保存指针
	char ch = get_next_char();
	if (ch == ']')//象征着数组的结束
	{
		return arr;//返回数组类；
	}
	m_index--;
	while (true)
	{
		arr.append(Parser::parse());//调用解析器的parse函数，去解析下一个元素。
		ch = get_next_char();
		if (ch == ']') break;
		if (ch != ',')
		{
			std::cout << "数组解析错误" << std::endl;
		}
		//else m_index--;
		m_index++;
	}
	return arr;
}

KJson Parser::parse_object()
{
	KJson obj(KJson::json_object); //和数组一样，根据类型构造对象
	char ch = get_next_char();
	if (ch == '}') //表示是一个空对象，直接返回空的obj就可以了
		return obj;
	m_index--;
	while (true)
	{
		//在一个类里面首先先解析键值，键值以双引号开头，
		ch = get_next_char();
		if (ch != '"') std::cout << "ERROR" << std::endl;
		std::string key = this->parse_string();

		ch = get_next_char();
		if (ch != ':') std::cout << "类应该有冒号" << std::endl;
		
		obj[key] = parse(); //<key, parse()>

		ch = get_next_char();
		if (ch == '}') break;
		if (ch != ',') std::cout << "ERROR" << std::endl;
		m_index++;
	}
	return obj;
}