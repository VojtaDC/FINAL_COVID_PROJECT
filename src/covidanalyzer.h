#pragma once

#include <QWidget>
#include <QString>
#include <vector>
#include <algorithm>
#include <opencv2/opencv.hpp>
#include <fdeep/fdeep.hpp>

namespace Ui {
class CovidAnalyzer;
}

class CovidAnalyzer : public QWidget
{
    Q_OBJECT

public:
    explicit CovidAnalyzer(QWidget *parent = nullptr);
    ~CovidAnalyzer();

private slots:
    void on_loadFileButton_clicked();

private:
    Ui::CovidAnalyzer *ui;
    QString selectedFilePath;
    int analyzeScan(const QString &imagePath);
    bool getHighestPrediction(const std::vector<fdeep::tensor> &results);

    // To implement, threads, later. 
    void startBackgroundAnalysis(const QString &imagePath);
};

