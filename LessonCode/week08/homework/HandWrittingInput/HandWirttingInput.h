#pragma once

#include "ui_HandWirttingInput.h"
//#include "CharacterList.h"
#include "MapCharList.h"  //MapCharList只要是对原来的CharacterList.h使用signalMap进行重写，优化代码
#include "MapNumList.h"
#include "MapEngList.h"
#include "HansInput.h"
#include "Setting.h"
#include "Suggestion.h"
#include "HttpReplyHandler.h"
#include "HttpRequestManager.h"
#include <QtWidgets/QMainWindow>
#include <QLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QWidget>
#include <QDebug>
#include <QTextEdit>
#include <QLabel>
#include <QEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPoint>
#include <Qt>
#include <QBitmap>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <qtextcodec.h>
#include <windows.h>
#include <QClipboard>
 


class HandWirttingInput : public QMainWindow
{
    Q_OBJECT

public:
    HandWirttingInput(QWidget *parent = nullptr);
    ~HandWirttingInput();

    //重写事件过滤器，允许WriteZone响应mouseRelease事件
    bool eventFilter(QObject* obj, QEvent* event) override;

    //___________________
    HansInput inputs;   //识别方法
    InPutResS tempRes;  //存放候选结果

    //___________________
    Suggestion suggestions;  //存放联想结果
    
    HttpRequestManager httpRequestManager; //管理http请求类
    HttpReplyHandler httpReplyHandler;  //处理和解析http请求结果



signals:
    void MouseRelease();  //每一笔写完之后，通过事件过滤器发出信号


    //————————————————————联想识别————————————————
    void ReadySuggest();  //在每一次鼠标释放之后，执行完本地识别之后，再发出这个信号

    void UpdateSuggestions();


public slots:
    void open_closeCharacterList();  //打开字符窗口
    void open_closeNumberList(); //单击打开窗口，再次点击关闭窗口
    void open_closeEngList(); 
    void open_closeSetting();

    //接收来自字符串窗口的信号，并处理
    void inputCharButton(const QString& btntext);
    void inputNumButton(const QString& btntext);
    void inputEngButton(const QString& btntext);

    void mouseReleaseEvent();   //void MouseRlease()信号发出之后，会调用这个槽函数，然后在里面调用识别功能

    //联想词按钮被按下
    void Sugbtn1Clicked();
    void Sugbtn2Clicked();
    void Sugbtn3Clicked();
    void Sugbtn4Clicked();



    //按下候选词的按钮，输入文字到textEdit
    void btn1Clicked();
    void btn2Clicked();
    void btn3Clicked();
    void btn4Clicked();
    void btn5Clicked();

    //重写按钮被按下
    void btnClearClicked();

    //HansInput发过来的信号，
    void deltUpdate();

    //多字识别模式
    void mulpattern();

    //单字识别模式
    void sigpattern();


    //____________from setting______________
    void setRed();
    void setBlack();
    void setYellow();
    void setBlue();
    void setGreen();
    void setPurple();

    void setWidth1();
    void setWidth2();
    void setWidth3();
    void setWidth4();
    void setWidth5();
    void setWidth6();

    void setSize1();
    void setSize2();
    void setSize3();
    void setSize4();
    void setSize5();
    void setSize6();

    void reSet();


    //————————————————————联想识别————————————————
    void ReadySuggestEvent();  //信号ReadySuggest的槽函数

    void fun_UpdateSuggestions();





private:
    //CharacterList* chaListWindow = nullptr; //主窗口里面添加一个子窗口的指针
    MapCharList* chaListWindow = nullptr; //主窗口里面添加一个子窗口的指针
    MapNumList* numListWindow = nullptr;
    MapEngList* engListWindow = nullptr;
    Setting* setting = nullptr;


    //准备页面布局的所欲需要用到的控件指针，本来是在构造函数里面处理的，但是总觉得这样不好直接访问，使用findchild()并不是一个很高效率的方法
    //所以先定义所有需要布局的，布局控制、容器、以及控件指针
    QWidget* centralWidget = nullptr; //中心部件的容器
    QGridLayout* centralplay = nullptr; //中心布局

    //顶部的文本编辑器 控件_______________________
    QTextEdit* textEdit = nullptr;


    //联想字区域————————————————————————————————
    QWidget* SugContainer = nullptr;
    QHBoxLayout* Sugplay = nullptr;
    QPushButton* Sugbtn1 = nullptr;  //联想字按钮
    QPushButton* Sugbtn2 = nullptr;
    QPushButton* Sugbtn3 = nullptr;
    QPushButton* Sugbtn4 = nullptr;



    //-------------- 左 ——————————————————
    QWidget* leftContainer = nullptr;
    QVBoxLayout* leftplay = nullptr;

    QPushButton* contrlBtn = nullptr;
    QPushButton* singleRecBtn = nullptr;
    QPushButton* multipRecBtn = nullptr;
    QPushButton* eraseBtn = nullptr;
    QPushButton* rewriteBtn = nullptr;

    //-------------- 中 ——————————————————
    QWidget* midContainer = nullptr;
    QVBoxLayout* midplay = nullptr;
    QLabel* writeZone = nullptr;

    //-------------- 右 ——————————————————
    //在MainWindow里面创建QWidget容器管理布局
    QWidget* rightContainer = nullptr;

    //网格布局
    QGridLayout* rightplay = nullptr;

    // 添加组件
    QPushButton* btn1 = nullptr; //识别之前默认候选栏都是空值
    QPushButton* btn2 = nullptr;
    QPushButton* btn3 = nullptr;
    QPushButton* btn4 = nullptr;
    QPushButton* btn5 = nullptr;

    QPushButton* charBtn = nullptr;
    QPushButton* numBtn = nullptr;
    QPushButton* EnBtn = nullptr;
    QPushButton* CnBtn = nullptr;



    Ui::HandWirttingInputClass ui;


};
