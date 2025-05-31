#include "covidanalyzer.h"
#include "ui_covidanalyzer.h"
#include "paths.h"    
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QDebug>
// #include <QtConcurrent>     // voor eenvoudige threading

CovidAnalyzer::CovidAnalyzer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CovidAnalyzer)
{
    ui->setupUi(this);
    setWindowTitle("COVID-19 Scan Analysis");
}

CovidAnalyzer::~CovidAnalyzer()
{
    delete ui;
}

void CovidAnalyzer::on_loadFileButton_clicked()
{
    // Open file dialog
    selectedFilePath = QFileDialog::getOpenFileName(
        this,
        "Select Scan Image",
        QString(),
        "Image Files (*.png *.jpg *.jpeg *.bmp *.tif)"
    );
    if (selectedFilePath.isEmpty()) return;

    // Toon direct de preview (zonder te wachten op analyse)
    QPixmap pixmap(selectedFilePath);
    if (pixmap.isNull()) {
        QMessageBox::critical(this, "Error", "Could not load the selected image.");
        return;
    }
    pixmap = pixmap.scaled(
        ui->imagePreviewLabel->width(),
        ui->imagePreviewLabel->height(),
        Qt::KeepAspectRatio,
        Qt::SmoothTransformation
    );
    ui->imagePreviewLabel->setPixmap(pixmap);
     try {
        int result = analyzeScan(selectedFilePath);
        if (result == 0) {
            qDebug() << "Scan analyzed successfully";
        } else {
            qDebug() << "Error analyzing scan";
        }
    } catch (const std::exception& e) {
        qDebug() << "Exception caught: " << e.what();
        QMessageBox::critical(this, "Analysis Error", QString("Error analyzing the scan: %1").arg(e.what()));
    }

    // startBackgroundAnalysis(selectedFilePath);
}

// De eigenlijke analyse (in worker thread)
int CovidAnalyzer::analyzeScan(const QString &imagePath)
{
    QString modelPath = getModelFilePath();
    try {
        const auto model = fdeep::load_model(
            modelPath.toStdString(),
            false,
            fdeep::dev_null_logger
        );

        cv::Mat image = cv::imread(imagePath.toStdString(), cv::IMREAD_COLOR);
        if (image.empty()) {
            qDebug() << "Could not read image:" << imagePath;
            return 1;
        }
        cv::Mat resizedImg;
        cv::resize(image, resizedImg, cv::Size(299, 299));
        // resizedImg.convertTo(resizedImg, CV_32FC3, 1.0 / 255.0);
        imshow("Display Window", resizedImg); 

        cv::cvtColor(resizedImg, resizedImg, cv::COLOR_BGR2RGB);
        const auto input = fdeep::tensor_from_bytes(
            resizedImg.ptr(),
            static_cast<std::size_t>(resizedImg.rows),
            static_cast<std::size_t>(resizedImg.cols),
            static_cast<std::size_t>(3),
            0.0f, 1.0f
        );

        std::vector<fdeep::tensor> result = model.predict({ input });
        bool isCovid = getHighestPrediction(result);
        const std::vector<float> probs = result.front().to_vector();
        float covidProb = !probs.empty() ? probs[0] * 100.0f : 0.0f;
        qDebug() << "Thread: COVID prob =" << covidProb << "%";

        // Omdat we in een worker thread zitten, mogen we UI‐widgets niet direct aanpassen.
        // Gebruik signals of QMetaObject::invokeMethod met Qt::QueuedConnection:
        QString resultText;
        if (isCovid) {
            resultText = QString("COVID-19 DETECTED\nProbability: %1%")
                             .arg(covidProb, 0, 'f', 1);
        } else {
            resultText = QString("NO COVID-19 DETECTED\nProbability: %1%")
                             .arg(covidProb, 0, 'f', 1);
        }

        ui->resultLabel->setText(resultText);

        // Post een functie die in de GUI‐thread draait om de label up te daten:
        // QMetaObject::invokeMethod(ui->resultLabel, "setText",
        //                           Qt::QueuedConnection,
        //                           Q_ARG(QString, resultText));

        return 0;
    }
    catch (const std::exception &e) {
        qDebug() << "Error in analyzeScan:" << e.what();
        QString errorMsg = QString::fromStdString(e.what());
        // QString labelText;
        if (errorMsg.contains("json", Qt::CaseInsensitive)) {
            // labelText = "Error: Model format incompatibility.\nPlease check model file.";
            ui->resultLabel->setText("Error: Model format incompatibility.\nPlease check the model file format.");
        } else {
            // labelText = "Error: Failed to analyze scan.\nCheck debug output.";
            ui->resultLabel->setText("Error: Failed to analyze scan.\nCheck debug output for details.");
        }
        // QMetaObject::invokeMethod(ui->resultLabel, "setText",
        //                           Qt::QueuedConnection,
        //                           Q_ARG(QString, labelText));
        return 1;
    }
}

bool CovidAnalyzer::getHighestPrediction(const std::vector<fdeep::tensor> &results)
{
    const std::vector<float> prob = results.front().to_vector();
    auto max_iter = std::max_element(prob.begin(), prob.end());
    int index = static_cast<int>(std::distance(prob.begin(), max_iter));
    return (index == 0);
}