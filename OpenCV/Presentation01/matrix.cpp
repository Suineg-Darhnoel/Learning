#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


int main()
{
    cv::Mat e = cv::Mat::eye(3, 3, CV_8UC1);
    e.at<uchar>(2, 1) = 3;
    std::cout << e << '\n';
    std::cout << e.t() << '\n';
    return 0;
}
