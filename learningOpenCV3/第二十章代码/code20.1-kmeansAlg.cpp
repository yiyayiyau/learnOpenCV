#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.cpp"
#include <iostream>
using namespace cv;
using namespace std;

static void help(char* argv[]) {
	cout << "\nThis programm demonstrates kmeans clustering.\n" <<
		"It generates an image with random points, then assigns a random number\n"
		<< "of cluster centers to their representative location\n" <<
		"Usage:\n" << argv[0] << "\n" << endl;

}
int main(int /*argc*/, char** /*argv*/)
{
	// first create cluster, and their centers, and create points(count is fest, gussian dist.)
	// around the ceters, and randomly shuffle the points
	// then look at whether kmeans with the strucktur works
	// label saves the tags of the calculate.
	const int MAX_CLUSTERS = 5;
	cv::Scalar colorTab[] = { cv::Scalar(0,0,255), cv::Scalar(0,255,0),
			cv::Scalar(255,100,100), cv::Scalar(255,0,255), cv::Scalar(0,255,255) };
	cv::Mat img(500, 500, CV_8UC3);
	cv::RNG rng(12345);
	for (;;) {
		int k, clusterCount = rng.uniform(2, MAX_CLUSTERS + 1);
		int i, sampleCount = rng.uniform(1, 1001);
		cv::Mat points(sampleCount, 1, CV_32FC2), labels;
		clusterCount = MIN(clusterCount, sampleCount);
		cv::Mat centers(clusterCount,1,points.type());

		/*generate random sample from multigaussian distribution*/
		for (k = 0; k < clusterCount; k++) {
			cv::Point center;
			center.x = rng.uniform(0, img.cols);
			center.y = rng.uniform(0, img.rows);
			cv::Mat pointChunk = points.rowRange(
				k * sampleCount / clusterCount,
				k == clusterCount - 1 ? sampleCount : (k + 1) * sampleCount / clusterCount);
			rng.fill(pointChunk, RNG::NORMAL,
				cv::Scalar(center.x, center.y), cv::Scalar(img.cols * 0.05, img.rows * 0.05));
		}
		randShuffle(points, 1, rng);
		kmeans(points, clusterCount, labels,
			cv::TermCriteria(cv::TermCriteria::EPS | cv::TermCriteria::COUNT, 10, 1.0),
			3, KMEANS_PP_CENTERS, centers);
		img = Scalar::all(0);
		for (i = 0; i < sampleCount; i++) {
			int clusterIdx = labels.at<int>(i);
			cv::Point ipt = points.at<cv::Point2f>(i);
			cv::circle(img, ipt, 2, colorTab[clusterIdx], cv::FILLED, cv::LINE_AA);
		}
		cv::imshow("clusters", img);
		char key = (char)waitKey();
		if (key == 27 || key == 'q' || key == 'Q')//'Esc
			break;

	}
	return 0;
}
