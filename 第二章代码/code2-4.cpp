// open a film with trackbar
// g_run = 1 单步模式, 只读取一张图片
// g_run = -1, -2,... 连续视频模式
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <fstream>

using namespace std;
// 添加全局变量来表示滑动条的位置,并且添加一个回调函数来更改这个变量来重新定位读取的位置
int g_slider_position = 0;
int g_run = 1; //start out in single step mode 以单步模式开始
int g_dontset = 0; //避免在调整进度条的时候触发单步模式
cv::VideoCapture g_cap;

void onTrackbarSlide( int pos, void *){
    // 当视频前进的时候,滑动条也跟着前进, 并且不会触发单步模式
    // 调整滑动条位置
    g_cap.set(cv::CAP_PROP_POS_FRAMES, pos); 
    
    if(!g_dontset)// 一旦触发滑动条事件,该设置生效,避免触发单步模式
        g_run = 1;// 跳转之后, g_run = 1, 跑一步之后, g_run = 0, 停止等待用户输入模式
    g_dontset = 0;
}

int main(int argc, char** argv){
    cv::namedWindow("Example2_4", cv::WINDOW_AUTOSIZE);
    
    g_cap.open( string(argv[1]) );
    int frames = (int) g_cap.get(cv::CAP_PROP_FRAME_COUNT);
    int tmpw = (int) g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
    int tmph = (int) g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    cout << "Video has " << frames <<" frames of dimensions (" << temw << " , " << temh << ")." <<endl;
    // 创建一个滑动条,指明窗口,设置总frame数,以及在滑动条移动的时候的回调函数
    cv::createTrackbar("Position", "Example2_4", &g_slider_position, frames, onTrackbarSlider);
    cv::Mat frame;
    for(;;){
        if( g_run!= 0){
            g_cap >> frame;
            if (frame.empty()) break;
            int current_pos = (int) g_cap.get(cv::CAP_PROP_POS_FRAMES);
            g_dontset = 1;
            
            cv::setTrackbarPos("Position", "Example2_4", current_pos);
            cv::imshow("Example2_4", frame);
            
            g_run -= 1; 
            
        }
        char C = (char) cv::waitKey(10);
        if ( C == 's' ) // sigle step
            {g_run = 1; cout << "Single step, run = " << g_run << endl;}
        if ( C == 'r') // run mode
            {g_run = -1; cout << "Run mode, run = " << g_run << endl;}
        if ( C == 27) break;
    }
    return 0;
}
 
