#pragma execution_character_set("utf-8")

#include "mainwindow.h"

#include<QHeaderView>

mainwindow::mainwindow(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    tableView = new QTableView;
    centralWidget = new QWidget;
    centralLayout = new QVBoxLayout;
    this->setCentralWidget(centralWidget);

    initDataSource();

    initTableWidget();

    centralLayout->addWidget(tableView);
    centralWidget->setLayout(centralLayout);
}

mainwindow::~mainwindow()
{
    if (!m_vector.isEmpty())
    {
        qDeleteAll(m_vector.begin(), m_vector.end());
    }
}


void mainwindow::initTableWidget()
{
    //创建自定义表格实例
    m_pModel = new TableModel(this);
    m_pModel->setContent(m_vector);  //设置模型内容
    m_pComboxDelegate = new BoxDelegate(this);  //创建了一个自定义的委托KComboxDelegate的实例
    tableView->setItemDelegate(m_pComboxDelegate);  //自定义的委托设置给tableView，这样tableView中的项将使用这个委托来显示和编辑

    tableView->setModel(m_pModel);  //设置模型到视图

    //水平表头的调整模式为拉伸（Stretch），垂直表头的调整模式为根据内容调整大小
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    tableView->verticalHeader()->hide();

    // 设置单击选中行
    //ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    //关闭滚动条
    tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);




}

void mainwindow::initDataSource()
{
    m_vector.push_back(new Require("修改开发模板", "业务创新"));
    m_vector.push_back(new Require("增加消息通知模块", "客户反馈"));
    m_vector.push_back(new Require("消息需要显示已读功能", "用户调研"));
    m_vector.push_back(new Require("登录是需要登录提醒", "用户调研"));
    m_vector.push_back(new Require("手机端升级故障", "客户反馈"));
    m_vector.push_back(new Require("手机端优化", "日常迭代"));
}
