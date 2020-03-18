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

img_cny.at<uchar>(y, x) = 128; // set the canny pixel there to 128

