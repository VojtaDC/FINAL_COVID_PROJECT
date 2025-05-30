#pragma once
#include <QString>
#include <QDir>
#include <QCoreApplication>

inline QString getPersonsFilePath() {
    QDir exeDir(QCoreApplication::applicationDirPath());
    exeDir.cdUp();
    exeDir.cd("data");
    return exeDir.filePath("persons.csv");
}