#include <iostream>
#include <opencv2/core.hpp> // Mat
#include <opencv2/highgui.hpp> // imshow
#include <opencv2/imgproc.hpp> // cvtColor
#include <vector>

int main()
{
    cv::Mat img = cv::imread("data/smarties.png");
    cv::Mat imgray;
    cv::cvtColor(img, imgray, cv::COLOR_BGR2GRAY);

    cv::Mat truncate;
    cv::threshold(imgray, truncate, 127, 150, cv::THRESH_BINARY);

    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

    cv::findContours(
                truncate,
                contours,
                hierarchy,
                cv::RETR_TREE,
                cv::CHAIN_APPROX_SIMPLE
            );

    cv::imshow("Truncate", truncate);

    std::cout << "Number of contours = " << contours.size() << '\n';

    cv::Scalar black = cv::Scalar(0, 0, 0);
    cv::drawContours(img, contours, -1, black);

    cv::imshow("Image", img);
    /* cv::imshow("Image GRAY", imgray); */
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
