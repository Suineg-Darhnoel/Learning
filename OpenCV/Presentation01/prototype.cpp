#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


int main()
{
    cv::Mat img = cv::imread("../data/imori.jpg");
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
