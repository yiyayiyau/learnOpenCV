// 两次图像金字塔,即收缩图像后,使用Canny边缘检测
#include <opencv/opencv.hpp>

int main(int argc, char** argv){
    cv::Mat img_rgb, img_gry, img_cny;
    cv::Mat img_pyr, img_pyr2;
    
    cv::namedWindow("Example1", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Example2", cv::WINDOW_AUTOSIZE);
    
    img = cv::imread( argv[1] );
    
    cv::cvtColor(img_rgb, img_gry, cv::COLOR_BGR2GRAY);
    cv::pyrDown( img_gry, img_pyr );
    cv::pyrDown( img_pyr, img_pyr2 );
    cv::imshow("Example1", img_gry);
    
    cv::Canny( img_pyr2, img_cny, 10, 100, 3, true);
    cv::imshow("Example2", img_cny);
    
    cv::waitKey(0);
    return 0;
}
 
