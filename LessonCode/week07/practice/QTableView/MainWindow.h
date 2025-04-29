#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include <QScopedPointer>  // Qt 框架中的一个智能指针类模板
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QGridLayout>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//前向声明
//减少依赖、避免循环依赖、减少编译时间
class KxStudent;
class QTableWidgetItem;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initTableWidget();
    void initDataSource();
    void loadStudentDataIntoTable();

    void onHandleItemChanged(QTableWidgetItem* item);

private:
    QVector<KxStudent*> m_vector;

    QTableWidget* tableWidget = nullptr;
    QWidget* centralWidget = nullptr;
    QVBoxLayout* centralLayout = nullptr;

    Ui::MainWindowClass ui;
};


#endif
