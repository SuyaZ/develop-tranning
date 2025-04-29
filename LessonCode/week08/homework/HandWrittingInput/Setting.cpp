# pragma execution_character_set("utf-8")

#include "Setting.h"
 
Setting::Setting(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	// 设置背景颜色为白色
	this->setStyleSheet("background-color: rgb(250, 250, 250); ");

	//不启用Qt::WA_StyledBackground属性就无法应用QSS的背景样式
	this->setAttribute(Qt::WA_StyledBackground);

	this->move(150, 180);
	this->setFixedSize(540, 490);

	setplay = new QGridLayout(this);

	color = new QLabel("墨 迹 颜 色");
	width = new QLabel("墨 迹 粗 细");
	size = new QLabel("候 选 字 号");
	padding = new QLabel("");

	// 创建按钮并设置样式
	QPushButton* btnblack = new QPushButton("黑");
	btnblack->setStyleSheet("QPushButton { color: white; background-color: black; }");

	QPushButton* btnred = new QPushButton("红");
	btnred->setStyleSheet("QPushButton { color: white; background-color: red; }");

	QPushButton* btnyellow = new QPushButton("黄");
	btnyellow->setStyleSheet("QPushButton { color: white; background-color: yellow; }");

	QPushButton* btnblue = new QPushButton("蓝");
	btnblue->setStyleSheet("QPushButton { color: white; background-color: blue; }");

	QPushButton* btngreen = new QPushButton("绿");
	btngreen->setStyleSheet("QPushButton { color: white; background-color: green; }");

	QPushButton* btnpurple = new QPushButton("紫");
	btnpurple->setStyleSheet("QPushButton { color: white; background-color: purple; }");

	//每10个像素作为一个单位递增
	btn1 = new QPushButton("1");
	btn2 = new QPushButton("2");
	btn3 = new QPushButton("3");
	btn4 = new QPushButton("4");
	btn5 = new QPushButton("5");
	btn6 = new QPushButton("6");

	btn10 = new QPushButton("1");
	btn15 = new QPushButton("2");
	btn20 = new QPushButton("3");
	btn25 = new QPushButton("4");
	btn30 = new QPushButton("5");
	btn35 = new QPushButton("6");

	reSetbtn = new QPushButton("恢复默认设置");
	reSetbtn->setStyleSheet("QPushButton { background-color: rgb(229, 255, 255)}");
	reSetbtn->setStyleSheet("QPushButton { background-color: hsl(180, 100%, 95%); }");


	setplay->addWidget(color, 0, 0, 1, 3);

	setplay->addWidget(btnblack, 1, 0, 1, 1);
	setplay->addWidget(btnred, 1, 1, 1, 1);
	setplay->addWidget(btnyellow, 1, 2, 1, 1);
	setplay->addWidget(btnblue, 1, 3, 1, 1);
	setplay->addWidget(btngreen, 1, 4, 1, 1);
	setplay->addWidget(btnpurple, 1, 5, 1, 1);


	setplay->addWidget(width, 2, 0, 1, 3);

	setplay->addWidget(btn1, 3, 0, 1, 1);
	setplay->addWidget(btn2, 3, 1, 1, 1);
	setplay->addWidget(btn3, 3, 2, 1, 1);
	setplay->addWidget(btn4, 3, 3, 1, 1);
	setplay->addWidget(btn5, 3, 4, 1, 1);
	setplay->addWidget(btn6, 3, 5, 1, 1);


	setplay->addWidget(size, 4, 0, 1, 3);

	setplay->addWidget(btn10, 5, 0, 1, 1);
	setplay->addWidget(btn15, 5, 1, 1, 1);
	setplay->addWidget(btn20, 5, 2, 1, 1);
	setplay->addWidget(btn25, 5, 3, 1, 1);
	setplay->addWidget(btn30, 5, 4, 1, 1);
	setplay->addWidget(btn35, 5, 5, 1, 1);

	setplay->addWidget(padding, 6, 0, 1, 3);
	setplay->addWidget(reSetbtn, 7, 0, 1, 3);


	bool bug = false;
	//按下按钮，向主窗口发出信号
	bug = QObject::connect(btnred, &QPushButton::clicked, this, &Setting::btnredclicked);
	if (bug == false)
	{
		qDebug() << "QObject::connect(btnred, &QPushButton::clicked, this, &Setting::btnredclicked);";
	}
	QObject::connect(btnblack, &QPushButton::clicked, this, &Setting::btnblackclicked);
	QObject::connect(btnyellow, &QPushButton::clicked, this, &Setting::btnyellowclicked);
	QObject::connect(btnblue, &QPushButton::clicked, this, &Setting::btnblueclicked);
	QObject::connect(btngreen, &QPushButton::clicked, this, &Setting::btngreenclicked);
	QObject::connect(btnpurple, &QPushButton::clicked, this, &Setting::btnpurpleclicked);


	QObject::connect(btn1, &QPushButton::clicked, this, &Setting::btn1clicked);
	QObject::connect(btn2, &QPushButton::clicked, this, &Setting::btn2clicked);
	QObject::connect(btn3, &QPushButton::clicked, this, &Setting::btn3clicked);
	QObject::connect(btn4, &QPushButton::clicked, this, &Setting::btn4clicked);
	QObject::connect(btn5, &QPushButton::clicked, this, &Setting::btn5clicked);
	QObject::connect(btn6, &QPushButton::clicked, this, &Setting::btn6clicked);


	QObject::connect(btn10, &QPushButton::clicked, this, &Setting::btn10clicked);
	QObject::connect(btn15, &QPushButton::clicked, this, &Setting::btn15clicked);
	QObject::connect(btn20, &QPushButton::clicked, this, &Setting::btn20clicked);
	QObject::connect(btn25, &QPushButton::clicked, this, &Setting::btn25clicked);
	QObject::connect(btn30, &QPushButton::clicked, this, &Setting::btn30clicked);
	QObject::connect(btn35, &QPushButton::clicked, this, &Setting::btn35clicked);

	
	QObject::connect(reSetbtn, &QPushButton::clicked, this, &Setting::reSetBtnclicked);

}

Setting::~Setting()
{
	delete setplay;
}
