#include "MainWindow.h"
#include "Kxstudent.h"
#include "ui_MainWindow.h"

#include<QHeaderView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    tableWidget = new QTableWidget;
    centralWidget = new QWidget;
    centralLayout = new QVBoxLayout;
    this->setCentralWidget(centralWidget);

    initDataSource();

    initTableWidget();

    centralLayout->addWidget(tableWidget);
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
    tableWidget->setRowCount(5);
    tableWidget->setColumnCount(3);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    QStringList headerLables = { "Name", "Age", "Score" };
    tableWidget->setHorizontalHeaderLabels(headerLables);
    loadStudentDataIntoTable();
    (void)connect(tableWidget, &QTableWidget::itemChanged, this, &MainWindow::onHandleItemChanged);

}

void MainWindow::initDataSource()
{
    m_vector.push_back(new KxStudent("Tom", 25, 90));
    m_vector.push_back(new KxStudent("Mark", 30, 86));
    m_vector.push_back(new KxStudent("Kevin", 18, 40));
    m_vector.push_back(new KxStudent("Lucy", 22, 88));
    m_vector.push_back(new KxStudent("David", 28, 75));
}

void MainWindow::loadStudentDataIntoTable()
{
    for (KxStudent* student : m_vector)
    {
        int index = m_vector.indexOf(student);
        tableWidget->setItem(index, 0, new QTableWidgetItem(student->getName()));
        tableWidget->setItem(index, 1, new QTableWidgetItem(QString::number(student->getAge())));
        tableWidget->setItem(index, 2, new QTableWidgetItem(QString::number(student->getScore())));
    }
}

void MainWindow::onHandleItemChanged(QTableWidgetItem* item)
{
    int row = item->row();
    int column = item->column();
    QString content = item->text();

    switch (item->column())
    {
    case 0:
        m_vector[row]->setName(content);
        break;
    case 1:
        m_vector[row]->setAge(content.toInt());
        break;
    case 2:
        m_vector[row]->setScore(content.toInt());
        break;
    }
}