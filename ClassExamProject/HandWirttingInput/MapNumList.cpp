# pragma execution_character_set("utf-8")

#include "MapNumList.h" 

MapNumList::MapNumList(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	// 设置背景颜色为白色
	this->setStyleSheet("background-color: rgb(250, 250, 250); ");

	//不启用Qt::WA_StyledBackground属性就无法应用QSS的背景样式
	this->setAttribute(Qt::WA_StyledBackground);  //Qt::WA_StyledBackground 是一个属性，当设置为 true 时，Qt 将使用样式表来绘制控件的背景。

	// 移动窗口
	this->move(300, 450);
	this->setFixedSize(550, 400);

	//添加按钮，其实按道理来说，可以使用for循环，但是里面每一个按钮的文本都不一样
	//可以使用QsignalMap来统一管理

	//首先使用buttonTexts存储每一个按钮的文本信息
	QStringList buttonTexts;
	buttonTexts << "0" << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9"
		<< "零" << "壹" << "贰" << "叁" << "肆" << "伍" << "陆" << "柒" << "捌" << "玖";
		

	//在当前QWidget里面添加网格布局管理器
	numplay = new QGridLayout(this); //父布局是this

	//创建Map 
	signalMapper = new QSignalMapper(this);

	for (int i = 0; i < buttonTexts.size(); i++)
	{
		QPushButton* btn = new QPushButton(buttonTexts[i]);
		connect(btn, SIGNAL(clicked()), signalMapper, SLOT(map()));  //将每个按钮的 clicked() 信号连接到 QSignalMapper 的 map() 槽函数
		signalMapper->setMapping(btn, buttonTexts[i]);
		numplay->addWidget(btn, i / 5, i % 5, 1, 1);
	}

	//信号连接信号， 信号转发
	connect(signalMapper, SIGNAL(mapped(const QString&)), this, SIGNAL(doclicked(const QString&)));

	//测试链接
	connect(signalMapper, SIGNAL(mapped(const QString&)), this, SLOT(Maptest(const QString&)));

	//子窗口和父窗口链接 
	QObject::connect(this, SIGNAL(doclicked(const QString&)), this->parent(), SLOT(inputNumButton(QString)));

	//布置布局
	this->setLayout(numplay);


}

MapNumList::~MapNumList()
{
	delete numplay;
	delete signalMapper;
}
