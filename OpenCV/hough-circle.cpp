#include <iostream>
#include <vector>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main(int argc, char** argv)
{
    cv::Mat img, img_gray;
    img = cv::imread(argv[1], 1);

    if (img.empty())
        return -1;

    cv::cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);

    cv::GaussianBlur(img_gray, img_gray, cv::Size(9, 9), 2, 2);

    std::vector<cv::Vec3f> circles;
    cv::HoughCircles(img_gray, circles, cv::HOUGH_GRADIENT, 1, img_gray.rows/8, 200, 100, 0, 0);

    cv::imshow("Gray Image", img_gray);
    std::cout << circles.size();

    for (size_t i = 0; i < circles.size(); i++){
        cv::Point center(
                    cvRound(circles[i][0]), 
                    cvRound(circles[i][1])
                );
        int radius = cvRound(circles[i][2]);
        // circle center
        cv::circle(
                img, 
                center, 
                3, 
                cv::Scalar(0, 255, 0), 
                -1, 8, 0);

        // circle outline
        cv::circle(
                img, 
                center, 
                radius, 
                cv::Scalar(0, 0, 255), 
                3, 8, 0);
    }

    cv::namedWindow("Hough Circle Transform Demo", cv::WINDOW_AUTOSIZE);
    cv::imshow("Hough Circle Transform Demo", img);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
