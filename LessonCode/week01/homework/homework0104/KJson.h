#pragma once


#include<string>
#include<vector> //json数组采用vector保存
#include<map> //对象的话表示又有键值对，使用map来保存

namespace kjsonh
{
	namespace json
	{
		class  KJson //KJson实际上记录的是键值对中的
		{
		private:
			union Value //联合体,字段的内存是公用的，由占用内存最大的类型来决定
			{
				bool m_bool;
				int m_int;
				double m_double;
				std::string* m_string;
				std::vector<KJson>* m_array;//嵌套数组
				std::map<std::string, KJson>* m_object;//嵌套对象
			};

			//对于每一个Json类，包含两个字段，一个是类型,一个是值value;

		public:
			enum Type
			{
				json_null = 0,
				json_bool,
				json_int,
				json_double,
				json_string,
				json_array,
				json_object
			};

			//基本类型转换成KJson
			//构造函数
			KJson();//默认, 默认为空值
			KJson(bool value); //支持bool类型构造，下面以此类推
			KJson(int value);
			KJson(double value);
			KJson(const char* value); //支持C风格的字符串, 加上const表示值不可修改.
			KJson(const std::string& value); //支持C++风格的字符串
			KJson(Type type);
			KJson(const KJson& other);

			Type getType() { return m_type; }
			void setType(Type type) { m_type = type; }

			//修改的是键值对，数组和类就不提供修改的接口了
			void setBool(bool value);
			bool getBool() const;

			void setInt(int value);
			int getInt() const;

			void setDouble(double value);
			double getDouble() const;

			void setString(std::string value);
			std::string getString() const;

			//希望对KJson里面的数组对象实现索引
			KJson& operator[] (int index);

			//能够通过append函数实现数组的追加
			void append(const KJson& other);

			std::string str() const;
			std::string str2() const; //加上格式输出

			//重载
			KJson& operator[](const std::string key);
			void operator = (const KJson& other); //拷贝赋值之前会把原来的清理掉(调用clear)，对于具有嵌套的数据十分不友好

			//复制函数，专门用于嵌套的数据，不会调用clear
			void Copy(const KJson& other);


			//内存释放问题
			void clear();

			//加上类型的一些判断
			//函数加上const表示函数内部，是不允许对
			bool isNull() const { return m_type == json_null; }
			bool isbool() const { return m_type == json_bool; }
			bool isint() const { return m_type == json_int; }
			bool isdouble() const { return m_type == json_double; }
			bool isstring() const { return m_type == json_string; }
			bool isarray() const { return m_type == json_array; }
			bool isobject() const { return m_type == json_object; }

			//判断数组当中有没有这个索引
			bool has(int index);

			//然后对象当中有没有这个key值
			bool has(const std::string& key);

			//删除索引为key的对象
			void remove(const std::string& key);

			void parse(const std::string& str);

			//分割字符串的函数
			void StringSplit(std::string str, std::vector<std::string>& res);

			//与用户的接口
			void QQuery(); //查
			void Update(); //改
			void Delete(); //删
			void Create(); //增



		private:
			Type m_type;//类型
			Value m_value; //值value


		};
	}
}