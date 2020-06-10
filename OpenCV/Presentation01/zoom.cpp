#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

cv::Mat zoomIn_color(cv::Mat img, int zoomSize=2)
{
    int z_imh = zoomSize * img.rows;
    int z_imw = zoomSize * img.cols;

    cv::Mat zoomImg = cv::Mat::zeros(z_imh, z_imw, CV_8UC3);
    for (int y = 0; y < z_imh; y++){
        for (int x = 0; x < z_imw; x++){
            int b = img.at<cv::Vec3b>(y/zoomSize, x/zoomSize)[0];
            int g = img.at<cv::Vec3b>(y/zoomSize, x/zoomSize)[1];
            int r = img.at<cv::Vec3b>(y/zoomSize, x/zoomSize)[2];
            zoomImg.at<cv::Vec3b>(y, x)[0] = b;
            zoomImg.at<cv::Vec3b>(y, x)[1] = g;
            zoomImg.at<cv::Vec3b>(y, x)[2] = r;
        }
    }
    return zoomImg;
}

cv::Mat zoomIn_gray(cv::Mat img, int zoomSize=2)
{
    int z_imh = zoomSize * img.rows;
    int z_imw = zoomSize * img.cols;

    cv::Mat zoomImg = cv::Mat::zeros(z_imh, z_imw, CV_8UC1);
    for (int y = 0; y < z_imh; y++){
        for (int x = 0; x < z_imw; x++){
            zoomImg.at<uchar>(y, x) = img.at<uchar>(y/zoomSize, x/zoomSize);
        }
    }
    return zoomImg;
}

int main()
{
    cv::Mat img = cv::imread("../data/imori.jpg");
    cv::Mat grayImg;
    cv::cvtColor(img, grayImg, cv::COLOR_BGR2GRAY);

    cv::Mat colZoomImg = zoomIn_color(img, 5);
    cv::Mat zoomImg = zoomIn_gray(grayImg, 5);

    cv::imshow("zoomed image", zoomImg);
    cv::imshow("color zoomed image", colZoomImg);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
