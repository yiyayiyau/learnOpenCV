// src: https://blog.csdn.net/qiao_lili/article/details/83590593
// 判断一个轮廓是否在一个矩形中 提取一个轮廓的四角点 左上 右下 左下 右上 分别判断这四个点是否在该矩形中 
// C++: double pointPolygonTest(InputArray contour, Point2f pt, bool measureDist)
// It returns positive (inside), negative (outside), or zero (on an edge) value, correspondingly. 
// When measureDist=false , the return value is +1, -1, and 0, respectively. 
// Otherwise, the return value is a signed distance between the point and the nearest contour edge
static bool lessP(const Point &lhs, const Point &rhs)
{
    return (lhs.x < rhs.x) || ((lhs.x == rhs.x) && (lhs.y < rhs.y));
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
        v1.copyTo(v3);

        sort(v3.begin(), v3.end(), lessP);
        Mat(v3.front()).convertTo(p1, p1.type()); // convert Point to Point2f
        v2.push_back(p1);//left bottom
        Mat(v3.back()).convertTo(p2, p2.type());
        v2.push_back(p2);// right oben

        sort(v3.begin(), v3.end(), greaterP);
        Mat(v3.front()).convertTo(p3, p3.type());
        v2.push_back(p3);//left oben
        Mat(v3.back()).convertTo(p4, p4.type());
        v2.push_back(p4);// right bottom
    }
    return v2;    

}

void main()
{
//use findContours get cContours and use selectROI get ignoreare
    vector<Point2f> boundPoints = boundPoint(cContours[i]);
    double inside_d = 1;
    for (size_t idx = 1, idx < boundPoints.size(), idx++)
    {
        double inside_d1 = pointpolygonTest(ignoreare, boundPoints[idx], false);
        inside_d += inside_d1;
    }
    if (inside_d -4 < 1e-2)
    {
        cout<<"the contour is inside of the Rectangle";
    }
 }
