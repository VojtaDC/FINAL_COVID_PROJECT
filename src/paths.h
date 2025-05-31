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

inline QString getModelFilePath() {
    QDir exeDir(QCoreApplication::applicationDirPath());
    exeDir.cdUp();
    exeDir.cd("data");
    return exeDir.filePath("epoch_30.json");
}

inline QString getDoctorFilePath() {
    QDir exeDir(QCoreApplication::applicationDirPath());
    exeDir.cdUp();
    exeDir.cd("data");
    return exeDir.filePath("doctor.csv");
}

inline QString getPatientFilePath() {
    QDir exeDir(QCoreApplication::applicationDirPath());
    exeDir.cdUp();
    exeDir.cd("data");
    return exeDir.filePath("patient.csv");
}