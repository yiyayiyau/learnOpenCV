// code2-5 加载图像,并添加平滑处理

#include <opencv2/opencv.hpp>

void example2_5(const cv::Mat & image){
    // Create some windows to show the input and output images in.
    cv::namedWindow("Example2_5-in", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Example2_5-out", cv::WINDOW_AUTOSIZE);
    
    cv::imshow("Example2_5-in", image);
    cv::Mat out;
    // GaussianBlur(), blur(), medianBlur(), bilateralFilter()
    cv::GaussianBlur( image, out, cv::Size(5,5), 3,3);
    cv::GaussianBlur( out, out, cv::Size(5,5), 3,3); // 两次模糊操作
    
    cv::imshow("Example2_5-out", out);
    cv::waitKey(0);
    
    destory();
}
