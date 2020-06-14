#ifndef GABOR_H
#define GABOR_H
#include <iostream>
#include <opencv2/core.hpp>

cv::Mat getGaborKernel(
            int K=11, 
            double sigma=1.5, // 1.5
            double angle=0,
            double lamda=3, // 3
            double gamma=1.2, // 1.2
            double psi=0
        )
{
    /* Formula for Gabor Kernel */
    // x' = cosA * x + sinA * y
    // y' = -sinA * x + cosA * y
    // G(y, x) = exp(-(x'^2 + g^2 y'^2) / 2 s^2) * cos(2 pi x' / l + p)

    /* Kernel's size has to be odd */
    assert (K % 2 != 0);

    double gabor;
    int d = K/2; // distance from center of the kernel
    cv::Mat out = cv::Mat::zeros(K, K, CV_64F);

    for (int y = 0; y < K; y++){
        for (int x = 0; x < K; x++){

            double theta = (angle / 180) * CV_PI;
            int cx = x - d;
            int cy = y - d;
            double co = std::cos(theta);
            double si = std::sin(theta);
            // kernel x and kernel y
            double kx = co*cx + si*cy;
            double ky = -si*cx + co*cy;

            // compute for each pixel
            gabor = std::exp(-(kx*kx + gamma*gamma * ky*ky)/(2 * sigma*sigma)) 
                * std::cos(2 * CV_PI * kx/lamda + psi); 
            out.at<double>(y, x) = gabor;
        }
    }

    return out;
}

// [0, 255] Normalization
cv::Mat getNormalizedKernel(cv::Mat kernel){
    double minVal, maxVal;
    cv::minMaxLoc(kernel, &minVal, &maxVal);

    double range = maxVal - minVal;
    double unit = range/255;

    int k_h = kernel.rows;
    int k_w = kernel.cols;
    cv::Mat out = cv::Mat::zeros(k_h, k_w, CV_8UC1);

    for (int y = 0; y < k_h; y++){
        for (int x = 0; x < k_w; x++){
            float val = kernel.at<double>(y, x);
            out.at<uchar>(y, x) = (uchar)std::round((val - minVal)/unit);
        }
    }
    return out;
}

cv::Mat filter2D(cv::Mat img, cv::Mat kernel)
{
    int k_size = kernel.rows;
    int img_h = img.rows;
    int img_w = img.cols;

    // distance from center to its frame of the kernel
    int pad = k_size / 2;
    double val;

    cv::Mat result = cv::Mat::zeros(img_h, img_w, CV_64F);
    // loop through each pixel
    for (int y = 0; y < img_h; y++){
        for (int x = 0; x < img_w; x++){
            val = 0;
            // cp image block
            for (int py = -pad; py < pad+1; py++){
                for (int px = -pad; px < pad+1; px++){
                    if ((px + x >= 0) 
                        && (py + y >= 0) 
                        && (px + x < img_w) 
                        && (py + y < img_h))
                    {
                        uchar imgPixel = img.at<uchar>(y+py, x+px);
                        val += kernel.at<double>(py+pad, px+pad) * imgPixel;
                    }
                }
            }
            /* std::cout << val << '\n'; */
            result.at<double>(y, x) = val;
        }
    }

    // Normalize [0, 255] and Prepare for output
    cv::Mat out = cv::Mat::zeros(img_h, img_w, CV_8UC1);

    double minVal, maxVal;
    cv::minMaxLoc(result, &minVal, &maxVal);

    double range = maxVal - minVal;
    double unit = range / 255;
    /* printf("range = %lf, unit = %lf\n", range, unit); */

    for (int y = 0; y < img_h; y++){
        for (int x = 0; x < img_w; x++){
            // get the computed value
            val = result.at<double>(y, x);
            uchar rval = (uchar)std::round((val - minVal)/unit);
            out.at<uchar>(y, x) = rval;  
        }
    }

    return out;
}

cv::Mat getMinMaxFilter(cv::Mat img, int k_size = 3)
{
    int img_h = img.rows;
    int img_w = img.cols;
    int d = k_size/2;

    cv::Mat out = cv::Mat::zeros(img_h, img_w, CV_8UC1);
    for (int y = 0; y < img_h; y++){
        for (int x = 0; x < img_w; x++){
            int vmax = 0;
            int vmin = 999;
            for (int py = -d; py < d + 1; py++){
                for (int px = -d; px < d + 1; px++){
                    if (
                            (y + py >= 0)
                            && (x + px >= 0)
                            && (y + py < img_h)
                            && (x + px < img_w)
                       )
                    {
                        double v = (double)img.at<uchar>(y + py, x + py);
                        if (v > vmax)
                            vmax = v;
                        if (v < vmin)
                            vmin = v;
                    }
                }
            }
            out.at<uchar>(y, x) = (uchar)(vmax - vmin);
        }
    }
    return out;
}
#endif
