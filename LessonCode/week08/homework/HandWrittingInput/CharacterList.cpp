# pragma execution_character_set("utf-8")

#include "CharacterList.h"

//首先编写字符串界面，然后在主界面创建一个界面实例

 
//字符界面构造函数
CharacterList::CharacterList(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);


	// 设置背景颜色为白色
	this->setStyleSheet("background-color: white;");
	
	//不启用Qt::WA_StyledBackground属性就无法应用QSS的背景样式
	this->setAttribute(Qt::WA_StyledBackground);  //Qt::WA_StyledBackground 是一个属性，当设置为 true 时，Qt 将使用样式表来绘制控件的背景。

	// 移动窗口
	this->move(300, 250);
	this->setFixedSize(550, 400);


	//在当前QWidget里面添加网格布局管理器
	QGridLayout* charplay = new QGridLayout(this); //父布局是this

	//添加按钮，其实按道理来说，可以使用for循环，但是里面每一个按钮的文本都不一样，还是不能使用for
	//btni_j : 布局在(i，j)的按钮
	//QPushButton* btn0_0 = new QPushButton(QString::fromUtf8("，"));  //布局在(0，0)的按钮,文本是“，”
	QPushButton* btn0_0 = new QPushButton("，");
	QPushButton* btn0_1 = new QPushButton("。");
	QPushButton* btn0_2 = new QPushButton("、");
	QPushButton* btn0_3 = new QPushButton("；");
	QPushButton* btn0_4 = new QPushButton("：");
	QPushButton* btn0_5 = new QPushButton("？");
	QPushButton* btn0_6 = new QPushButton("！");
	QPushButton* btn0_7 = new QPushButton("·");
	QPushButton* btn0_8 = new QPushButton("···");

	QPushButton* btn1_0 = new QPushButton("——");
	QPushButton* btn1_1 = new QPushButton("~");
	QPushButton* btn1_2 = new QPushButton("‘’");
	QPushButton* btn1_3 = new QPushButton("“”");
	QPushButton* btn1_4 = new QPushButton("/");
	QPushButton* btn1_5 = new QPushButton("\\");
	QPushButton* btn1_6 = new QPushButton("_");
	QPushButton* btn1_7 = new QPushButton("··");
	QPushButton* btn1_8 = new QPushButton("--");

	QPushButton* btn2_0 = new QPushButton(",");
	QPushButton* btn2_1 = new QPushButton(".");
	QPushButton* btn2_2 = new QPushButton("''");
	QPushButton* btn2_3 = new QPushButton("\"\"");
	QPushButton* btn2_4 = new QPushButton("?");
	QPushButton* btn2_5 = new QPushButton("!");
	QPushButton* btn2_6 = new QPushButton("`");
	QPushButton* btn2_7 = new QPushButton("+");
	QPushButton* btn2_8 = new QPushButton("-");

	QPushButton* btn3_0 = new QPushButton("@");
	QPushButton* btn3_1 = new QPushButton("#");
	QPushButton* btn3_2 = new QPushButton("$");
	QPushButton* btn3_3 = new QPushButton("￥");
	QPushButton* btn3_4 = new QPushButton("^");
	QPushButton* btn3_5 = new QPushButton("&&"); //显示实际的 "&" 符号，需要对 "&" 进行转义。
	QPushButton* btn3_6 = new QPushButton("*");
	QPushButton* btn3_7 = new QPushButton("()");
	QPushButton* btn3_8 = new QPushButton("[]");

	QPushButton* btn4_0 = new QPushButton("{}");
	QPushButton* btn4_1 = new QPushButton("<>");
	QPushButton* btn4_2 = new QPushButton("|");
	QPushButton* btn4_3 = new QPushButton("%");
	QPushButton* btn4_4 = new QPushButton(";");
	QPushButton* btn4_5 = new QPushButton("℃");
	QPushButton* btn4_6 = new QPushButton("⟪⟫");
	QPushButton* btn4_7 = new QPushButton("→");
	QPushButton* btn4_8 = new QPushButton("←");

	charplay->addWidget(btn0_0, 0, 0, 1, 1);
	charplay->addWidget(btn0_1, 0, 1, 1, 1);
	charplay->addWidget(btn0_2, 0, 2, 1, 1);
	charplay->addWidget(btn0_3, 0, 3, 1, 1);
	charplay->addWidget(btn0_4, 0, 4, 1, 1);
	charplay->addWidget(btn0_5, 0, 5, 1, 1);
	charplay->addWidget(btn0_6, 0, 6, 1, 1);
	charplay->addWidget(btn0_7, 0, 7, 1, 1);
	charplay->addWidget(btn0_8, 0, 8, 1, 1);

	charplay->addWidget(btn1_0, 1, 0, 1, 1);
	charplay->addWidget(btn1_1, 1, 1, 1, 1);
	charplay->addWidget(btn1_2, 1, 2, 1, 1);
	charplay->addWidget(btn1_3, 1, 3, 1, 1);
	charplay->addWidget(btn1_4, 1, 4, 1, 1);
	charplay->addWidget(btn1_5, 1, 5, 1, 1);
	charplay->addWidget(btn1_6, 1, 6, 1, 1);
	charplay->addWidget(btn1_7, 1, 7, 1, 1);
	charplay->addWidget(btn1_8, 1, 8, 1, 1);

	charplay->addWidget(btn2_0, 2, 0, 1, 1);
	charplay->addWidget(btn2_1, 2, 1, 1, 1);
	charplay->addWidget(btn2_2, 2, 2, 1, 1);
	charplay->addWidget(btn2_3, 2, 3, 1, 1);
	charplay->addWidget(btn2_4, 2, 4, 1, 1);
	charplay->addWidget(btn2_5, 2, 5, 1, 1);
	charplay->addWidget(btn2_6, 2, 6, 1, 1);
	charplay->addWidget(btn2_7, 2, 7, 1, 1);
	charplay->addWidget(btn2_8, 2, 8, 1, 1);

	charplay->addWidget(btn3_0, 3, 0, 1, 1);
	charplay->addWidget(btn3_1, 3, 1, 1, 1);
	charplay->addWidget(btn3_2, 3, 2, 1, 1);
	charplay->addWidget(btn3_3, 3, 3, 1, 1);
	charplay->addWidget(btn3_4, 3, 4, 1, 1);
	charplay->addWidget(btn3_5, 3, 5, 1, 1);
	charplay->addWidget(btn3_6, 3, 6, 1, 1);
	charplay->addWidget(btn3_7, 3, 7, 1, 1);
	charplay->addWidget(btn3_8, 3, 8, 1, 1);

	charplay->addWidget(btn4_0, 4, 0, 1, 1);
	charplay->addWidget(btn4_1, 4, 1, 1, 1);
	charplay->addWidget(btn4_2, 4, 2, 1, 1);
	charplay->addWidget(btn4_3, 4, 3, 1, 1);
	charplay->addWidget(btn4_4, 4, 4, 1, 1);
	charplay->addWidget(btn4_5, 4, 5, 1, 1);
	charplay->addWidget(btn4_6, 4, 6, 1, 1);
	charplay->addWidget(btn4_7, 4, 7, 1, 1);
	charplay->addWidget(btn4_8, 4, 8, 1, 1);


	//为当前窗口安装布局
	this->setLayout(charplay);

}

CharacterList::~CharacterList()
{}
