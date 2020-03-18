// Canny 边缘检测
#include <opencv/opencv.hpp>

int main(int argc, char** argv){
    cv::Mat img_rgb, img_gry, img_cny;
    
    cv::namedWindow("Example1", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Example2", cv::WINDOW_AUTOSIZE);
    
    img = cv::imread( argv[1] );
    
    cv::cvtColor(img_rgb, img_gry, cv::COLOR_BGR2GRAY);
    cv::imshow("Example1", img_gry);
    
    cv::Canny( img_gry, img_cny, 10, 100, 3, true);
    cv::imshow("Example2", img_cny);
    
    cv::waitKey(0);
    return 0;
}
