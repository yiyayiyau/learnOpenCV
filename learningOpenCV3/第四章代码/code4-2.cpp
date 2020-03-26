#include <opencv/opencv.hpp>

//使用N-ary将两个数组相加
const int n_mat_size = 5;
const int n_mat_sz[] = { n_mat_size, n_mat_size, n_mat_size };
cv::Mat n_mat0(3, n_mat_sz, CV32FC1);
cv::Mat n_mat1(3, n_mat_sz, CV32FC1);

cv::RNG rng;
rng.fill(n_mat0, CV::RNG::UNIFORM, 0.f, 1.f);
rng.fill(n_mat1, CV::RNG::UNIFORM, 0.f, 1.f);

const cv::Mat* arrays[] = { &n_mat0, &n_mat1, 0 };
cv::Mat my_planes[2];
cv::NAryMatIterator it(arrays, my_planes);

float s = 0.f;
int n = 0;
for (int p = 0; p < it.nplanes; p++, ++it)
{
	s += cv::sum(it.planes[0])[0];
	s += cv::sum(it.planes[1])[0];
	n++;
}


///////////////////////compute dst[*] = pow(src1[*],src2[*])/////////
const Mat* arrays[] = { src1, src2, dst, 0 };
float* ptrs[3];

cv::NAryMatIterator it(arrays, (uchar**)ptrs);
for (size_t i = 0; i < it.nplanes; i++, ++it) //面的数量
{
	for (size_t j = 0; j < it.size; j++)  //面的大小
	{
		ptr[2][j] = std::pow(ptrs[0][j], ptrs[1][j]);
	}
}