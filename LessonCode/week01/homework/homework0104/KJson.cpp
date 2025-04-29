#include"KJson.h"
#include"parser.h"
#include<iostream>
#include<sstream>

//ͷ�ļ��е����ƿռ��������
using namespace kjsonh::json;

//Ĭ�Ϲ��캯�����޲ι����ʱ��Ĭ��Ϊ��ֵ
KJson::KJson() :
	m_type(json_null) {}

KJson::KJson(bool value) :
	m_type(json_bool)
{
	m_value.m_bool = value; //m_value��һ��KJson�ĳ�Ա����m_value����һ�������壬ʵ�����ǽ�valueֵ���θ�m_value���е�m_bool��Ա
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

//m_string �� <string*>
KJson::KJson(const char* value) :
	m_type(json_string)
{
	m_value.m_string = new std::string(value);
	//string����char*�����ַ���
	//new()���㷵��ָ���ڴ��ָ��
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
	switch (type) // ����������ʼ��ֵ,Ĭ�϶�Ϊ��ֵ
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


//����������KJson����
//����û�б����������ʱ��ʹ�ÿ�������
KJson::KJson(const KJson& other)
{
	//��ʱKJson�����valueֵ����ȡ����Ƕ�����valueֵ����
	m_type = other.m_type;
	switch (m_type)
	{
	case json_null: break; //��ֵ��ʲôҲ����
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
		m_value.m_string = other.m_value.m_string; //ǳ������ָ�뿽��
		break;
	case json_array:
		m_value.m_array = other.m_value.m_array; //ǳ������ָ�뿽��
		break;
	case json_object:
		m_value.m_object = other.m_value.m_object; //ǳ������ָ�뿽��
		break;
	default:
		break;
	}
}



//�޸ĵ��Ǽ�ֵ�ԣ��������Ͳ��ṩ�޸ĵĽӿ���
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
	clear(); //�ͷ�ָ��ָ����ڴ�
	m_type = json_string; //��������
	m_value.m_string = new std::string(value); //���·���ռ䲢��ֵ
}

std::string KJson::getString() const
{
	return (*(m_value.m_string));
}


KJson& KJson::operator[](int index)
{
	if (m_type != json_array)
	{
		//KJson original(*this); // ����ԭʼֵ
		m_type = json_array;
		m_value.m_array = new std::vector<KJson>();
		//m_value.m_array->push_back(original);
	}

	int size = m_value.m_array->size();
	if (index < 0)
	{
		std::cout << "�����±겻�Ϸ���" << std::endl;
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

//�ܹ�ͨ��append����ʵ�������׷��
void KJson::append(const KJson& other)
{
	//���ԭ����value���Ͳ�����������

	if (m_type != json_array)
	{
		// ����ԭ�е�ֵ��һ����ʱ����
		//KJson original(*this);

		// ת����ǰ����Ϊ��������
		m_type = json_array;
		m_value.m_array = new std::vector<KJson>();

		// ��ԭʼֵ׷�ӵ�������
		//m_value.m_array->push_back(original);
		//union���������������ͣ�����ͬһ���ڴ棬�洢ָ��֮�󣬻����һ�ε����ݸ����ǵ�
	}
	(m_value.m_array)->push_back(other);
}



//���ַ����ĸ�ʽ����Json������
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




//std::map���������������operator[]��֧�ּ�ֵ����value
//����map�����е�type�ҵ�����������ֵ��������ҵ����ͷ������ֵ��Ӧ��KJson���������
//���û���ҵ���std::map�ͻ���������ֵ����һ��mapʵ����Ȼ�󷵻����ʵ����ֵ KJson
KJson& KJson::operator[](const std::string key)
{
	//���������Ͳ��Ƕ�������
	if (m_type != json_object)
	{
		clear();
		m_type = json_object;
		m_value.m_object = new std::map<std::string, KJson>();
	}

	return (*(m_value.m_object))[key];
}

//�����Ѿ��������ڴ��ʱ��ʹ�ÿ�����ֵ����
void KJson::operator = (const KJson& other)
{
	this->clear();//��������ڴ���������������ԭ����ָ��ָ��Ŀռ�����ͷŵ��������ڴ�й¶

	m_type = other.m_type;
	switch (m_type)
	{
	case json_null: break; //��ֵ��ʲôҲ����
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
		m_value.m_string = other.m_value.m_string; //ǳ������ָ�뿽��
		//m_value.m_string = new std::string(*(other.m_value.m_string));
		break;
	case json_array:
		m_value.m_array = other.m_value.m_array; //ǳ������ָ�뿽��
		break;
	case json_object:
		m_value.m_object = other.m_value.m_object; //ǳ������ָ�뿽��
		break;
	default:
		break;
	}
}



//���ƺ�����ר������Ƕ�׵����ݣ��������clear 
void KJson::Copy(const KJson& other)
{
	m_type = other.m_type;
	switch (m_type)
	{
	case json_null: break; //��ֵ��ʲôҲ����
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
		m_value.m_string = other.m_value.m_string; //ǳ������ָ�뿽��
		//m_value.m_string = new std::string(*(other.m_value.m_string));
		break;
	case json_array:
		m_value.m_array = other.m_value.m_array; //ǳ������ָ�뿽��
		break;
	case json_object:
		m_value.m_object = other.m_value.m_object; //ǳ������ָ�뿽��
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
	case json_string:delete(m_value.m_string);//�ͷ�ָ��
		//m_value.m_string = nullptr;//������������
		break;
	case json_array:
		for (auto it = (m_value.m_array)->begin(); it != (m_value.m_array)->end(); it++)
		{
			it->clear();//�ݹ�,����KJson����Ԫ��
		}
		delete(m_value.m_array);
		//m_value.m_array = nullptr;
		break;
	case json_object:
		for (auto it = (m_value.m_object)->begin(); it != (m_value.m_object)->end(); it++)
		{
			//it->clear(); //map<string, KJson>���Զ����Ա���ͣ�mapû��std::clear���䣬����KJson�������clear.
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


//�ж����鵱����û���������
bool KJson::has(int index)
{
	if (m_type != json_array)
	{
		std::cout << "�������ṩ��ȷ��array����" << std::endl;
		return false;
	}

	int size = m_value.m_array->size();
	if (index < size && index >= 0)
	{
		return true;
	}
	else return false;
}

//Ȼ���������û�����keyֵ
bool KJson::has(const std::string& key)
{
	if (m_type != json_object)
	{
		std::cout << "�������ṩ��ȷ��array����" << std::endl;
		return false;
	}
	//����map���Բ���֪�����������һ����ֵ
	return (m_value.m_object)->find(key) != (m_value.m_object)->end();
}


//ɾ������Ϊkey�Ķ���
void KJson::remove(const std::string& key)
{
	if (this->has(key) == false) //û�м�ֵΪkey��mapԪ��
	{
		std::cout << "�������ṩ��ȷ������" << std::endl;
		return;
	}
	else
	{
		//m_value.m_object->erase(key);Ҳ�п�����ɵ�����ʧЧ������
		for (auto it = (m_value.m_object)->begin(); it != (m_value.m_object)->end(); )
		{
			if (it->first == key)
			{
				it = (m_value.m_object)->erase(it); // erase ������һ����Ч�ĵ�����
			}
			else
			{
				++it;
			}
		}
	}
}


//ÿһ��KJson���󶼻���һ�������Լ��Ľ��������������õ��ĳ�ͻ
void KJson::parse(const std::string& str)
{
	Parser p;//����һ��������������ԭʼ���ַ���str
	p.load(str);

	//p.parse();���ص���һ��KJson����ĸ���Ȼ������KJson�Ŀ������㺯������ֵ ��ֵ����*this��
	*this = p.parse();

}


//���ַ����ĸ�ʽ����Json������
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


//�ָ��ַ������� Ĭ�Ϸָ��Ϊ�ո� 
void KJson::StringSplit(std::string str, std::vector<std::string>& res)
{
	int idx = 0;//����ָ�룬ָ������±�
	int size = str.size();

	while (idx < size)
	{
		std::string stmp = "";//��ʼΪ�մ�

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
	int pt = 0;//ָ��
	int size = options.size();
	KJson* pre = &top; //preָ��top���ڵ��ڴ�ռ�

	//std::cout << pre[options[pt]].str();

	KJson* now = nullptr;
	while (pt < size)
	{
		//��ֵ������ʱ����Ҫ���ǵ������������������ַ��������࣬��������ֿ�ͷ�ľ��������±�

		if (options[pt][0] >= '0' && options[pt][0] <= '9') //pre������
		{
			int n = std::stoi(options[pt]);
			now = &(*pre)[n]; //���preָ��Ŀռ���һ���������ͣ���ô�ͽ����ռ�ĵ�ַ���浽now����
		}
		else now = &(*pre)[options[pt]]; //pre��object

		//std::cout << now.str() << "********************************************\n\n\n\n\n\n";

		pt++;
		//pre = now;//ֱ�Ӹ�ֵ��ʱ������pre���ȰѶ�Ӧ���ڴ���Դ�ͷŵ�������pre����Ƕ����now,��˻����now����ָ�����յ����
		//�����Ҫ����������Ҳ�ǲ����еģ���Ϊʵ������ǳ������clear()������ʱ����ָ��ָ����ڴ���ԴҲ�ͷŵ������¸����ڵ�ָ��Ҳ��ʧЧ

		//����ֱ�Ӹ�ֵ
		pre = now;


	}

	//����ѭ����ʱ��pre = now; pt = size;

	//return *now;
	return *pre;

}






//���û������Ľӿڶ���

void KJson::QQuery() //��
{
	std::cout << "\nPlease enter the string in the format so that you can locate the data you want to query;" << std::endl
		<< "The format of the string is: �� \"key1\" \"key2\" \"key3\"... (int)���� \"key4\" ��  " << std::endl
		<< "where \"keyX\" represents the key value, which is used to access the object type;" << std::endl
		<< "(int) is an integer type that represents an index and is used to access elements in an array.\n" << std::endl;

	std::string op;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//�Ե���һ���س�������Ȼgetline()����ǰ����
	std::getline(std::cin, op); //�����û����ַ�����׼������
	//std::cout << op << std::endl;

	std::vector<std::string> options; //ÿһ��Ԫ�ض�����һ����ѯ�ļ�ֵ�����±�
	StringSplit(op, options);

	KJson loc = visit(options, (*this));

	std::cout << loc.str2() << std::endl;
}

void KJson::Update() //��
{
	std::cout << "\nPlease enter the string in the format so that you can locate the data you want to query;" << std::endl
		<< "The format of the string is: �� \"key1\" \"key2\" \"key3\"... (int)���� \"key4\" ��  " << std::endl;

	//�޸ļ�ֵ�Ե����ݣ�ע��valueֵ����һ��object������һ��array�����������ľ����ֵ

	std::string op;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//�Ե���һ���س�������Ȼgetline()����ǰ����
	std::getline(std::cin, op); //�����û����ַ�����׼������
	//std::cout << op << std::endl;

	std::vector<std::string> options; //ÿһ��Ԫ�ض�����һ����ѯ�ļ�ֵ�����±�
	StringSplit(op, options);

	KJson& loc = visit(options, (*this)); //��λ����Ҫ�����޸ĵļ�ֵ�Ե�ֵKJson����

	switch (loc.getType())
	{
	case json_null:
	{
		std::cout << "��ֵ�����޸ģ�" << std::endl;
		break;
	}
	case json_bool:
	{
		std::cout << "������Bool���͵����ݡ�" << std::endl;
		bool b;
		std::cin >> b;
		loc.setBool(b);
		std::cout << "�޸���ɣ��޸ĺ�Ľ��Ϊ��" << loc.str2() << "\n" << std::endl;
		break;
	}
	case json_int:
	{
		std::cout << "������int���͵����ݡ�" << std::endl;
		int ii;
		std::cin >> ii;
		loc.setInt(ii);
		std::cout << "�޸���ɣ��޸ĺ�Ľ��Ϊ��" << loc.str2() << "\n" << std::endl;
		break;
	}
	case json_double:
	{
		std::cout << "������double���͵����ݡ�" << std::endl;
		double d;
		std::cin >> d;
		loc.setDouble(d);
		std::cout << "�޸���ɣ��޸ĺ�Ľ��Ϊ��" << loc.str2() << "\n" << std::endl;
		break;
	}
	case json_string:
	{
		std::cout << "������string���͵����ݡ�" << std::endl;
		std::string s;
		std::getline(std::cin, s); //�����û����ַ�����׼������
		loc.setString(s); //�����������û�������ַ����лس���
		std::cout << "�޸���ɣ��޸ĺ�Ľ��Ϊ��" << loc.str2() << "\n" << std::endl;
		break;
	}
	default:
		break;

	}
	std::cout << std::endl;
}

void KJson::Delete() //ɾ
{
	std::cout << "\nPlease enter the string in the format so that you can locate the data you want to query;" << std::endl
		<< "The format of the string is: �� \"key1\" \"key2\" \"key3\"... (int)���� \"key4\" ��  " << std::endl;

	//�޸ļ�ֵ�Ե����ݣ�ע��valueֵ����һ��object������һ��array�����������ľ����ֵ

	std::string op;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//�Ե���һ���س�������Ȼgetline()����ǰ����
	std::getline(std::cin, op); //�����û����ַ�����׼������
	//std::cout << op << std::endl;

	std::vector<std::string> options; //ÿһ��Ԫ�ض�����һ����ѯ�ļ�ֵ�����±�
	StringSplit(op, options);

	KJson& loc = visit(options, (*this)); //��λ����Ҫ�����޸ĵļ�ֵ�Ե�ֵKJson����

	std::cout << "�������ֵ�� �� ��ֵ \"key\"" << std::endl;
	std::string s;
	std::cin >> s;
	loc.remove(s);
	std::cout << "ɾ����������ɣ�" << std::endl;

}

void KJson::Create() //��
{
	std::cout << "\nPlease enter the string in the format so that you can locate the data you want to query;" << std::endl
		<< "The format of the string is: �� \"key1\" \"key2\" \"key3\"... (int)���� \"key4\" ��  " << std::endl;

	//�޸ļ�ֵ�Ե����ݣ�ע��valueֵ����һ��object������һ��array�����������ľ����ֵ

	std::string op;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//�Ե���һ���س�������Ȼgetline()����ǰ����
	std::getline(std::cin, op); //�����û����ַ�����׼������
	//std::cout << op << std::endl;

	std::vector<std::string> options; //ÿһ��Ԫ�ض�����һ����ѯ�ļ�ֵ�����±�
	StringSplit(op, options);

	KJson& loc = visit(options, (*this)); //��λ����Ҫ�����޸ĵļ�ֵ�Ե�ֵKJson����

	std::cout << "�������ֵ�� �� ��ֵ \"key\"" << std::endl;
	std::string key;
	std::cin >> key;
	int ops;
	std::cout << "��ѡ����Ҫ�����ֵ�����ͣ�" << std::endl
		<< "����1 �� bool" << std::endl
		<< "����2 �� int" << std::endl
		<< "����3 �� double" << std::endl
		<< "����4 �� string" << std::endl;
	std::cin >> ops;

	switch (ops)
	{
	case 1:
	{
		std::cout << "������Bool���͵����ݡ�" << std::endl;
		std::string b;
		std::cin >> b; //�û���������ַ�������Ҫ���ַ����� true\false �Ա��ٽ��и�ֵ����
		if (loc.has(key) == true)
		{
			std::cout << "��ֵ�Ѿ����ڣ���Ҫ������ת���޸Ĳ�����" << std::endl;
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
		std::cout << "������int���͵����ݡ�" << std::endl;
		int ii;
		std::cin >> ii;
		if (loc.has(key) == true)
		{
			std::cout << "��ֵ�Ѿ����ڣ���Ҫ������ת���޸Ĳ�����" << std::endl;
		}
		else
		{
			loc[key] = ii;
		}
		break;
	}
	case 3:
	{
		std::cout << "������double���͵����ݡ�" << std::endl;
		double d;
		std::cin >> d;
		if (loc.has(key) == true)
		{
			std::cout << "��ֵ�Ѿ����ڣ���Ҫ������ת���޸Ĳ�����" << std::endl;
		}
		else
		{
			loc[key] = d;
		}
		break;
	}
	case 4:
	{
		std::cout << "������string���͵����ݡ�" << std::endl;
		std::string sv;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//�Ե���һ���س�������Ȼgetline()����ǰ����
		std::getline(std::cin, sv); //�����û����ַ�����׼������
		if (loc.has(key) == true)
		{
			std::cout << "��ֵ�Ѿ����ڣ���Ҫ������ת���޸Ĳ�����" << std::endl;
		}
		else
		{
			loc[key] = sv;
		}
		break;
	}

	default:
		std::cout << "��ѡ����Ч�����ݡ�" << std::endl;
		break;
	}

	std::cout << "���������ɡ�" << std::endl;

}