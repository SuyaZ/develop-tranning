#include "MainWindow.h"

#include<QHeaderView>

MainWindow::MainWindow(QWidget *parent)
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

MainWindow::~MainWindow()
{
    if (!m_vector.isEmpty())
    {
        qDeleteAll(m_vector.begin(), m_vector.end());
    }
}


void MainWindow::initTableWidget()
{
    //创建自定义表格实例
    m_pModel = new KStuTableModel(this);
    m_pModel->setContent(m_vector);  //设置模型内容
    m_pComboxDelegate = new KComboxDelegate(this);  //创建了一个自定义的委托KComboxDelegate的实例
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

void MainWindow::initDataSource()
{
    m_vector.push_back(new KStudent("Tom", 25, "Male", 90));
    m_vector.push_back(new KStudent("Mark", 30, "Male", 86));
    m_vector.push_back(new KStudent("Rose", 18, "Female", 40));
}

//void MainWindow::loadStudentDataIntoTable()
//{
//    for (KStudent* student : m_vector)
//    {
//        int index = m_vector.indexOf(student);
//        tableWidget->setItem(index, 0, new QTableWidgetItem(student->getName()));
//        tableWidget->setItem(index, 1, new QTableWidgetItem(QString::number(student->getAge())));
//        tableWidget->setItem(index, 2, new QTableWidgetItem(QString::number(student->getScore())));
//    }
//}
//
//void MainWindow::onHandleItemChanged(QTableWidgetItem* item)
//{
//    int row = item->row();
//    int column = item->column();
//    QString content = item->text();
//
//    switch (item->column())
//    {
//    case 0:
//        m_vector[row]->setName(content);
//        break;
//    case 1:
//        m_vector[row]->setAge(content.toInt());
//        break;
//    case 2:
//        m_vector[row]->setScore(content.toInt());
//        break;
//    }
//}