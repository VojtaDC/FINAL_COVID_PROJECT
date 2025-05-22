#include "mainwindow.h"
#include "loginscreen.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	LoginScreen login;
	login.show();
	//MainWIndow w;
	//w.show();
	return a.exec();
}
