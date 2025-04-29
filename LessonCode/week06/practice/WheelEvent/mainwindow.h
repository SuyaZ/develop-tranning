#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QWheelEvent>


class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    mainwindow(QWidget* parent = nullptr);

protected:
    bool eventFilter(QObject* watched, QEvent* event) override;


private:
    QWidget* centralWidget = nullptr;
    QVBoxLayout* centralLayout = nullptr;

    QLabel* uiLabel;

    Ui::mainwindowClass ui;
};
