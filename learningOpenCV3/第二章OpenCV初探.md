# 第二章OpenCV初探
## 头文件
头文件位于modules文件夹中, 例如imgproc.hpp 存在于 .../modules/imgproc/include/opencv2/imgproc/imgproc.hpp
用哪个就调用哪个,不会减慢编译的速度

        #include "opencv2/core/core.hpp" // 结构及数学运算
        #include "opencv2/flann/miniflann.hpp" //最临近搜索匹配函数
        #include "opencv2/imgproc/imgproc.hpp" //图像处理函数
        #include "opencv2/video/photo.hpp" //操作和恢复照片相关算法
        #include "opencv2/video/video.hpp" //视觉追踪及背景分割
        #include "opencv2/features2d/features2d.hpp" //追踪二维特征
        #include "opencv2/objdetect/objdetect.hpp" //人脸分类器,SVM分类器,HoG特征和平面检测器
        #include "opencv2/calib3d/calib3d.hpp" //校准及双目视觉相关
        #include "opencv2/ml/ml.hpp" //机器学习,聚类及模式识别相关
        #include "opencv2/highgui/highgui.hpp" //显示,滑动条,鼠标操作及输入输出相关
        #include "opencv2/contrib/contrib.hpp" //皮肤检测,模糊Mean-Shift追踪,spin image算法及自相似特征
        //可以调用遗留代码,旧的斑点追踪,隐函马尔可夫模型检测,聚合追踪及特征目标
        #include "opencv2/legacy/legacy.hpp"

* code2-1, code2-2 显示图片
* code2-3 播放视频
* code2-4 播放视频,有进度条,单步和连续播放模式
* code2-5 加载图像,并添加平滑处理
* code2-6 加载图像
* code2-7 Canny边缘检测
* code2-8 两次图像金字塔,即收缩图像后,使用Canny边缘检测
* code2-9 读写像素值
* code2-10 连接摄像头
* code2-11 对数极坐标
