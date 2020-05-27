#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <cmath>


int main()
{
    cv::Mat img = cv::imread("data/eye2.jpg");
    if (img.empty())
        return -1;

    cv::Mat grayImg;
    cv::cvtColor(img, grayImg, cv::COLOR_BGR2GRAY);

    // Binarization
    cv::threshold(grayImg, grayImg, 200, 255, cv::THRESH_BINARY);
    cv::imshow("Thresholded Image", grayImg);

    // Find all contours
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(grayImg.clone(), contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);

    // fill holes in each contour
    cv::drawContours(
                grayImg, 
                contours, 
                -1, 
                cv::Scalar(255, 255, 255), 
                -1
            );
    for (int i = 0; i < int(contours.size()); i++)
    {
        double area = cv::contourArea(contours[i]);
        cv::Rect rect = cv::boundingRect(contours[i]);
        int radius = rect.width/2;

        // If contour is big enough and has round shape
        // The it is the pupil
        if (area >= 30 
            &&std::abs(1-((double)rect.width / (double)rect.height)) <= 0.2 
            &&std::abs(1-(area/(CV_PI * std::pow(radius, 2)))) <= 0.2
                )
        {
            cv::circle(img, cv::Point(rect.x + radius, rect.y + radius), radius, cv::Scalar(255,0,0), 2);
        }
    }

    cv::imshow("image", img);

    /* cv::imshow("canny image", cannyImg); */
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
