#include <iostream>
#include <fdeep/fdeep.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <filesystem>
#include <exception>

// "C:/Users/jorda/image_ex/"
// "C:/Users/jorda/data/COVID-19_Radiography_Dataset/COVID/images/"

namespace fs = std::experimental::filesystem;  

bool highest(const std::vector<fdeep::tensor> _results);
int prediction_folder(std::string folder);
int prediction_image(std::string _image);

int main()
{
	int number = 2;
	std::vector<std::string> list_image = { "C:/Users/jorda/image_ex/Viral Pneumonia-1.png", "C:/Users/jorda/image_ex/Viral Pneumonia-2.png" };
	int P_image = prediction_image("C:/Users/jorda/image_ex/Viral Pneumonia-1.png");

	return 0;
}

int prediction_folder(std::string folder)
{
	try {
		std::string test_image_folder_path = folder;  
		const auto mymodel = fdeep::load_model("C:/Users/jorda/OneDrive/Documenten/3BA_EIT/system programming/epoch_30.json", false);

		for (const auto& entry : fs::directory_iterator(test_image_folder_path)) {
			try {
				std::string image_path = entry.path().string();

				// Werken met RGB (3 kanalen), model werkt met grey
				cv::Mat image = cv::imread(image_path, cv::IMREAD_COLOR);
				if (image.empty()) {
					std::cerr << "Could not read image: " << image_path << std::endl;
					continue;
				}
				cv::Mat resizedImg;
				cv::resize(image, resizedImg, cv::Size(299, 299)); //Resize naar 299x299

				resizedImg.convertTo(resizedImg, CV_32FC3, 1.0 / 255.0);  //normalise [0,1]
				imshow("Display Window", resizedImg);    //show image
				//cv::waitKey(10000000000);

				// Maak tensor van de image data
				const auto input = fdeep::tensor_from_bytes(
					resizedImg.ptr(),
					static_cast<std::size_t>(resizedImg.rows),
					static_cast<std::size_t>(resizedImg.cols),
					static_cast<std::size_t>(3),  // 3 kanalen (RGB)
					0.0f, 1.0f);
				//resultaten
				auto result = mymodel.predict({ input });
				//highest(result[0], list);
				std::cout << "Prediction for " << image_path << ":\n"
					<< fdeep::show_tensors(result) << std::endl;

				// [[[[[ COVID 0, LUNG OP 1, NORMAL 1, VIRAL PNE 0]]]]]  


			}
			catch (const std::exception& e) {
				std::cerr << "Error processing " << entry.path() << ": " << e.what() << '\n';
			}
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Fout bij laden model: " << e.what() << std::endl;
		return 1;
	}
}

int prediction_image(std::string _image)
{
	const auto mymodel = fdeep::load_model("C:/Users/jorda/OneDrive/Documenten/3BA_EIT/system programming/epoch_30.json", false);
	std::string image_path = _image;
	cv::Mat image = cv::imread(image_path, cv::IMREAD_COLOR);
	if (image.empty()) {
		std::cerr << "Could not read image: " << image_path << std::endl;
		return 1;
	}

	cv::Mat resizedImg;
	cv::resize(image, resizedImg, cv::Size(299, 299));
	resizedImg.convertTo(resizedImg, CV_32FC3, 1.0 / 255.0);
	imshow("Display Window", resizedImg);

	cv::cvtColor(resizedImg, resizedImg, cv::COLOR_BGR2RGB);
	const auto input = fdeep::tensor_from_bytes(
		resizedImg.ptr(),
		static_cast<std::size_t>(resizedImg.rows),
		static_cast<std::size_t>(resizedImg.cols),
		static_cast<std::size_t>(3),
		0.0f, 1.0f);

	std::vector<fdeep::tensor> result = mymodel.predict({ input });
	std::cout << "Prediction for " << image_path << ":\n"
		<< fdeep::show_tensors(result) << std::endl;
	bool rs = highest(result);
	// [[[[[ COVID 0, LUNG OP 1, NORMAL 1, VIRAL PNE 0]]]]]
	if (rs) {
		std::cout<<"you have COVID"<<std::endl;
	}
	else {
		std::cout<<"you do not have COVID"<<std::endl;
	}
	return 0;
		 
}

bool highest(const std::vector<fdeep::tensor> _results)
{
	const std::vector<float> prob = _results.front().to_vector();
	auto max_itt = std::max_element(prob.begin(), prob.end());
	int index = static_cast<int>(std::distance(prob.begin(), max_itt));
	if (index == 0)
	{
		return true;
	}else{
		return false;
	}
}