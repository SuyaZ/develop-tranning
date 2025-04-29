#include"KJson.h"
#include"parser.h"
#include<iostream>
#include<sstream>

//头文件中的名称空间包含进来
using namespace kjsonh::json;

//默认构造函数，无参构造的时候默认为空值
KJson::KJson() :
	m_type(json_null) {}

KJson::KJson(bool value) :
	m_type(json_bool)
{
	m_value.m_bool = value; //m_value是一个KJson的成员，而m_value又是一个联合体，实际上是将value值传参给m_value当中的m_bool成员
}

KJson::KJson(int value) :
	m_type(json_int)
{
	m_value.m_int = value;
}

KJson::KJson(double value) :
	m_type(json_double)
{
	m_value.m_double = value;
}

//m_string 是 <string*>
KJson::KJson(const char* value) :
	m_type(json_string)
{
	m_value.m_string = new std::string(value);
	//string接受char*风格的字符串
	//new()运算返回指向内存的指针
}

KJson::KJson(const std::string& value) :
	m_type(json_string)
{
	m_value.m_string = new std::string(value);
}

/*
KJson::KJson(std::vector<KJson>* value) :
	m_type(json_array)
{
	m_value.m_array = value;
}*/

KJson::KJson(Type type) :
	m_type(type)
{
	switch (type) // 由类型来初始化值,默认都为空值
	{
	case json_null:
		break;
	case json_bool:
		m_value.m_bool = false;
		break;
	case json_int:
		m_value.m_int = 0;
		break;
	case json_double:
		m_value.m_double = 0.0;
		break;
	case json_string:
		m_value.m_string = new std::string("");
		break;
	case json_array:
		m_value.m_array = new std::vector<KJson>();
		break;
	case json_object:
		m_value.m_object = new std::map<std::string, KJson>();
		break;
	default:
		break;
	}
}


//对于其他的KJson对象
//对象还没有被构造出来的时候使用拷贝构造
KJson::KJson(const KJson& other)
{
	//此时KJson对象的value值类型取决于嵌套类的value值类型
	m_type = other.m_type;
	switch (m_type)
	{
	case json_null: break; //空值就什么也不坐
	case json_bool:
		m_value.m_bool = other.m_value.m_bool;
		break;
	case json_int:
		m_value.m_int = other.m_value.m_int;
		break;
	case json_double:
		m_value.m_double = other.m_value.m_double;
		break;
	case json_string:
		m_value.m_string = other.m_value.m_string; //浅拷贝，指针拷贝
		break;
	case json_array:
		m_value.m_array = other.m_value.m_array; //浅拷贝，指针拷贝
		break;
	case json_object:
		m_value.m_object = other.m_value.m_object; //浅拷贝，指针拷贝
		break;
	default:
		break;
	}
}



//修改的是键值对，数组和类就不提供修改的接口了
void KJson::setBool(bool value)
{
	m_value.m_bool = value;
}

bool KJson::getBool() const
{
	return m_value.m_bool;
}

void KJson::setInt(int value)
{
	m_value.m_int = value;
}

int KJson::getInt() const
{
	return m_value.m_int;
}

void KJson::setDouble(double value)
{
	m_value.m_double = value;
}

double KJson::getDouble() const
{
	return m_value.m_double;
}

void KJson::setString(std::string value)
{
	clear(); //释放指针指向的内存
	m_type = json_string; //设置类型
	m_value.m_string = new std::string(value); //重新分配空间并赋值
}

std::string KJson::getString() const
{
	return (*(m_value.m_string));
}


KJson& KJson::operator[](int index)
{
	if (m_type != json_array)
	{
		//KJson original(*this); // 保存原始值
		m_type = json_array;
		m_value.m_array = new std::vector<KJson>();
		//m_value.m_array->push_back(original);
	}

	int size = m_value.m_array->size();
	if (index < 0)
	{
		std::cout << "数组下标不合法！" << std::endl;
		//throw std::out_of_range("Negative index");
	}
	if (index >= size)
	{
		for (int i = size; i <= index; i++)
		{
			m_value.m_array->push_back(KJson());
		}
	}
	return m_value.m_array->at(index);
}

