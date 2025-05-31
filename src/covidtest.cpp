#include "covidtest.h"
#include "ui_covidtest.h"
#include "paths.h"

CovidTest::CovidTest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CovidTest)
{
    ui->setupUi(this);
    setWindowTitle("COVID-19 Scan Analysis");
    
    // Create main layout
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    
    // Create image preview section
    QGroupBox *previewBox = new QGroupBox("Scan Preview", this);
    QVBoxLayout *previewLayout = new QVBoxLayout(previewBox);
    imagePreviewLabel = new QLabel(this);
    imagePreviewLabel->setAlignment(Qt::AlignCenter);
    imagePreviewLabel->setMinimumSize(400, 400);
    imagePreviewLabel->setText("No image selected");
    previewLayout->addWidget(imagePreviewLabel);
    
    // Create control section
    QGroupBox *controlBox = new QGroupBox("Controls", this);
    QVBoxLayout *controlLayout = new QVBoxLayout(controlBox);
    loadFileButton = new QPushButton("Load Scan File", this);
    controlLayout->addWidget(loadFileButton);
    
    // Create result section
    QGroupBox *resultBox = new QGroupBox("Analysis Result", this);
    QVBoxLayout *resultLayout = new QVBoxLayout(resultBox);
    resultLabel = new QLabel("No scan analyzed yet", this);
    resultLabel->setAlignment(Qt::AlignCenter);
    resultLayout->addWidget(resultLabel);
    
    // Add all sections to main layout
    mainLayout->addWidget(previewBox);
    mainLayout->addWidget(controlBox);
    mainLayout->addWidget(resultBox);
    
    // Set central widget
    setCentralWidget(centralWidget);
    
    // Connect signals to slots
    connect(loadFileButton, &QPushButton::clicked, this, &CovidTest::on_loadFileButton_clicked);
    
    // Set window size
    resize(600, 700);
}

CovidTest::~CovidTest()
{
    delete ui;
}

void CovidTest::on_loadFileButton_clicked()
{
    // Open file dialog to select an image
    selectedFilePath = QFileDialog::getOpenFileName(
        this, 
        "Select Scan Image", 
        QString(), 
        "Image Files (*.png *.jpg *.jpeg *.bmp *.tif)"
    );
    
    if (selectedFilePath.isEmpty()) {
        return; // User canceled selection
    }
    
    // Display selected image in preview label
    QPixmap pixmap(selectedFilePath);
    if (pixmap.isNull()) {
        QMessageBox::critical(this, "Error", "Could not load the selected image.");
        return;
    }
    
    // Scale the image to fit the label while maintaining aspect ratio
    pixmap = pixmap.scaled(imagePreviewLabel->width(), imagePreviewLabel->height(), 
                           Qt::KeepAspectRatio, Qt::SmoothTransformation);
    imagePreviewLabel->setPixmap(pixmap);
    
    // Analyze the scan and update result
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
}

int CovidTest::analyzeScan(const QString &imagePath)
{
    // Get the model path from paths.h
    QString modelPath = getModelFilePath();
    
    try {
        // Load the model
        qDebug() << "Loading model from:" << modelPath;
        
        // Load model with verification disabled and custom error handling
        qDebug() << "Building model...";
        const auto model = fdeep::load_model(
            modelPath.toStdString(), 
            false,  // disable verification tests
            fdeep::dev_null_logger  // disable logging to reduce noise
        );
        qDebug() << "Model loaded successfully!";
        
        // Load and preprocess the image
        cv::Mat image = cv::imread(imagePath.toStdString(), cv::IMREAD_COLOR);
        if (image.empty()) {
            qDebug() << "Could not read image:" << imagePath;
            return 1;
        }
        
        // Resize to 299x299 (assuming this is the input size expected by your model)
        cv::Mat resizedImg;
        cv::resize(image, resizedImg, cv::Size(299, 299));
        
        // Convert to floating point and normalize
        resizedImg.convertTo(resizedImg, CV_32FC3, 1.0 / 255.0);
        
        // Convert BGR to RGB (assuming model expects RGB)
        cv::cvtColor(resizedImg, resizedImg, cv::COLOR_BGR2RGB);
        
        // Create tensor from image
        const auto input = fdeep::tensor_from_bytes(
            resizedImg.ptr(),
            static_cast<std::size_t>(resizedImg.rows),
            static_cast<std::size_t>(resizedImg.cols),
            static_cast<std::size_t>(3), // 3 channels (RGB)
            0.0f, 1.0f
        );
        
        // Run prediction
        std::vector<fdeep::tensor> result = model.predict({ input });
        
        // Get prediction
        bool isCovid = getHighestPrediction(result);
        
        // Output raw tensor values for debugging
        qDebug() << "Prediction raw values:";
        qDebug() << QString::fromStdString(fdeep::show_tensors(result));
        
        // Extract probabilities
        const std::vector<float> probabilities = result.front().to_vector();
        float covidProb = 0.0f;
        if (!probabilities.empty()) {
            covidProb = probabilities[0] * 100.0f; // First element is COVID probability
            qDebug() << "COVID probability:" << covidProb << "%";
        }
        
        // Update result label
        QString resultText;
        if (isCovid) {
            resultText = QString("COVID-19 DETECTED\nProbability: %1%").arg(covidProb, 0, 'f', 1);
            qDebug() << "COVID-19 detected in scan.";
        } else {
            resultText = QString("NO COVID-19 DETECTED\nProbability of COVID: %1%").arg(covidProb, 0, 'f', 1);
            qDebug() << "No COVID-19 detected in scan.";
        }
        resultLabel->setText(resultText);
        
        return 0;
    }
    catch (const std::exception& e) {
        qDebug() << "Error in analyzeScan:" << e.what();
        
        // Check if it's a JSON-related error
        QString errorMsg = QString::fromStdString(e.what());
        if (errorMsg.contains("json") || errorMsg.contains("JSON") || 
            errorMsg.contains("key") || errorMsg.contains("operator[]")) {
            qDebug() << "JSON parsing error detected. This might be due to:";
            qDebug() << "1. Model format incompatibility with frugally-deep version";
            qDebug() << "2. Missing required keys in the model file";
            qDebug() << "3. Corrupted model file";
            
            // Set error result in the UI
            resultLabel->setText("Error: Model format incompatibility.\nPlease check the model file format.");
        } else {
            resultLabel->setText("Error: Failed to analyze scan.\nCheck debug output for details.");
        }
        
        return 1;
    }
}

bool CovidTest::getHighestPrediction(const std::vector<fdeep::tensor> &results)
{
    // Extract probabilities from tensor
    const std::vector<float> prob = results.front().to_vector();
    
    // Find the index with the maximum probability
    auto max_iter = std::max_element(prob.begin(), prob.end());
    int index = static_cast<int>(std::distance(prob.begin(), max_iter));
    
    // Return true if COVID (assuming index 0 is COVID as in original code)
    return (index == 0);
}
