#ifndef __TIMER_H__
#define __TIMER_H__
//实现一个计时器对时间进行显示和修改
#include<QtWidgets>
#include<Qwidget>
#include<QEvent>
#include<QTimer>
#include<QObject>


class myTimer : public QTimeEdit
{
	Q_OBJECT;

public:
	QPushButton* pb;
	QPushButton* pb1;
	QTimer t;

	myTimer(QWidget* p = nullptr) : QTimeEdit(p) {}

	myTimer(QTime d, QWidget* p = nullptr) :QTimeEdit(d, p)
	{
		pb = new QPushButton("edit", p);
		pb->move(22, 66);

		pb1 = new QPushButton("ok", p);
		pb1->move(99, 66);

		//作用与仅限于组件实例
		setReadOnly(true); //将旋转狂设置为只读模式，这样在时间显示的时候就不能修改时间
		setWrapping(true); //开启微调按钮的循环调节模式
		//对于数值调节组件，如 QTimer，环绕模式意味着当值达到最大值时，继续增加会回到最小值，形成一个循环调节的效果

		connect(pb, &QPushButton::clicked, this, &myTimer::myEdit);
		connect(this, &QTimeEdit::editingFinished, this, &myTimer::run);
		//&QTimeEdit::editingFinished：这是 QTimeEdit 控件的 editingFinished 信号。当用户完成时间编辑并且控件失去焦点时，这个信号被发射。
		connect(pb1, &QPushButton::clicked, this, &myTimer::run);
		connect(&t, &QTimer::timeout, this, &myTimer::addSecond);

		t.start(1000); //1000ms为一个时间间隔
		
	}

public slots:
	void addSecond() //当前时间基础上增加一秒，有计时器超时调用
	{
		setTime(time().addSecs(1));
	}

	void myEdit() //使QtimeEdit可编辑
	{
		t.stop(); //停止计时器
		setReadOnly(false);
	}

	void run() //编辑完成之后，里面的时间再次自动运行起来
	{
		setReadOnly(true);
		t.start(1000);
	}

};



#endif