//能够通过append函数实现数组的追加
void KJson::append(const KJson& other)
{
	//如果原本的value类型不是数组类型

	if (m_type != json_array)
	{
		// 保存原有的值到一个临时对象
		//KJson original(*this);

		// 转换当前对象为数组类型
		m_type = json_array;
		m_value.m_array = new std::vector<KJson>();

		// 将原始值追加到数组中
		//m_value.m_array->push_back(original);
		//union类型是联合体类型，共用同一块内存，存储指针之后，会把上一次的数据给覆盖掉
	}
	(m_value.m_array)->push_back(other);
}



//以字符串的格式返回Json的内容
std::string KJson::str() const
{
	//std::string tmp;
	std::stringstream ss;
	switch (m_type)
	{
	case json_null: ss << "null";
		break;
	case json_bool:
	{
		if (m_value.m_bool == true) { ss << "true"; }
		else { ss << "false"; }
		break;
	}
	case json_int:
		ss << m_value.m_int;
		break;
	case json_double:
		ss << std::to_string(m_value.m_double);
		break;
	case json_string:
		//std::cout << (*(m_value.m_string)) << std::endl;
		ss << '\"' << (*(m_value.m_string)) << '\"';
		break;
	case json_array:
		ss << "[";
		for (auto it = (m_value.m_array)->begin(); it != (m_value.m_array)->end(); it++)
		{
			ss << (*it).str();
			if (it != m_value.m_array->end() - 1) ss << ", ";
		}
		ss << "]";
		break;
	case json_object:
		ss << "{";
		for (auto it = (m_value.m_object)->begin(); it != (m_value.m_object)->end(); it++)
		{
			if (it != m_value.m_object->begin()) ss << ",  ";
			ss << "\"" << it->first << "\" :" << it->second.str();
		}
		ss << "}";

	default:
		break;
	}
	return ss.str();
}




//std::map当中重载了运算符operator[]，支持键值查找value
//根据map对象中的type找到符合条件的值，如果能找到，就返回这个值对应的KJson对象的引用
//如果没有找到，std::map就会根据这个键值创建一个map实例，然后返回这个实例的值 KJson
KJson& KJson::operator[](const std::string key)
{
	//如果这个类型不是对象类型
	if (m_type != json_object)
	{
		clear();
		m_type = json_object;
		m_value.m_object = new std::map<std::string, KJson>();
	}

	return (*(m_value.m_object))[key];
}

//对象已经被分配内存的时候，使用拷贝赋值函数
void KJson::operator = (const KJson& other)
{
	this->clear();//先清理掉内存再做拷贝，这样原来的指针指向的空间可以释放掉，避免内存泄露

	m_type = other.m_type;
	switch (m_type)
	{
	case json_null: break; //空值就什么也不做
	case json_bool:
		m_value.m_bool = other.m_value.m_bool;
		break;
	case json_int:
		m_value.m_int = other.m_value.m_int;
		break;
	case json_double:
		m_value.m_double = other.m_value.m_double;
		break;
	case json_string:
		m_value.m_string = other.m_value.m_string; //浅拷贝，指针拷贝
		//m_value.m_string = new std::string(*(other.m_value.m_string));
		break;
	case json_array:
		m_value.m_array = other.m_value.m_array; //浅拷贝，指针拷贝
		break;
	case json_object:
		m_value.m_object = other.m_value.m_object; //浅拷贝，指针拷贝
		break;
	default:
		break;
	}
}



//复制函数，专门用于嵌套的数据，不会调用clear 
void KJson::Copy(const KJson& other)
{
	m_type = other.m_type;
	switch (m_type)
	{
	case json_null: break; //空值就什么也不做
	case json_bool:
		m_value.m_bool = other.m_value.m_bool;
		break;
	case json_int:
		m_value.m_int = other.m_value.m_int;
		break;
	case json_double:
		m_value.m_double = other.m_value.m_double;
		break;
	case json_string:
		m_value.m_string = other.m_value.m_string; //浅拷贝，指针拷贝
		//m_value.m_string = new std::string(*(other.m_value.m_string));
		break;
	case json_array:
		m_value.m_array = other.m_value.m_array; //浅拷贝，指针拷贝
		break;
	case json_object:
		m_value.m_object = other.m_value.m_object; //浅拷贝，指针拷贝
		break;
	default:
		break;
	}
}


