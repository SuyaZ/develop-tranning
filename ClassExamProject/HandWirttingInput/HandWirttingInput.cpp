# pragma execution_character_set("utf-8")

#include "HandWirttingInput.h" 

//窗口构造函数，用于初始化布局以及组件
HandWirttingInput::HandWirttingInput(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    this->resize(1400, 590); // 设置窗口的初始大小
    this->setWindowTitle("Handwriting Input"); // 设置窗口标题
    //this->setStyleSheet("background-color: rgb(196, 255, 238);");



    // 在 QMainWindow 的构造函数中
    centralWidget = new QWidget(this); // 创建中心部件作为容器
    this->setCentralWidget(centralWidget); // 设置为中心部件

    //设置中心布局 网格布局
    centralplay = new QGridLayout;
    centralplay->setRowMinimumHeight(0, 50);
    centralplay->setRowMinimumHeight(1, 100);
    centralplay->setRowMinimumHeight(2, 500);
    centralplay->setColumnMinimumWidth(0, 140);
    centralplay->setColumnMinimumWidth(1, 700);
    centralplay->setColumnMinimumWidth(2, 270);

    //设置子部件之间的垂直间隔
    centralplay->setVerticalSpacing(10);
    centralplay->setHorizontalSpacing(10);

    // 设置拉伸因子，让第二列和第三列在窗口变大时拉伸
    centralplay->setColumnStretch(0, 0); // 第一列不拉伸
    centralplay->setColumnStretch(1, 2); // 第二列拉伸
    centralplay->setColumnStretch(2, 1); // 第三列拉伸


    QSizePolicy policy = QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);



    //_______________________________________________________________________
    // 创建QTextEdit对象
    textEdit = new QTextEdit(centralWidget); //堆区 父对象是中心组件
    //textEdit->setGeometry(10, 10, 880, 50); // 设置QTextEdit的位置和大小
    //设置文本格式
    textEdit->setFontPointSize(16);
    textEdit->setTextColor(Qt::blue);

    centralplay->addWidget(textEdit, 0, 0, 1, 3);
    textEdit->setSizePolicy(policy);


    //_______________________________________________________________________
    SugContainer = new QWidget;
    Sugplay = new QHBoxLayout(SugContainer);

    Sugbtn1 = new QPushButton("");
    Sugbtn2 = new QPushButton("");
    Sugbtn3 = new QPushButton("");
    Sugbtn4 = new QPushButton("");

    Sugplay->addWidget(Sugbtn1);
    Sugplay->addWidget(Sugbtn2);
    Sugplay->addWidget(Sugbtn3);
    Sugplay->addWidget(Sugbtn4);

    Sugbtn1->setSizePolicy(policy);
    Sugbtn2->setSizePolicy(policy);
    Sugbtn3->setSizePolicy(policy);
    Sugbtn4->setSizePolicy(policy);


    centralplay->addWidget(SugContainer, 1, 0, 1, 3);


    //分别设计左、中、右三块布局

    //———————————————————————————————— 左 ——————————————————————————————————————

    //在MainWindow里面创建QWidget容器管理布局
    leftContainer = new QWidget;
    centralplay->addWidget(leftContainer, 2, 0, 1, 1); //容器添加到布局当中

    //创建最左边的 垂直布局
    leftplay = new QVBoxLayout(leftContainer); 

    //添加组件
    contrlBtn = new QPushButton("设  置");  //设置单字手写按钮
    singleRecBtn = new QPushButton("单字手写");  //设置单字手写按钮
    multipRecBtn = new QPushButton("多字手写");  //设置多字手写按钮

    multipRecBtn->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255)}");
    singleRecBtn->setStyleSheet("QPushButton { background-color: rgb(229, 255, 255)}");
    singleRecBtn->setStyleSheet("QPushButton { background-color: hsl(180, 100%, 95%); }");

    eraseBtn = new QPushButton("退一笔");  //设置退一笔按钮
    rewriteBtn = new QPushButton("重  写");  //设置重写按钮

    //按钮大小调整
    contrlBtn->setFixedSize(120, 90);
    singleRecBtn->setFixedSize(120, 90); // 设置按钮的宽度为140像素，高度为50像素
    multipRecBtn->setFixedSize(120, 90);
    eraseBtn->setFixedSize(120, 90);
    rewriteBtn->setFixedSize(120, 90);

    leftplay->addWidget(contrlBtn);
    leftplay->addSpacing(100);
    leftplay->addWidget(singleRecBtn);
    leftplay->addSpacing(20);
    leftplay->addWidget(multipRecBtn);
    leftplay->addSpacing(100);
    leftplay->addWidget(eraseBtn);
    leftplay->addSpacing(20);
    leftplay->addWidget(rewriteBtn);


    //———————————————————————————————— 中 ——————————————————————————————————————
    // 
    //在MainWindow里面创建QWidget容器管理布局
    midContainer = new QWidget;
    centralplay->addWidget(midContainer, 2, 1, 1, 1); //容器添加到布局当中

    //创建中间的 垂直布局
    midplay = new QVBoxLayout(midContainer);

    // 添加组件
    writeZone = new QLabel(midContainer);
    //writeZone->setAlignment(Qt::AlignCenter); // 文本居中对齐
    writeZone->setStyleSheet("QLabel { background-color : white; }"); // 设置背景颜色

    midplay->addWidget(writeZone);


    //———————————————————————————————— 右 ——————————————————————————————————————
    // 
    //在MainWindow里面创建QWidget容器管理布局
    rightContainer = new QWidget;
    centralplay->addWidget(rightContainer, 2, 2, 1, 1); //容器添加到布局当中

    //网格布局
    rightplay = new QGridLayout(rightContainer);

    // 添加组件
    btn1 = new QPushButton(""); //识别之前默认候选栏都是空值
    btn2 = new QPushButton("");
    btn3 = new QPushButton("");
    btn4 = new QPushButton("");
    btn5 = new QPushButton("");

    //设置候选字默认字号
    QFont font("宋体", 10);
    btn1->setFont(font);
    btn2->setFont(font);
    btn3->setFont(font);
    btn4->setFont(font);
    btn5->setFont(font);



    charBtn = new QPushButton(",!/.");
    numBtn = new QPushButton("123");
    EnBtn = new QPushButton("ENG");

    //默认是CN模式，改变按钮的状态，伪状态
    CnBtn = new QPushButton("CN");
    CnBtn->setStyleSheet("QPushButton { background-color: rgb(229, 255, 255)}");
    CnBtn->setStyleSheet("QPushButton { background-color: hsl(180, 100%, 95%); }");


    rightplay->addWidget(btn1, 0, 0, 4, 4);
    rightplay->addWidget(btn2, 4, 0, 2, 2);
    rightplay->addWidget(btn3, 4, 2, 2, 2);
    rightplay->addWidget(btn4, 6, 0, 2, 2);
    rightplay->addWidget(btn5, 6, 2, 2, 2);

    rightplay->addWidget(charBtn, 8, 0, 1, 1);
    rightplay->addWidget(numBtn, 8, 1, 1, 1);
    rightplay->addWidget(EnBtn, 8, 2, 1, 1);
    rightplay->addWidget(CnBtn, 8, 3, 1, 1);


    // 设置按钮的尺寸策略为 Expanding
    btn1->setSizePolicy(policy);
    btn2->setSizePolicy(policy);
    btn3->setSizePolicy(policy);
    btn4->setSizePolicy(policy);
    btn5->setSizePolicy(policy);
    charBtn->setSizePolicy(policy);
    numBtn->setSizePolicy(policy);
    EnBtn->setSizePolicy(policy);
    CnBtn->setSizePolicy(policy);

    // 设置行和列的拉伸因子
    rightplay->setRowStretch(0, 1);
    rightplay->setRowStretch(1, 1);
    rightplay->setRowStretch(2, 1);
    rightplay->setRowStretch(3, 1);
    rightplay->setRowStretch(4, 1);
    rightplay->setRowStretch(5, 1);
    rightplay->setRowStretch(6, 1);
    rightplay->setRowStretch(7, 1);
    rightplay->setRowStretch(8, 1);

    for (int i = 0; i < 4; ++i) 
    {
        rightplay->setColumnStretch(i, 1);
    }


    //为当前窗口安装布局
    centralWidget->setLayout(centralplay);


    //———————————————————————————————— 设置事件过滤器 ——————————————————————————————————————
    writeZone->installEventFilter(this); 
    writeZone->setMouseTracking(true); //开启鼠标追踪器，持续接收鼠标移动事件


    //———————————————————————————————— 槽链接 ——————————————————————————————————————
    QObject::connect(charBtn, &QPushButton::clicked, this, &HandWirttingInput::open_closeCharacterList);
    QObject::connect(numBtn, &QPushButton::clicked, this, &HandWirttingInput::open_closeNumberList);
    QObject::connect(EnBtn, &QPushButton::clicked, this, &HandWirttingInput::open_closeEngList);

    bool bug2 = false;
    bug2 = QObject::connect(contrlBtn, &QPushButton::clicked, this, &HandWirttingInput::open_closeSetting);
    if (bug2 == false)
    {
        qDebug() << "QObject::connect(setting, &Setting::btnredclicked, this, &HandWirttingInput::setRed);";
    }
    
    //链接时子窗口并未完成创建，是无效链接，应该在子窗口创建实例之后链接
    //QObject::connect(this->chaListWindow, SIGNAL(MapCharList::itemclicked(QString)), this, SLOT(HandWirttingInput::inputButton(QString)));
    

    //WriteZone响应鼠标释放事件
    QObject::connect(this, &HandWirttingInput::MouseRelease, this, &HandWirttingInput::mouseReleaseEvent);


    //重写按钮
    QObject::connect(rewriteBtn, &QPushButton::clicked, this, &HandWirttingInput::btnClearClicked);

    //退一笔按钮
    QObject::connect(eraseBtn, &QPushButton::clicked, &inputs, &HansInput::clearNew);
    //更新识别
    QObject::connect(&inputs, &HansInput::deleteLast, this, &HandWirttingInput::deltUpdate);


    //候选字按钮被按下
    QObject::connect(btn1, &QPushButton::clicked, this, &HandWirttingInput::btn1Clicked);
    QObject::connect(btn2, &QPushButton::clicked, this, &HandWirttingInput::btn2Clicked);
    QObject::connect(btn3, &QPushButton::clicked, this, &HandWirttingInput::btn3Clicked);
    QObject::connect(btn4, &QPushButton::clicked, this, &HandWirttingInput::btn4Clicked);
    QObject::connect(btn5, &QPushButton::clicked, this, &HandWirttingInput::btn5Clicked);


    //按下“多字识别”按钮，开启多字识别模式
    QObject::connect(multipRecBtn, &QPushButton::clicked, this, &HandWirttingInput::mulpattern);
    //开启单字识别模式
    QObject::connect(singleRecBtn, &QPushButton::clicked, this, &HandWirttingInput::sigpattern);


    //联想识别
    QObject::connect(this, &HandWirttingInput::ReadySuggest, this, &HandWirttingInput::ReadySuggestEvent);
    QObject::connect(&httpRequestManager, &HttpRequestManager::requestFinished, &httpReplyHandler, &HttpReplyHandler::onHandleHttpReply);
    //联想词结果成功返回后
    QObject::connect(this, &HandWirttingInput::UpdateSuggestions, this, &HandWirttingInput::fun_UpdateSuggestions);
    //联想词按钮槽链接
    QObject::connect(Sugbtn1, &QPushButton::clicked, this, &HandWirttingInput::Sugbtn1Clicked);
    QObject::connect(Sugbtn2, &QPushButton::clicked, this, &HandWirttingInput::Sugbtn2Clicked);
    QObject::connect(Sugbtn3, &QPushButton::clicked, this, &HandWirttingInput::Sugbtn3Clicked);
    QObject::connect(Sugbtn4, &QPushButton::clicked, this, &HandWirttingInput::Sugbtn4Clicked);



    //______________________ 识别器初始化 _________________________
    WId hshow = writeZone->winId();
    inputs.inputInit((HWND)hshow);


    //--------------------- 鼠标箭头移动到writeZone之后，就会变成十字光标 ---------   //这是一个问题，还没有解决，先搁置
    //QPixmap bitmap01("./cursor01.png");
    ////QPixmap bitmap_mask01("./cursor01.png");

    //QCursor cursor(bitmap01, bitmap01, -1, -1); //-1 -1表示鼠标热点在中心点

    //this->setCursor(Qt::ArrowCursor);

    //// 设置光标为自定义样式
    //writeZone->setCursor(Qt::ArrowCursor);


}

