#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv){
    cv::namedWindow("Example2-10", WINDOW_AUTOSIZE);
    cv::VideoCapture cap;
    if (argc==1){cap.open(0);} // 0: the first camera; -1: random a camara
    else {cap.open(argv[1])}
    if ( !cap.isOpened()){
        std::cerr << "Couldn't open capture." << std:endl;
        return -1;
    }
    //------------------------------------the same as code2-3/code2-4
    cv::Mat frame;
    for(;;){
        cap >> frame;
        if ( frame.empty() ) break;
        cv::imshow( "Example2-10", frame );
        if ( cv::waitKey(33) >= 0 ) break;
    }
    return 0;
}
