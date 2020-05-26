#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat test = cv::imread("data/cat.jpg", cv::IMREAD_UNCHANGED);
    return 0;
}