HandWirttingInput::~HandWirttingInput()
{
    if (chaListWindow != nullptr) //已经分配了内存
    {
        delete chaListWindow;
    }
    if (numListWindow != nullptr) //已经分配了内存
    {
        delete numListWindow;
    }
    if (engListWindow != nullptr) //已经分配了内存
    {
        delete engListWindow;
    }
    if (setting != nullptr)
    {
        delete setting;
    }

    delete centralWidget;
}


//处理字符按钮
void HandWirttingInput::open_closeCharacterList() //单击打开窗口，再次点击关闭窗口
{
    if (chaListWindow == nullptr)
    {
        chaListWindow = new MapCharList(this); //设置子窗口的父对象是this

        chaListWindow->show();
        this->charBtn->setText("关闭窗口");
        CnBtn->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255)}");
        
        charBtn->setStyleSheet("QPushButton { background-color: rgb(229, 255, 255)}");
        charBtn->setStyleSheet("QPushButton { background-color: hsl(180, 100%, 95%); }");
    }
    else
    {
        if (chaListWindow->isVisible()) 
        {
            chaListWindow->hide();  // 隐藏窗口
            this->charBtn->setText(",!/.");
            charBtn->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255)}");
 
            CnBtn->setStyleSheet("QPushButton { background-color: rgb(229, 255, 255)}");
            CnBtn->setStyleSheet("QPushButton { background-color: hsl(180, 100%, 95%); }");
        }
        else 
        {
            chaListWindow->show();  // 显示窗口
            this->charBtn->setText("关闭窗口");
            CnBtn->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255)}");

            charBtn->setStyleSheet("QPushButton { background-color: rgb(229, 255, 255)}");
            charBtn->setStyleSheet("QPushButton { background-color: hsl(180, 100%, 95%); }");
        }
    }


}


