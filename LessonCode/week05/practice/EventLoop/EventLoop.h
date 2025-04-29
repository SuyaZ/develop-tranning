#include<QWidget>
#include<QtWidgets/QApplication>
#include<QEvent>
#include<QPushButton>
#include<QMouseEvent>

class MyButton : public QPushButton
{
public:
	MyButton(QWidget* parent) : QPushButton(parent)
	{
		setFixedSize(200, 100);  //设置按钮的初始大小
	}

protected:
	//鼠标移入时按钮放大
	void enterEvent(QEvent* e) override
	{
		setFixedSize(400, 200);
		QPushButton::enterEvent(e); //事件传递
	}

	//移除时缩小
	void leaveEvent(QEvent* e) override
	{
		setFixedSize(200, 100);
		QPushButton::leaveEvent(e); //事件传递
	}


};


