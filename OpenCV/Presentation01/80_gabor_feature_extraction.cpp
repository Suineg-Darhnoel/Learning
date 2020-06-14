#include <iostream>
#include <cmath>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <queue>
#include "gaborLib.hpp"

int main()
{
    cv::Mat img = cv::imread("../data/imori.jpg", cv::IMREAD_GRAYSCALE);
    
    // getGaborKernel(ksize, sigma, angle, lambda, gamma, psi)
    int ksize = 11;
    double sigma = 1.5, angle = 0, lambda = 3, gamma = 1.2, psi = 0;

    std::vector<cv::Mat> gaborKernels;
    for (; angle <= 3*45; angle+=45){
        cv::Mat gbk = getGaborKernel(ksize, sigma, angle, lambda, gamma, psi);
        gaborKernels.push_back(gbk);
    }

    cv::Mat out = cv::Mat::zeros(img.rows, img.cols, CV_32F);
    double _, maxVal;
    for (auto gaborKernel : gaborKernels){
        out += filter2D(img, gaborKernel);
        cv::minMaxLoc(out, &_, &maxVal);
        out /= maxVal;
    }

    cv::imshow("out", out);
    // write output to disk
    cv::imwrite("Results/final_out.png", 255*out);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}

