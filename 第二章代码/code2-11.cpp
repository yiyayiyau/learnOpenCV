#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv){
    
    cv::namedWindow( "example2-11", cv::WINDOW_AUTOSIZE );
    cv::namedWindow( "Log_polar", cv::WINDOW_AUTOSIZE );
    // 如果给的是一个整数的话,将会连接对应的摄像镜头,如果是字符串,将是视频
    cv::VideoCapture capture( argv[1] );
    
    double fps = capture.get( cv::CAP_PROP_FRAME_FPS);
    cv::Size size( (int)capture.get( cv::CAP_PROP_FRAME_WIDTH),
        (int)capture.get( cv::CAP_PROP_FRAME_HEIGHT) );
    
    cv::VideoWriter writer;
    writer.open( argv[2], CV_FOURCC('M','J','P','G'), fps, size);//MJPG 是一种编码器,与OpenCV是分开安装的
    
    cv::Mat logpolar_frame, bgr_frame;
    for(;;){
        capture >> bgr_frame;
        if (bgr_frame.empty()) break;
        
        cv::imshow("example2-11", bgr_frame);
        
        //cv::logPolar(Input, output, CenterPointer(x,y), Magnitude, Fill outliers with 'zero');
        cv::logPolar(bgr_frame, logpolar_frame, cv::Point2f(bgr_frame.cols/2, bgr_frame.rows/2), 40, cv::WARP_FILL_OUTLIERS);
        cv::imshow("Log_polar", logpolar_frame);
        
        char C = cv::waitKey(10);
        if ( C==27 ) break; //ESC
    }

    capture.release();
    return 0;
}
