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

    cv::Mat closed_image, opened_after_closed;

    cv::Mat hsv = BGR2HSV(img);
    cv::Mat mask = getMask(hsv, 200, 360);
    cv::imshow("mask", mask);

    closed_image = closing(mask, 2);
    opened_after_closed = opening(closed_image, 6);
    cv::imshow("opened_after_closed", opened_after_closed);
    /* cv::Mat out = erode(mask, 1); */

    /* for (int i = 1; i < 3; i++){ */
    /*     for (int j = 1; j < 10; j++){ */
    /*         closed_image = closing(mask, i); */
    /*         opened_after_closed = opening(closed_image, j); */
    /*         cv::Mat out = setMask(img, opened_after_closed); */

    /*         std::string id_i = std::to_string(i); */
    /*         std::string id_j = std::to_string(j); */
    /*         std::string closedName = id_i + "_" + id_j + "_closed_image"; */
    /*         std::string openedName = id_i + "_" + id_j + "_opened_image"; */
    /*         std::string outName = id_i + "_" + id_j + "_out"; */

    /*         /1* cv::imshow(closedName, closed_image); *1/ */
    /*         /1* cv::imshow(openedName, opened_after_closed); *1/ */
    /*         cv::imshow(outName, out); */
    /*     } */
    /* } */

    // output files
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
