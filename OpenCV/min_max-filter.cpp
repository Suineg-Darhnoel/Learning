#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

cv::Mat BGR2GRAY(cv::Mat& img)
{
    int rows = img.rows;
    int cols = img.cols;
    // Output
    cv::Mat out = cv::Mat::zeros(rows, cols, CV_8UC1);
    
    // Formula : Y = 0.2126 R + 0.7152 G + 0.0722 B
    
    for (int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            out.at<uchar>(row, col) = 
                0.2126 * (float)img.at<cv::Vec3b>(row, col)[2]
                + 0.7152 * (float)img.at<cv::Vec3b>(row, col)[1]
                + 0.0722 * (float)img.at<cv::Vec3b>(row, col)[0];
        }
    }
    return out;
}

int main()
{
    cv::Mat img = cv::imread("data/lena.jpg");
    cv::Mat out = BGR2GRAY(img);

    cv::imshow("BGR2GRAY", out);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
