#include <iostream>
#include <ctime>
#include <stdint.h>
#include <opencv2/opencv.hpp>


int main()
{
    cv::Mat gray = cv::imread("data/imori.jpg", cv::COLOR_BGR2GRAY);
    cv::Mat binary;

    time_t start_time, end_time;

    time(&start_time);
    cv::threshold(gray, binary, 100, 255, cv::THRESH_BINARY);
    for (int i = 0; i < 10000000; i++)
        std::cout << ".";
    time(&end_time);

    std::cout << "Threshold processing time: " << difftime(end_time, start_time) << '\n';
    
    return 0;
}
