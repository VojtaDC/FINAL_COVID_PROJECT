#pragma once

#include <QMainWindow>
#include <QFileDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QMessageBox>
#include <QString>
#include <QDebug>

#include <fdeep/fdeep.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <exception>

namespace Ui {
    class CovidTest;
}

class CovidTest : public QMainWindow
{
    Q_OBJECT

public:
    explicit CovidTest(QWidget *parent = nullptr);
    ~CovidTest();

private slots:
    void on_loadFileButton_clicked();

private:
    Ui::CovidTest *ui;
    QPushButton *loadFileButton;
    QLabel *imagePreviewLabel;
    QLabel *resultLabel;
    
    QString selectedFilePath;
    
    int analyzeScan(const QString &imagePath);
    bool getHighestPrediction(const std::vector<fdeep::tensor> &results);
};
