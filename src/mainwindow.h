#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"

class MainWIndow : public QMainWindow
{
	Q_OBJECT

public:
	MainWIndow(QWidget *parent = Q_NULLPTR);

private:
	Ui::MainWIndowClass ui;
};