void KJson::clear()
{
	switch (m_type)
	{
	case json_null:
		break;
	case json_bool:m_value.m_bool = false;
		break;
	case json_int:m_value.m_int = 0;
		break;
	case json_double:m_value.m_double = 0.0;
		break;
	case json_string:delete(m_value.m_string);//释放指针
		//m_value.m_string = nullptr;//避免悬空引用
		break;
	case json_array:
		for (auto it = (m_value.m_array)->begin(); it != (m_value.m_array)->end(); it++)
		{
			it->clear();//递归,销毁KJson数组元素
		}
		delete(m_value.m_array);
		//m_value.m_array = nullptr;
		break;
	case json_object:
		for (auto it = (m_value.m_object)->begin(); it != (m_value.m_object)->end(); it++)
		{
			//it->clear(); //map<string, KJson>是自定义成员类型，map没有std::clear适配，但是KJson有适配的clear.
			it->second.clear();
		}
		delete(m_value.m_object);
		//m_value.m_object = nullptr;
		break;

	default:
		break;
	}

	m_type = json_null;
}


//判断数组当中有没有这个索引
bool KJson::has(int index)
{
	if (m_type != json_array)
	{
		std::cout << "错误，请提供正确的array类型" << std::endl;
		return false;
	}

	int size = m_value.m_array->size();
	if (index < size && index >= 0)
	{
		return true;
	}
	else return false;
}

//然后对象当中有没有这个key值
bool KJson::has(const std::string& key)
{
	if (m_type != json_object)
	{
		std::cout << "错误，请提供正确的array类型" << std::endl;
		return false;
	}
	//利用map特性查找知否存在这样的一个键值
	return (m_value.m_object)->find(key) != (m_value.m_object)->end();
}


//删除索引为key的对象
void KJson::remove(const std::string& key)
{
	if (this->has(key) == false) //没有键值为key的map元素
	{
		std::cout << "错误，请提供正确的索引" << std::endl;
		return;
	}
	else
	{
		//m_value.m_object->erase(key);也有可能造成迭代器失效的问题
		for (auto it = (m_value.m_object)->begin(); it != (m_value.m_object)->end(); )
		{
			if (it->first == key)
			{
				it = (m_value.m_object)->erase(it); // erase 返回下一个有效的迭代器
			}
			else
			{
				++it;
			}
		}
	}
}


//每一个KJson对象都会有一个属于自己的解析器，这样不用担心冲突
void KJson::parse(const std::string& str)
{
	Parser p;//定义一个解析器，解析原始的字符串str
	p.load(str);

	//p.parse();返回的是一个KJson对象的副本然后利用KJson的拷贝运算函数做赋值 赋值给（*this）
	*this = p.parse();

}


//以字符串的格式返回Json的内容
std::string KJson::str2() const
{
	//std::string tmp;
	std::stringstream ss;
	switch (m_type)
	{
	case json_null: ss << "null";
		break;
	case json_bool:
	{
		if (m_value.m_bool == true) { ss << "true"; }
		else { ss << "false"; }
		break;
	}
	case json_int:
		ss << m_value.m_int;
		break;
	case json_double:
		ss << std::to_string(m_value.m_double);
		break;
	case json_string:
		//std::cout << (*(m_value.m_string)) << std::endl;
		ss << '\"' << (*(m_value.m_string)) << '\"';
		break;
	case json_array:
		ss << "[";
		for (auto it = (m_value.m_array)->begin(); it != (m_value.m_array)->end(); it++)
		{
			ss << (*it).str2();
			if (it != m_value.m_array->end() - 1) ss << ", ";
		}
		ss << "]" << std::endl;
		break;
	case json_object:
		ss << std::endl << "{";
		for (auto it = (m_value.m_object)->begin(); it != (m_value.m_object)->end(); it++)
		{
			if (it != m_value.m_object->begin()) ss << ",  " << std::endl;
			ss << "\t" << "\"" << it->first << "\" :" << it->second.str2();
		}
		ss << std::endl << "}" << std::endl;

	default:
		break;
	}
	return ss.str();
}


