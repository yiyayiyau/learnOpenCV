#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


using namespace std;
using namespace cv;

void Sharpen(const Mat& myImage, Mat& Result);
int main(int argc, char* argv[])
{
	string filename = cv::samples::findFile("lena.jpg");

	Mat src, dst0, dst1;
	src = imread(filename, IMREAD_COLOR);

	if (src.empty())
	{
		cerr << "没有找到图片" << filename << endl;
		return EXIT_FAILURE;
	}

	namedWindow("input", WINDOW_AUTOSIZE);
	namedWindow("output", WINDOW_AUTOSIZE);
	imshow("input", src);
	
	double t = (double)getTickCount();
	Sharpen(src, dst0);

	t = ((double)getTickCount() - t) / getTickFrequency();
	cout << "自定义函数运行时间" << t << endl;

	imshow("output", dst0);
	waitKey();

	// 创建一个滤波器的mask
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	t = (double)getTickCount();
	filter2D(src, dst1, src.depth(), kernel);//滤波

	t = ((double)getTickCount() - t) / getTickFrequency();
	cout << "内置函数运行时间" << t << endl;
	imshow("output", dst1);
	waitKey();
	return EXIT_SUCCESS;
}

void Sharpen(const Mat& myImage, Mat& Result)
{
	CV_Assert(myImage.depth() == CV_8U);
	const int nChannels = myImage.channels();
	Result.create(myImage.size(), myImage.type());

	for (int j = 1; j < myImage.rows - 1; ++j)
	{
		const uchar* previous = myImage.ptr<uchar>(j - 1);
		const uchar* current = myImage.ptr<uchar>(j);
		const uchar* next = myImage.ptr<uchar>(j + 1);

		uchar* output = Result.ptr<uchar>(j);

		for (int i = nChannels; i < nChannels * (myImage.cols - 1); ++i)
		{
			//保护溢出
			*output++ = saturate_cast<uchar>(5 * current[i]
				- current[i - nChannels] - current[i + nChannels] 
				- previous[i] - next[i]);
		}

	}
	//边界处理,这里设为0
	Result.row(0).setT(Scalar(0));
	Result.row(Result.rows-1).setT(Scalar(0));
	Result.col(0).setT(Scalar(0));
	Result.row(Result.cols-1).setT(Scalar(0));
}