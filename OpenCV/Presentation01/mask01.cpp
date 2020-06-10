#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <cmath>

cv::Mat BGR2HSV(cv::Mat img)
{
    int width = img.cols;
    int height = img.rows;

    float r, g, b;
    float h, s, v;
    float Max, Min;

    // Output
    cv::Mat hsv = cv::Mat::zeros(height, width, CV_32FC3);

    // Process through each pixel
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            // BGR -> HSV
            r = (float)img.at<cv::Vec3b>(y, x)[2] / 255;
            g = (float)img.at<cv::Vec3b>(y, x)[1] / 255;
            b = (float)img.at<cv::Vec3b>(y, x)[0] / 255;

            Max = std::fmax(r, std::fmax(g, b));
            Min = std::fmin(r, std::fmin(g, b));

            // get Hue
            if (Min == b){
                h = 60 * (g-r) / (Max - Min) + 60;
            }
            else if (Min == r){
                h = 60 * (b-g) / (Max - Min) + 180;
            }
            else if (Min == g){
                h = 60 * (r-b) / (Max - Min) + 300;
            }
            else{
                // Min == Max
                h = 0;
            }

            // get Saturation
            s = Max - Min;

            // get Value
            v = Max;

            hsv.at<cv::Vec3f>(y, x)[0] = h;
            hsv.at<cv::Vec3f>(y, x)[1] = s;
            hsv.at<cv::Vec3f>(y, x)[2] = v;
        }
    }
    return hsv;
}

void getMask(cv::Mat hsv, cv::Mat mask, int hueLow=180, int hueHigh=260)
{
    int height = hsv.rows;
    int width = hsv.cols;

    hueLow = std::fmax(0, hueLow);
    hueHigh = std::fmin(hueHigh, 260);
    double h;
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            h = (double)hsv.at<cv::Vec3f>(y, x)[0];
            if (h <= hueHigh && h >= hueLow){
                mask.at<uchar>(y, x) = 1;
            }
        }
    }
}

void setMask(cv::Mat img, cv::Mat _mask, cv::Mat out){
    cv::Mat mask = 1 - _mask;
    int height = img.rows;
    int width = img.cols;

    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            // loop through BGR
            for (int i = 0; i < 3; i++)
                out.at<cv::Vec3b>(y, x)[i] = mask.at<uchar>(y, x) * out.at<cv::Vec3b>(y, x)[i];
        }
    }
}

int main()
{
    cv::Mat img = cv::imread("../data/imori.jpg");

    // BGR to HSV
    cv::Mat hsv = BGR2HSV(img);
    cv::Mat mask = cv::Mat::zeros(img.size(), CV_8U);
    cv::Mat out;

    getMask(hsv, mask, 180, 260);
    cv::imshow("original img", img);
    cv::imshow("mask", mask*255);

    cv::imwrite("Results/mask_img.png", mask*255);
    cv::imwrite("Results/inv_mask_img.png", (1-mask)*255);
    // why put this line into the function
    // setMask implied core dump?
    img.copyTo(out);
    setMask(img, mask, out);

    cv::imshow("masked img", out);
    cv::imwrite("Results/masked_img.png", out);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