//处理数字按钮
void HandWirttingInput::open_closeNumberList() //单击打开窗口，再次点击关闭窗口
{
    if (numListWindow == nullptr)
    {
        numListWindow = new MapNumList(this); //设置子窗口的父对象是this

        numListWindow->show();
        this->numBtn->setText("关闭窗口");
        CnBtn->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255)}");

        numBtn->setStyleSheet("QPushButton { background-color: rgb(229, 255, 255)}");
        numBtn->setStyleSheet("QPushButton { background-color: hsl(180, 100%, 95%); }");
    }
    else
    {
        if (numListWindow->isVisible())
        {
            numListWindow->hide();  // 隐藏窗口
            this->numBtn->setText("123");
            numBtn->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255)}");

            CnBtn->setStyleSheet("QPushButton { background-color: rgb(229, 255, 255)}");
            CnBtn->setStyleSheet("QPushButton { background-color: hsl(180, 100%, 95%); }");
        }
        else
        {
            numListWindow->show();  // 显示窗口
            this->numBtn->setText("关闭窗口");
            CnBtn->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255)}");

            numBtn->setStyleSheet("QPushButton { background-color: rgb(229, 255, 255)}");
            numBtn->setStyleSheet("QPushButton { background-color: hsl(180, 100%, 95%); }");
        }
    }


}

