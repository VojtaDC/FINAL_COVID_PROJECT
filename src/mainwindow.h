#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *_parent = Q_NULLPTR);

private:
    Ui::MainWIndowClass ui;
};