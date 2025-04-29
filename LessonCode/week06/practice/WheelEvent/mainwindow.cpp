#pragma execution_character_set("utf-8")

#include "mainwindow.h"

mainwindow::mainwindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    centralWidget = new QWidget;
    centralLayout = new QVBoxLayout;

    uiLabel = new QLabel("滚动事件: 无", this);
    centralLayout->addWidget(uiLabel);

    this->setCentralWidget(centralWidget);
    centralWidget->setLayout(centralLayout);

    // 安装事件过滤器
    this->installEventFilter(this);

}

bool mainwindow::eventFilter(QObject* watched, QEvent* event)
{
    if (event->type() == QEvent::Wheel || watched == uiLabel) 
    {
        QWheelEvent* wheelEvent = static_cast<QWheelEvent*>(event);
        int delta = wheelEvent->angleDelta().y();

        // 判断滚动方向
        QString direction = (delta > 0) ? "向上滚动" : "向下滚动";

        // 更新UI
        QString message = QString("滚动事件: %1").arg(direction);
        uiLabel->setText(message);

        return true; // 事件已处理，不再传递
    }
    return QWidget::eventFilter(watched, event);
}
