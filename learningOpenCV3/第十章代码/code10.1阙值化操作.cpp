#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;

void sum_rgb(const cv::Mat& src, cv::Mat& dst)
{
	//split image onto the color planes
	vector<cv::Mat> planes;
	cv::split(src, planes);
	// add color-value with weight, might be over 255
	cv::Mat b = planes[0], g = planes[1], r = planes[2], s;
	cv::addWeighted(r, 1./3., g, 1./3., 0.0, s);
	cv::addWeighted(s, 1., b, 1./3., 0.0, s);

	cv::threshold(s, dst, 100, 100, cv::THRESH_TRUNC);

}
void help() {
	cout << "Call: ./ch10_ex10_1 faceScene.jpg" << endl;
	cout << "Shows use of alpha blending (addWeighted) and threshold" << endl;
}

int main(int arg, char** argv) {
	help();
	if (argc < 2) {
		cout << "specify input image" << endl;
		return -1;
	}
	cv::Mat src = cv::imread(argv[1]), dst;
	if (src.empty()) {
		cout << "Can not load " << argv[1] << endl;
		return -1;
	}
	sum_rgb(src, dst);
	cv::imshow(argv[1], dst);
	cv::waitKey(0);
	return 0;
}