//处理字母按钮
void HandWirttingInput::open_closeEngList() //单击打开窗口，再次点击关闭窗口
{
    if (engListWindow == nullptr)
    {
        engListWindow = new MapEngList(this); //设置子窗口的父对象是this

        engListWindow->show();
        this->EnBtn->setText("关闭窗口");
        CnBtn->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255)}");

        EnBtn->setStyleSheet("QPushButton { background-color: rgb(229, 255, 255)}");
        EnBtn->setStyleSheet("QPushButton { background-color: hsl(180, 100%, 95%); }");
    }
    else
    {
        if (engListWindow->isVisible())
        {
            engListWindow->hide();  // 隐藏窗口
            this->EnBtn->setText("ENG");
            EnBtn->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255)}");

            CnBtn->setStyleSheet("QPushButton { background-color: rgb(229, 255, 255)}");
            CnBtn->setStyleSheet("QPushButton { background-color: hsl(180, 100%, 95%); }");
        }
        else
        {
            engListWindow->show();  // 显示窗口
            this->EnBtn->setText("关闭窗口");
            CnBtn->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255)}");

            EnBtn->setStyleSheet("QPushButton { background-color: rgb(229, 255, 255)}");
            EnBtn->setStyleSheet("QPushButton { background-color: hsl(180, 100%, 95%); }");
        }
    }

}

void HandWirttingInput::open_closeSetting()
{
    if (setting == nullptr)
    {
        setting = new Setting(this); //设置子窗口的父对象是this

        //接收来自setting的信号  setting窗口应该在窗口实例化之后再做链接
        bool bug = false;
        bug = QObject::connect(setting, &Setting::btnredclicked, this, &HandWirttingInput::setRed);
        if (bug == false)
        {
            qDebug() << "QObject::connect(setting, &Setting::btnredclicked, this, &HandWirttingInput::setRed);";
        }

        QObject::connect(setting, &Setting::btnblackclicked, this, &HandWirttingInput::setBlack);
        QObject::connect(setting, &Setting::btnyellowclicked, this, &HandWirttingInput::setYellow);
        QObject::connect(setting, &Setting::btnblueclicked, this, &HandWirttingInput::setBlue);
        QObject::connect(setting, &Setting::btngreenclicked, this, &HandWirttingInput::setGreen);
        QObject::connect(setting, &Setting::btnpurpleclicked, this, &HandWirttingInput::setPurple);

        QObject::connect(setting, &Setting::btn1clicked, this, &HandWirttingInput::setWidth1);
        QObject::connect(setting, &Setting::btn2clicked, this, &HandWirttingInput::setWidth2);
        QObject::connect(setting, &Setting::btn3clicked, this, &HandWirttingInput::setWidth3);
        QObject::connect(setting, &Setting::btn4clicked, this, &HandWirttingInput::setWidth4);
        QObject::connect(setting, &Setting::btn5clicked, this, &HandWirttingInput::setWidth5);
        QObject::connect(setting, &Setting::btn6clicked, this, &HandWirttingInput::setWidth6);

        QObject::connect(setting, &Setting::btn10clicked, this, &HandWirttingInput::setSize1);
        QObject::connect(setting, &Setting::btn15clicked, this, &HandWirttingInput::setSize2);
        QObject::connect(setting, &Setting::btn20clicked, this, &HandWirttingInput::setSize3);
        QObject::connect(setting, &Setting::btn25clicked, this, &HandWirttingInput::setSize4);
        QObject::connect(setting, &Setting::btn30clicked, this, &HandWirttingInput::setSize5);
        QObject::connect(setting, &Setting::btn35clicked, this, &HandWirttingInput::setSize6);

        QObject::connect(setting, &Setting::reSetBtnclicked, this, &HandWirttingInput::reSet);


        setting->show();
        this->contrlBtn->setText("关闭窗口");

        contrlBtn->setStyleSheet("QPushButton { background-color: rgb(229, 255, 255)}");
        contrlBtn->setStyleSheet("QPushButton { background-color: hsl(180, 100%, 95%); }");
    }
    else
    {
        if (setting->isVisible())
        {
            setting->hide();  // 隐藏窗口
            this->contrlBtn->setText("设  置");
            contrlBtn->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255)}");
        }
        else
        {
            setting->show();  // 显示窗口
            this->contrlBtn->setText("关闭窗口");

            contrlBtn->setStyleSheet("QPushButton { background-color: rgb(229, 255, 255)}");
            contrlBtn->setStyleSheet("QPushButton { background-color: hsl(180, 100%, 95%); }");
        }
    }
}


