//source: https://docs.opencv.org/4.1.2/db/deb/tutorial_display_image.html
//https://zhuanlan.zhihu.com/p/92493705
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
using namespace cv;
using namespace std;
int main(int argc, char** argv)
{
	String imageName("HappyFish.jpg"); // String imageName("D:/....jpg");
	imageName = samples::findFile(imageName);

	Mat image;
	image = imread(imageName, IMREAD_COLOR);
	if (image.empty())
	{
		cout << "没有找到图片" << std::endl;
		return -1;
	}

	namedWindow("display window", WINDOW_AUTOSIZE);
	imshow("display window", image);
	waitKey(0);
	return 0;
}