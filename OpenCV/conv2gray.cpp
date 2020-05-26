#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

cv::Mat toGray(cv::Mat& origImg)
{
    int rows = origImg.rows;
    int cols = origImg.cols;

    cv::Mat out = cv::Mat::zeros(rows, cols, CV_8UC1);

    for (int row = 0; row < rows; row++){
        for (int col = 0; col < cols; col++){
            out.at<uchar>(row, col) = 
                0.2126*(float)origImg.at<cv::Vec3b>(row, col)[2]
            +   0.7152 * (float)origImg.at<cv::Vec3b>(row, col)[1] 
            +   0.0722 * (float)origImg.at<cv::Vec3b>(row, col)[0];
        }
    }
    return out;
}


int main()
{
    cv::Mat img = cv::imread("data/lena.jpg");
    cv::Mat cvtImg = toGray(img);

    cv::imshow("Grayscale Image", cvtImg);
    cv::waitKey(0);
    
    return 0;
}