//接收来自字符串窗口的信号，并处理
void HandWirttingInput::inputCharButton(const QString& btntext)
{
    //textEdit->append(btntext);  //每次选择一个字符之后，界面就会自动隐藏 append()会自动换行
    textEdit->insertPlainText(btntext);
    chaListWindow->hide();
    this->charBtn->setText(",!/.");
    charBtn->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255)}");

    CnBtn->setStyleSheet("QPushButton { background-color: rgb(229, 255, 255)}");
    CnBtn->setStyleSheet("QPushButton { background-color: hsl(180, 100%, 95%); }");
}

//接收来自数字窗口的信号，并处理
void HandWirttingInput::inputNumButton(const QString& btntext)
{
    //textEdit->append(btntext);  //每次选择一个字符之后，界面就会自动隐藏 append()会自动换行
    textEdit->insertPlainText(btntext);
    numListWindow->hide();
    this->numBtn->setText("123");
    numBtn->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255)}");

    CnBtn->setStyleSheet("QPushButton { background-color: rgb(229, 255, 255)}");
    CnBtn->setStyleSheet("QPushButton { background-color: hsl(180, 100%, 95%); }");
}

//接收来自字母窗口的信号，并处理
void HandWirttingInput::inputEngButton(const QString& btntext)
{
    //textEdit->append(btntext);  //每次选择一个字符之后，界面就会自动隐藏 append()会自动换行
    textEdit->insertPlainText(btntext);
    engListWindow->hide();
    this->EnBtn->setText("ENG");
    EnBtn->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255)}");

    CnBtn->setStyleSheet("QPushButton { background-color: rgb(229, 255, 255)}");
    CnBtn->setStyleSheet("QPushButton { background-color: hsl(180, 100%, 95%); }");
}


//重写事件过滤器，允许WriteZone响应mouseRelease事件
bool HandWirttingInput::eventFilter(QObject* watched, QEvent* event)
{
    if (watched == (this->writeZone))
    {
        if (event->type() == QEvent::MouseButtonRelease)
        {
            QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);

            if (mouseEvent->button() == Qt::LeftButton) //确认是鼠标左键
            {
                emit MouseRelease();
                qDebug() << "Left Mouse Release";

                return true; //事件成功处理
            }
        }
    }

    return QWidget::eventFilter(watched, event);  //继续转发
}


//每一个笔划的结束都会调用识别功能
void HandWirttingInput::mouseReleaseEvent()   //void MouseRlease()信号发出之后，会调用这个槽函数，然后在里面调用识别功能
{
    qDebug() << "mouseReleaseEvent connect.";

    tempRes.clear(); //清空上一次识别的结果
    inputs.RecogData(tempRes); //识别结果获取之后，再发出信号请求联网识别

    //emit ReadySuggest();

    qDebug() << tempRes.size();

    btn1->setText(QString::fromUtf8(QByteArray(tempRes[0].res)));
    btn2->setText(QString::fromUtf8(QByteArray(tempRes[1].res)));
    btn3->setText(QString::fromUtf8(QByteArray(tempRes[2].res)));
    btn4->setText(QString::fromUtf8(QByteArray(tempRes[3].res)));
    btn5->setText(QString::fromUtf8(QByteArray(tempRes[4].res)));

    //候选词填充完成之后，再发出信号请求联网识别
    //suggestions.toNULL();//每一次鼠标释放之后，清空上一次识别的结果
    emit ReadySuggest();   //会滞后一个笔划的结果


}


