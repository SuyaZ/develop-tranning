#pragma once
#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include <QScopedPointer>  // Qt 框架中的一个智能指针类模板
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QTableView>
#include <Require.h>
#include <BoxDelegate.h>
#include <TableModel.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//前向声明
//减少依赖、避免循环依赖、减少编译时间
class Require;
class QTableWidgetItem;


class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent = nullptr);
    ~mainwindow();

    void initTableWidget();
    void initDataSource();

private:

    QVector<Require*> m_vector;
    TableModel* m_pModel = nullptr;
    BoxDelegate* m_pComboxDelegate = nullptr;

    QTableView* tableView = nullptr;
    QWidget* centralWidget = nullptr;
    QVBoxLayout* centralLayout = nullptr;

    Ui::mainwindowClass ui;
};


#endif