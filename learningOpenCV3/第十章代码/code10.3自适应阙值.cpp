#include <iostream>
using namespace std;
//input:
//0. 
//1. double fixed_threshold
//2. int threshold_type
//3. int adaptive_method
//4. int block_size
//5. double offset
//6. string imagepath
int main(int argc, char** argv) {
	if (argc != 7) {
		cout << "Usage: " << argv[0] 
			<< "fixed_threshold 
			<< "threshold_type(0=off|1=on)"
			<<"adaptive_method(0=mean|1=gaussian)"
			<< "block_size"
			<< "offset"
			<< "imagepath\n"
			<<"Example: " << argv[0] << " 100 1 0 15 10 fruits.jpg\n";
		return -1;
	}
	// atof:convert string to double
	// atoi:convert string to integer
	double fixed_threshold = (double)atof(argv[1]);
	int threshold_type = atoi(argv[2]) ? cv::THRESH_BINARY : cv::THRESH_BINARY_INV;
	int adaptive_method = atoi(argv[3]) ? cv::ADAPTIVE_THRESH_MEAN_C : cv::ADAPTIVE_THRESH_GAUSSIAN_C;
	int block_size = atoi(argv[4]);
	double offset = (double)atof(argv[5]);
	cv::Mat Igray = cv::imread(argv[6], cv::LOAD_IMAGE_GRAYSCALE);
	if (Igray.empty()) {
		cout << "Can not load " << argv[6] << endl;
		return -1;
	}
	cv::Mat Imaget, ImageAt;
	cv::threshold(Igray, ImageAt, fixed_threshold, 255, threshold_type);
	cv::adaptiveThreshold(Igray, ImageAt, 255, adaptive_method, threshold_type, block_size, offset);
	cv::imshow("Raw", Igray);
	cv::imshow("Threshold", Imaget);
	cv::imshow("Adaptive Threshold", ImageAt);
	cv::waitKey(0);
	return 0;


}