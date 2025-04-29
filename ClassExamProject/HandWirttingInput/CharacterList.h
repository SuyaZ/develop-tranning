#pragma once
 
#include "ui_CharacterList.h"
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

class CharacterList : public QWidget
{
	Q_OBJECT

public:
	CharacterList(QWidget *parent = nullptr);
	~CharacterList();

private:
	Ui::CharacterListClass ui;
};