//按下重写按钮
void HandWirttingInput::btnClearClicked()
{
    qDebug() << "btnClearClicked";

    textEdit->setFocus();
    inputs.clear();  //只是删除笔触，之后在析构的时候才会删除所有资源

    writeZone->clear();

    btn1->setText("");
    btn2->setText("");
    btn3->setText("");
    btn4->setText("");
    btn5->setText("");

    Sugbtn1->setText("");
    Sugbtn2->setText("");
    Sugbtn3->setText("");
    Sugbtn4->setText("");

    tempRes.clear();

}


//按下候选词的按钮，输入文字到textEdit
void HandWirttingInput::btn1Clicked()
{
    qDebug() << "btn1Clicked";

    textEdit->insertPlainText(btn1->text()); //输入按钮文本

    //清空候选框以及书写墨迹，准备下一次识别
    rewriteBtn->click();  //手动发出信号，直接转到重写的槽函数
    
}

void HandWirttingInput::btn2Clicked()
{
    qDebug() << "btn2Clicked";

    textEdit->insertPlainText(btn2->text()); //输入按钮文本

    //清空候选框以及书写墨迹，准备下一次识别
    rewriteBtn->click();  //手动发出信号，直接转到重写的槽函数
}

void HandWirttingInput::btn3Clicked()
{
    qDebug() << "btn3Clicked";

    textEdit->insertPlainText(btn3->text()); //输入按钮文本

    //清空候选框以及书写墨迹，准备下一次识别
    rewriteBtn->click();  //手动发出信号，直接转到重写的槽函数
}

void HandWirttingInput::btn4Clicked()
{
    qDebug() << "btn4Clicked";

    textEdit->insertPlainText(btn4->text()); //输入按钮文本

    //清空候选框以及书写墨迹，准备下一次识别
    rewriteBtn->click();  //手动发出信号，直接转到重写的槽函数
}

void HandWirttingInput::btn5Clicked()
{
    qDebug() << "btn5Clicked";

    textEdit->insertPlainText(btn5->text()); //输入按钮文本

    //清空候选框以及书写墨迹，准备下一次识别
    rewriteBtn->click();  //手动发出信号，直接转到重写的槽函数
}

 
//HansInput发过来的信号，
void HandWirttingInput::deltUpdate()
{
    tempRes.clear(); //清空上一次识别的结果
    inputs.RecogData(tempRes);

    qDebug() << tempRes.size();

    //删除最后一笔时，由于删除之后自动识别，此时画布上面什么也没有，那么结果数组temRes里面是没有任何元素的，于是访问元素下标时不合法的
    //下面的if做一个特判
    if (tempRes.size() >= 5)
    {
        btn1->setText(QString::fromUtf8(QByteArray(tempRes[0].res)));
        btn2->setText(QString::fromUtf8(QByteArray(tempRes[1].res)));
        btn3->setText(QString::fromUtf8(QByteArray(tempRes[2].res)));
        btn4->setText(QString::fromUtf8(QByteArray(tempRes[3].res)));
        btn5->setText(QString::fromUtf8(QByteArray(tempRes[4].res)));
    }
    else   //画布为空的时候
    {
        btn1->setText("");
        btn2->setText("");
        btn3->setText("");
        btn4->setText("");
        btn5->setText("");
    }

    emit ReadySuggest();

    qDebug() << "After Delete, the results has been UPDATE.";
}


//多字识别模式
void HandWirttingInput::mulpattern()
{
    this->resize(2000, 590);

    singleRecBtn->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255)}");

    multipRecBtn->setStyleSheet("QPushButton { background-color: rgb(229, 255, 255)}");
    multipRecBtn->setStyleSheet("QPushButton { background-color: hsl(180, 100%, 95%); }");
}

//单字识别模式
void HandWirttingInput::sigpattern()
{
    this->resize(1300, 590);
    multipRecBtn->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255)}");

    singleRecBtn->setStyleSheet("QPushButton { background-color: rgb(229, 255, 255)}");
    singleRecBtn->setStyleSheet("QPushButton { background-color: hsl(180, 100%, 95%); }");
}


//__________________from setting_____________

void HandWirttingInput::setRed()
{
    IInkDrawingAttributes* p;
    HRESULT hr;
    hr = inputs.p_IInkCollector->get_DefaultDrawingAttributes(&p);
    if (SUCCEEDED(hr))
    {
        p->put_Color(RGB(255, 0, 0));   //红色
    }
}

void HandWirttingInput::setBlack()
{
    IInkDrawingAttributes* p;
    HRESULT hr;
    hr = inputs.p_IInkCollector->get_DefaultDrawingAttributes(&p);
    if (SUCCEEDED(hr))
    {
        p->put_Color(RGB(0, 0, 0));
    }
}

