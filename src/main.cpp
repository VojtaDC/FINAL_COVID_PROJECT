#include "mainwindow.h"
#include "loginscreen.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	LoginScreen login;
	login.show();
	return a.exec();
}
