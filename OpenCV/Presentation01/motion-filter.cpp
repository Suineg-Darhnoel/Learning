#include <iostream>
#include <cmath>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

cv::Mat motionFilter(cv::Mat img)
{
    // try gray scale image
    int img_h = img.rows;
    int img_w = img.cols;
    int channels = img.channels();

    cv::Mat out = cv::Mat::zeros(img_h, img_w, CV_8UC3);
    for (int y = 0; y < img_h; y++){
        for (int x = 0; x < img_w; x++){

            for (int i = 0; i < channels; i++){
                int c = img.at<cv::Vec3b>((int)fmax(0, y-1), x)[i]
                    + img.at<cv::Vec3b>(y, x)[i]
                    + img.at<cv::Vec3b>(y, (int)fmin(img_w-1, x))[i];
                out.at<cv::Vec3b>(y, x)[i] =  (int)(c / 3.);
            }
        }
    }
    return out;
}

int main()
{
    cv::Mat img = cv::imread("../data/lena.jpg");
    cv::Mat out = motionFilter(img);

    cv::imshow("original", img);
    cv::imshow("out", out);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