//分割字符串函数 默认分割符为空格 
void KJson::StringSplit(std::string str, std::vector<std::string>& res)
{
	int idx = 0;//设置指针，指向操作下标
	int size = str.size();

	while (idx < size)
	{
		std::string stmp = "";//初始为空串

		while (str[idx] == ' ' || str[idx] == '"') idx++;
		while (str[idx] != ' ' && idx < size && str[idx] != '"')
		{
			stmp += str[idx], idx++;
		}

		if (stmp != "") res.push_back(stmp);
	}

}


KJson& visit(std::vector<std::string>& options, KJson& top)
{
	int pt = 0;//指针
	int size = options.size();
	KJson* pre = &top; //pre指向top所在的内存空间

	//std::cout << pre[options[pt]].str();

	KJson* now = nullptr;
	while (pt < size)
	{
		//赋值迭代的时候需要考虑到数组的条件，如果是字符串就是类，如果是数字开头的就是数组下标

		if (options[pt][0] >= '0' && options[pt][0] <= '9') //pre是数组
		{
			int n = std::stoi(options[pt]);
			now = &(*pre)[n]; //如果pre指向的空间是一个数组类型，那么就将这块空间的地址保存到now当中
		}
		else now = &(*pre)[options[pt]]; //pre是object

		//std::cout << now.str() << "********************************************\n\n\n\n\n\n";

		pt++;
		//pre = now;//直接赋值的时候，由于pre会先把对应的内存资源释放掉，由于pre里面嵌套着now,因此会出现now里面指针悬空的情况
		//如果想要创建副本，也是不可行的，因为实质上是浅拷贝，clear()主本的时候会把指针指向的内存资源也释放掉，导致副本内的指针也会失效

		//避免直接赋值
		pre = now;


	}

	//跳出循环的时候，pre = now; pt = size;

	//return *now;
	return *pre;

}






//和用户交互的接口定义

void KJson::QQuery() //查
{
	std::cout << "\nPlease enter the string in the format so that you can locate the data you want to query;" << std::endl
		<< "The format of the string is: “ \"key1\" \"key2\" \"key3\"... (int)数字 \"key4\" ”  " << std::endl
		<< "where \"keyX\" represents the key value, which is used to access the object type;" << std::endl
		<< "(int) is an integer type that represents an index and is used to access elements in an array.\n" << std::endl;

	std::string op;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//吃掉上一个回车符，不然getline()会提前结束
	std::getline(std::cin, op); //输入用户的字符串并准备解析
	//std::cout << op << std::endl;

	std::vector<std::string> options; //每一个元素都保存一个查询的键值或者下标
	StringSplit(op, options);

	KJson loc = visit(options, (*this));

	std::cout << loc.str2() << std::endl;
}

void KJson::Update() //改
{
	std::cout << "\nPlease enter the string in the format so that you can locate the data you want to query;" << std::endl
		<< "The format of the string is: “ \"key1\" \"key2\" \"key3\"... (int)数字 \"key4\" ”  " << std::endl;

	//修改键值对的内容，注意value值不是一个object，不是一个array，而是其他的具体的值

	std::string op;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//吃掉上一个回车符，不然getline()会提前结束
	std::getline(std::cin, op); //输入用户的字符串并准备解析
	//std::cout << op << std::endl;

	std::vector<std::string> options; //每一个元素都保存一个查询的键值或者下标
	StringSplit(op, options);

	KJson& loc = visit(options, (*this)); //定位到想要作出修改的键值对的值KJson对象

	switch (loc.getType())
	{
	case json_null:
	{
		std::cout << "空值不可修改！" << std::endl;
		break;
	}
	case json_bool:
	{
		std::cout << "请输入Bool类型的数据。" << std::endl;
		bool b;
		std::cin >> b;
		loc.setBool(b);
		std::cout << "修改完成，修改后的结果为：" << loc.str2() << "\n" << std::endl;
		break;
	}
	case json_int:
	{
		std::cout << "请输入int类型的数据。" << std::endl;
		int ii;
		std::cin >> ii;
		loc.setInt(ii);
		std::cout << "修改完成，修改后的结果为：" << loc.str2() << "\n" << std::endl;
		break;
	}
	case json_double:
	{
		std::cout << "请输入double类型的数据。" << std::endl;
		double d;
		std::cin >> d;
		loc.setDouble(d);
		std::cout << "修改完成，修改后的结果为：" << loc.str2() << "\n" << std::endl;
		break;
	}
	case json_string:
	{
		std::cout << "请输入string类型的数据。" << std::endl;
		std::string s;
		std::getline(std::cin, s); //输入用户的字符串并准备解析
		loc.setString(s); //这样就允许用户输入的字符串有回车了
		std::cout << "修改完成，修改后的结果为：" << loc.str2() << "\n" << std::endl;
		break;
	}
	default:
		break;

	}
	std::cout << std::endl;
}

