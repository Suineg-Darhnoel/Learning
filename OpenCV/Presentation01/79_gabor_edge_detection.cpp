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

    std::string dir = "Results/";
    for (; angle <= 3*45; angle+=45){
        cv::Mat gaborKernel = getGaborKernel(ksize, sigma, angle, lambda, gamma, psi);
        cv::Mat out = filter2D(img, gaborKernel);
        // for expirimenting with big images
        if (img.rows * img.cols > 128 * 128)
            cv::resize(out, out, cv::Size(out.cols/2, out.rows/2));

        std::string windowName = std::to_string((int)angle) + "_out";
        cv::imshow(windowName, out);

        // write output to disk
        /* cv::imwrite(dir+windowName+".png", getMinMaxFilter(out)); */
    }


    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}

