#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <cmath>

#include "myFunc.hpp"

int main()
{
    cv::Mat img = cv::imread("../data/imori.jpg");

    // BGR to HSV
    cv::Mat hsv = BGR2HSV(img);
    cv::Mat mask;
    cv::Mat out;

    mask = getMask(hsv, 180, 260);
    cv::imshow("original img", img);
    cv::imshow("mask", mask);

    /* cv::imwrite("Results/mask_img.png", mask); */
    /* cv::imwrite("Results/inv_mask_img.png", (255-mask)); */

    out = setMask(img, mask);

    cv::imshow("masked img", out);
    /* cv::imwrite("Results/masked_img.png", out); */

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