void HandWirttingInput::setYellow()
{
    IInkDrawingAttributes* p;
    HRESULT hr;
    hr = inputs.p_IInkCollector->get_DefaultDrawingAttributes(&p);
    if (SUCCEEDED(hr))
    {
        p->put_Color(RGB(255, 255, 0));
    }
}

void HandWirttingInput::setBlue()
{
    IInkDrawingAttributes* p;
    HRESULT hr;
    hr = inputs.p_IInkCollector->get_DefaultDrawingAttributes(&p);
    if (SUCCEEDED(hr))
    {
        p->put_Color(RGB(0, 0, 255));
    }
}

void HandWirttingInput::setGreen()
{
    IInkDrawingAttributes* p;
    HRESULT hr;
    hr = inputs.p_IInkCollector->get_DefaultDrawingAttributes(&p);
    if (SUCCEEDED(hr))
    {
        p->put_Color(RGB(0, 128, 0));
    }
}

void HandWirttingInput::setPurple()
{
    IInkDrawingAttributes* p;
    HRESULT hr;
    hr = inputs.p_IInkCollector->get_DefaultDrawingAttributes(&p);
    if (SUCCEEDED(hr))
    {
        p->put_Color(RGB(128, 0, 128));
    }
}



void HandWirttingInput::setWidth1()
{
    IInkDrawingAttributes* p;
    HRESULT hr;
    hr = inputs.p_IInkCollector->get_DefaultDrawingAttributes(&p);
    if (SUCCEEDED(hr))
    {
        p->put_Width(30);
    }
}

void HandWirttingInput::setWidth2()
{
    IInkDrawingAttributes* p;
    HRESULT hr;
    hr = inputs.p_IInkCollector->get_DefaultDrawingAttributes(&p);
    if (SUCCEEDED(hr))
    {
        p->put_Width(60);
    }
}

void HandWirttingInput::setWidth3()
{
    IInkDrawingAttributes* p;
    HRESULT hr;
    hr = inputs.p_IInkCollector->get_DefaultDrawingAttributes(&p);
    if (SUCCEEDED(hr))
    {
        p->put_Width(90);
    }
}

void HandWirttingInput::setWidth4()
{
    IInkDrawingAttributes* p;
    HRESULT hr;
    hr = inputs.p_IInkCollector->get_DefaultDrawingAttributes(&p);
    if (SUCCEEDED(hr))
    {
        p->put_Width(120);
    }
}

void HandWirttingInput::setWidth5()
{
    IInkDrawingAttributes* p;
    HRESULT hr;
    hr = inputs.p_IInkCollector->get_DefaultDrawingAttributes(&p);
    if (SUCCEEDED(hr))
    {
        p->put_Width(150);
    }
}

void HandWirttingInput::setWidth6()
{
    IInkDrawingAttributes* p;
    HRESULT hr;
    hr = inputs.p_IInkCollector->get_DefaultDrawingAttributes(&p);
    if (SUCCEEDED(hr))
    {
        p->put_Width(180);
    }
}

//候选字大小
void HandWirttingInput::setSize1()
{
    QFont font("宋体", 10);
    btn1->setFont(font);
    btn2->setFont(font);
    btn3->setFont(font);
    btn4->setFont(font);
    btn5->setFont(font);
}

void HandWirttingInput::setSize2()
{
    QFont font("宋体", 15);
    btn1->setFont(font);
    btn2->setFont(font);
    btn3->setFont(font);
    btn4->setFont(font);
    btn5->setFont(font);
}

void HandWirttingInput::setSize3()
{
    QFont font("宋体", 20);
    btn1->setFont(font);
    btn2->setFont(font);
    btn3->setFont(font);
    btn4->setFont(font);
    btn5->setFont(font);
}

void HandWirttingInput::setSize4()
{
    QFont font("宋体", 25);
    btn1->setFont(font);
    btn2->setFont(font);
    btn3->setFont(font);
    btn4->setFont(font);
    btn5->setFont(font);
}

void HandWirttingInput::setSize5()
{
    QFont font("宋体", 30);
    btn1->setFont(font);
    btn2->setFont(font);
    btn3->setFont(font);
    btn4->setFont(font);
    btn5->setFont(font);
}

void HandWirttingInput::setSize6()
{
    QFont font("宋体", 35);
    btn1->setFont(font);
    btn2->setFont(font);
    btn3->setFont(font);
    btn4->setFont(font);
    btn5->setFont(font);
}

