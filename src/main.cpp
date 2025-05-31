#include "login_screen.h"
#include <QtWidgets/QApplication>
#include <QString>
#include <QDir>
#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QString exeDir = QCoreApplication::applicationDirPath();
	qDebug() << exeDir;
	LoginScreen login;
	login.show();
	return a.exec();

}