void KJson::Delete() //删
{
	std::cout << "\nPlease enter the string in the format so that you can locate the data you want to query;" << std::endl
		<< "The format of the string is: “ \"key1\" \"key2\" \"key3\"... (int)数字 \"key4\" ”  " << std::endl;

	//修改键值对的内容，注意value值不是一个object，不是一个array，而是其他的具体的值

	std::string op;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//吃掉上一个回车符，不然getline()会提前结束
	std::getline(std::cin, op); //输入用户的字符串并准备解析
	//std::cout << op << std::endl;

	std::vector<std::string> options; //每一个元素都保存一个查询的键值或者下标
	StringSplit(op, options);

	KJson& loc = visit(options, (*this)); //定位到想要作出修改的键值对的值KJson对象

	std::cout << "请输入键值对 的 键值 \"key\"" << std::endl;
	std::string s;
	std::cin >> s;
	loc.remove(s);
	std::cout << "删除操作已完成！" << std::endl;

}

void KJson::Create() //增
{
	std::cout << "\nPlease enter the string in the format so that you can locate the data you want to query;" << std::endl
		<< "The format of the string is: “ \"key1\" \"key2\" \"key3\"... (int)数字 \"key4\" ”  " << std::endl;

	//修改键值对的内容，注意value值不是一个object，不是一个array，而是其他的具体的值

	std::string op;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//吃掉上一个回车符，不然getline()会提前结束
	std::getline(std::cin, op); //输入用户的字符串并准备解析
	//std::cout << op << std::endl;

	std::vector<std::string> options; //每一个元素都保存一个查询的键值或者下标
	StringSplit(op, options);

	KJson& loc = visit(options, (*this)); //定位到想要作出修改的键值对的值KJson对象

	std::cout << "请输入键值对 的 键值 \"key\"" << std::endl;
	std::string key;
	std::cin >> key;
	int ops;
	std::cout << "请选择想要输入的值的类型：" << std::endl
		<< "输入1 ： bool" << std::endl
		<< "输入2 ： int" << std::endl
		<< "输入3 ： double" << std::endl
		<< "输入4 ： string" << std::endl;
	std::cin >> ops;

	switch (ops)
	{
	case 1:
	{
		std::cout << "请输入Bool类型的数据。" << std::endl;
		std::string b;
		std::cin >> b; //用户输入的是字符串，需要把字符串和 true\false 对比再进行赋值操作
		if (loc.has(key) == true)
		{
			std::cout << "键值已经存在，如要操作请转向修改操作。" << std::endl;
		}
		else
		{
			if (b == "true") loc[key] = true;
			else loc[key] = false;
		}
		break;
	}
	case 2:
	{
		std::cout << "请输入int类型的数据。" << std::endl;
		int ii;
		std::cin >> ii;
		if (loc.has(key) == true)
		{
			std::cout << "键值已经存在，如要操作请转向修改操作。" << std::endl;
		}
		else
		{
			loc[key] = ii;
		}
		break;
	}
	case 3:
	{
		std::cout << "请输入double类型的数据。" << std::endl;
		double d;
		std::cin >> d;
		if (loc.has(key) == true)
		{
			std::cout << "键值已经存在，如要操作请转向修改操作。" << std::endl;
		}
		else
		{
			loc[key] = d;
		}
		break;
	}
	case 4:
	{
		std::cout << "请输入string类型的数据。" << std::endl;
		std::string sv;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//吃掉上一个回车符，不然getline()会提前结束
		std::getline(std::cin, sv); //输入用户的字符串并准备解析
		if (loc.has(key) == true)
		{
			std::cout << "键值已经存在，如要操作请转向修改操作。" << std::endl;
		}
		else
		{
			loc[key] = sv;
		}
		break;
	}

	default:
		std::cout << "请选择有效的数据。" << std::endl;
		break;
	}

	std::cout << "插入操作完成。" << std::endl;

}