void HandWirttingInput::reSet()
{
    IInkDrawingAttributes* p;
    HRESULT hr;
    hr = inputs.p_IInkCollector->get_DefaultDrawingAttributes(&p);
    if (SUCCEEDED(hr))
    {
        p->put_Color(RGB(0, 0, 0));
        p->put_Width(30);
    }
    
    //设置候选字默认字号
    QFont font("宋体", 10);
    btn1->setFont(font);
    btn2->setFont(font);
    btn3->setFont(font);
    btn4->setFont(font);
    btn5->setFont(font);
}


//联想识别功能
void HandWirttingInput::ReadySuggestEvent()  //信号ReadySuggest的槽函数
{
    QString queryContext = btn1->text(); //获取最优的识别结果，联网做关键字联想查询
    //QString queryContext = QString::fromUtf8(QByteArray(tempRes[0].res)); //获取最优的识别结果，联网做关键字联想查询  QString::fromUtf8(QByteArray(tempRes[0].res))

    QUrl url("https://sug.so.360.cn/suggest");

    QUrlQuery query; //添加自定义查询
    query.addQueryItem("encodein", "utf-8");
    query.addQueryItem("encodeout", "utf-8");
    query.addQueryItem("format", "json");
    query.addQueryItem("word", queryContext);
    query.addQueryItem("callback", "window.so.sug");
    url.setQuery(query);

    qDebug() << "queryContext : " << url;

    //Manager和Reply在构造函数里面做了链接

    //QEventLoop loop;  // 创建事件循环

    httpRequestManager.sendGetRequest(url);  //发送请求

    //httpReplyhandler自动解析数据 解析完成之后会发送suggestionsReady的信号
    //只有在接收到这个信号的时候才更新联想结果

    //QObject::connect(&httpReplyHandler, &HttpReplyHandler::suggestionsReady,
    //    [&loop, this](Suggestion http_suggestions) {
    //        this->suggestions = http_suggestions;
    //        loop.quit();  // 退出事件循环
    //    });


    //联网结果没有返回之前就执行了emit UpdateSuggestions(); 导致检索结果其实是空的，所以具有之后性，
    //要保证返回的结果是有效的，才能够执行发送信号的语句


    QObject::connect(&httpReplyHandler, &HttpReplyHandler::suggestionsReady,
        [this](Suggestion http_suggestions) {
            this->suggestions = http_suggestions;
            // 直接在这里处理数据
            emit UpdateSuggestions();  //实现同步，否则会滞后
        });

    
    //发送信号，表示联想词更新已完成，准备显示到按钮文本上
    //emit UpdateSuggestions();

}


//信号UpdateSuggestions()的槽函数
void HandWirttingInput::fun_UpdateSuggestions()
{
    QVector<SugResult> tmpsug = suggestions.getSugresult();

    int tmpsize = tmpsug.size();
    qDebug() << "tmpSug : " << tmpsize;

    if (tmpsize == 0)  //没有识别结果或者撤销笔划直到画布为空的边界条件
    {
        Sugbtn1->setText("");
        Sugbtn2->setText("");
        Sugbtn3->setText("");
        Sugbtn4->setText("");

    }

    if (tmpsize >= 1) Sugbtn1->setText(tmpsug[0].m_word);
    if (tmpsize >= 2) Sugbtn2->setText(tmpsug[1].m_word);
    if (tmpsize >= 3) Sugbtn3->setText(tmpsug[2].m_word);
    if (tmpsize >= 4) Sugbtn4->setText(tmpsug[3].m_word);

}


//联想词按钮被按下
//无论是候选词还是联想词的按钮，只要被按下，就代表用户认可当前识别结果，要清空所有按钮和画布
void HandWirttingInput::Sugbtn1Clicked()
{
    qDebug() << "Sugbtn1Clicked";

    textEdit->insertPlainText(Sugbtn1->text()); //输入按钮文本

    //清空候选框以及书写墨迹，准备下一次识别
    rewriteBtn->click();  //手动发出信号，直接转到重写的槽函数
}

void HandWirttingInput::Sugbtn2Clicked()
{
    qDebug() << "Sugbtn2Clicked";

    textEdit->insertPlainText(Sugbtn2->text()); //输入按钮文本

    //清空候选框以及书写墨迹，准备下一次识别
    rewriteBtn->click();  //手动发出信号，直接转到重写的槽函数
}

void HandWirttingInput::Sugbtn3Clicked()
{
    qDebug() << "Sugbtn3Clicked";

    textEdit->insertPlainText(Sugbtn3->text()); //输入按钮文本

    //清空候选框以及书写墨迹，准备下一次识别
    rewriteBtn->click();  //手动发出信号，直接转到重写的槽函数
}

void HandWirttingInput::Sugbtn4Clicked()
{
    qDebug() << "Sugbtn4Clicked";

    textEdit->insertPlainText(Sugbtn4->text()); //输入按钮文本

    //清空候选框以及书写墨迹，准备下一次识别
    rewriteBtn->click();  //手动发出信号，直接转到重写的槽函数
}