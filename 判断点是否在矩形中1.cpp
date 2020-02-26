// src: https://blog.csdn.net/qiao_lili/article/details/83590593
// 判断一个轮廓是否在一个矩形中 提取一个轮廓的四角点 左上 右下 左下 右上 分别判断这四个点是否在该矩形中 
// C++: double pointPolygonTest(InputArray contour, Point2f pt, bool measureDist)
// It returns positive (inside), negative (outside), or zero (on an edge) value, correspondingly. 
// When measureDist=false , the return value is +1, -1, and 0, respectively. 
// Otherwise, the return value is a signed distance between the point and the nearest contour edge
static bool lessP(const Point &lhs, const Point &rhs)
{
    return (lhs.x < rhs.x) || ((lhs.x == rhs.x) && (lhs.y > rhs.y));
};

static bool greaterP(const Point &ohs, const Point &bhs)
{
    return (ohs.y < bhs.y) || ((ohs.y == bhs.y) && (ohs.x < bhs.x));
};

vector<Point2f> boundPoint(vector<Point> v1)
{
    vector<Point2f> v2, v3;
    Point2f p1, p2, p3, p4;
    if (!v1.empty())
    {
        copy(v1.begin(), v1.end(), back_inserter(v3));
        //https://www.geeksforgeeks.org/ways-copy-vector-c/

        sort(v3.begin(), v3.end(), lessP);
        //Mat(v3.front()).convertTo(p1, p1.type()); // convert Point to Point2f
        //v2.push_back(p1);//left bottom
        v2.push_back(v3.front());//left bottom
        //Mat(v3.back()).convertTo(p2, p2.type());
        //v2.push_back(p2);// right oben
        v2.push_back(v3.back());// right oben

        sort(v3.begin(), v3.end(), greaterP);
        //Mat(v3.front()).convertTo(p3, p3.type());
        //v2.push_back(p3);//left oben
        v2.push_back(v3.front());//left oben
        //Mat(v3.back()).convertTo(p4, p4.type());
        //v2.push_back(p4);// right bottom
        v2.push_back(v3.back());// right bottom
    }
    return v2;    

}

void main()
{
    // readImage
    Mat referenceimage = imread(referenceimagename);
    namedWindow("referenceimage/selectROI", WINDOW_NORMAL);
    imshow("referenceimage/selectROI", referenceimage);
    waitKey(0);
    // use selectROI get ignoreare
    rect_area = selectROI("referenceimage/selectROI", referenceimage);
    LOG(INFO) << "recht_area is " << rect_area;
    Point2f lt, lb, rb, rt;
    lt = rect_area.tl(); 
    lb = Point2f(rect_area.x, rect_area.y + rect_area.height);
    rt = Point2f(rect_area.x + rect_area.width, rect_area.y);
    rb = rect_area.br();
    Point2f corners[4] = {lt, lb, rb, rt};
    Point2f *lastItemPointer = (corners+sizeof(corners)/sizeof(corners[0]));
    // LOG(INFO) << "lastItemPointer" << lastItemPointer;
    vector<Point2f> ignoreare(corners, lastItemPointer);
    
    namedWindow("ignore area", WINDOW_NORMAL);
    imshow("ignore area", ignoreare);
    waitKey(0);
    // find Contours
    Mat grayImage, binarizedImage; 
    blur(referenceimage, grayImage, Size(3,3));
    // threshold(grayImage, binarizedImage, thresh, 255, THRESH_BINARY);
    Canny(grayImage, binarizedImage, thresh, maximun_thresh,3);
    vector<vector<Point>> contours_v;
    vector<Vec4i> hierarchy;
    findContours(binarizedImage, contours_v, hierarchy, RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE, Point(0,0));
    vector<Point2f> boundPoints = boundPoint(contours_v[i]);
    
    double inside_d = 0;
    for (size_t idx = 0, idx < boundPoints.size(), idx++)
    {
        double inside_d1 = pointPolygonTest(ignoreare, boundPoints[idx], false);
        inside_d += inside_d1;
    }
    if (inside_d ==4)
    {
        cout<<"the contour is inside of the Rectangle";
    }
 }
