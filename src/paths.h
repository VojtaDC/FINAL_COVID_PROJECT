#pragma once
#include <QString>
#include <QDir>
#include <QCoreApplication>
#include <QDebug>

inline QString getPersonsFilePath() {

	QDir exeDir(QCoreApplication::applicationDirPath());
	exeDir.cdUps();
	exeDir.cd("data");

	return exeDir.filePath("persons.csv");
}

