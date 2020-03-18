
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
    //--------------------------------------------
    // fortsetzen code2-8
    int x = 16, y = 32;
    cv::Vec3b intensity = img_rgb.at< cv:: Vec3b> (y, x);

    uchar blur = intensity[0];
    uchar green = intensity[1];
    uchar red = intensity[2];

    std::cout <<"At (x,y) = (" << x << "," << y <<"): (blue, green, red) = (" << (unsigned int) blue <<
    (unsigned int) green << (unsigned int) red << ")" << std::endl;
    std::cout <<"Gray pixel there is: " << (unsigned int)img_gry.at<uchar>(y, x) << std::endl;

    x/=4;
    y/=4;
    std:cout << "Pyramid2 pixel there is: " << (unsigned int)img_pyr2.at<uchar>(y, x) << std::endl;
    
    // original in book: img_cny.at<uchar>(x, y) = 128; ?? error?
    img_cny.at<uchar>(y, x) = 128; // set the canny pixel there to 128
    //---------------------------------------------------------
    std::cout <<"(y, x) is "<< img_cny.at<uchar>(y, x)<< std::endl;
    std::cout <<"(x, y) is "<< img_cny.at<uchar>(x, y)<< std::endl;
    
    cv::waitKey(0);
    return 0;
}
