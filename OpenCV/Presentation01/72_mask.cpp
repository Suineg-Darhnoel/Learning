#include <iostream>
#include <cmath>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "myFunc.hpp"

int main()
{
    cv::Mat img = cv::imread("../data/imori.jpg");
    cv::Mat imgGray;
    cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);

    cv::Mat closed_image, opened_image;

    cv::Mat hsv = BGR2HSV(img);
    cv::Mat mask = getMask(hsv);

    closed_image = closing(mask, 5);
    opened_image = opening(closed_image, 5);
    cv::Mat out = setMask(img, opened_image);

    cv::imshow("closed image", closed_image);
    cv::imshow("opened image", opened_image);
    cv::imshow("Output", out);

    /* cv::imwrite("Results/opening_closing_mask.png", opened_image); */
    /* cv::imwrite("Results/opening_closing_out.png", out); */

    // output files
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
