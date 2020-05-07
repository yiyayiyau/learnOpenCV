#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
int main(int argc, char** argv) {
	if (argc != 2) {
		cout << "Warp affine\nUsage: " << argv[0] << " <imagename>\n" << endl;
		return -1;
	}
	cv::Mat src = cv::imread(argv[1], 1);
	if (src.empty()) {
		cout << "Can not load" << argv[1] << endl;
		return -1;
	}
	cv::Point2f srcTri[] = {
		cv::Point2f(0,0),			// Src Top left
		cv::Point2f(src.cols-1,0),	// src Top right
		cv::Point2f(0,src.rows-1)	// src Bottom left
	}
	cv::Point2f dstTri[] = {
		cv::Point2f(src.cols*0.f, src.rows*0.33f), //dst Top left
		cv::Point2f(src.cols*0.85f, src.rows*0.25f), //dst Top right
		cv::Point2f(src.cols*0.15f, src.rows*0.7f)	//dst Bottom left
	}
	// compute Affine Matrix
	cv::Mat warp_mat = cv::getAffineTransform(srcTri, dstTri);
	cv::Mat dst, dst2;
	cv::warpAffine(src, dst, warp_mat, src.size(), cv::INTER_LINEAR,
		cv::BORDER_CONSTANT, cv::Scalar());
	for (int i = 0; i < 3; ++i)
		cv::circle(dst, dstTri[i], 5, cv::Scalar(255, 0, 255), -1 cv::AA)
		cv::imshow("Affine Transform Test", dst);
	cv::waitKey();
	for (int frame = 0;; ++frame) {
		//compute rotation matrix
		cv::Point2f center(src.cols * 0.5f, src.rows * 0.5f);
		double angle = frame * 3 % 360;
		double scale = (cos((angle - 60) * cv::PI / 180) + 1.05) * 0.8;
		cv::Mat rot_mat = cv::getRotationMatrix2D(center, angle, scale);
		cv::warpAffine(src, dst, rot_mat, src.sie(), cv::INTER_LINEAR,
			cv::BORDER_CONSTANT, cv::Scalar());
		cv::imshow("Rotated Image", dst);
		if (cv::waitKey(30) >= 0)
			break;
	}
	return 0;
}