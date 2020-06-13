#include <iostream>
#include <cmath>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <queue>

cv::Mat getGaborKernel(
            int K=11, 
            double A=0, 
            double g=1.2, 
            double s=1.5,
            int l=3,
            int p=0
        )
{
    /* Formula for Gabor Kernel */
    // x' = cosA * x + sinA * y
    // y' = -sinA * x + cosA * y
    // G(y, x) = exp(-(x'^2 + g^2 y'^2) / 2 s^2) * cos(2 pi x' / l + p)

    /* Kernel's size has to be odd */
    assert (K % 2 != 0);

    double gabor;
    // distance from center
    int d = K/2;
    float sum = 0;
    cv::Mat out = cv::Mat::zeros(K, K, CV_32F);

    for (int y = 0; y < K; y++){
        for (int x = 0; x < K; x++){
            double theta = A / 180. * M_PI;
            int cx = x - d;
            int cy = y - d;
            // kernel x and kernel y
            int kx = (int)(std::cos(theta) * cx + std::sin(theta) * cy);
            int ky = (int)(-std::sin(theta) * cx + std::cos(theta) * cy);

            // compute for each pixel
            gabor = std::exp(-(kx*kx + g*g * ky*ky)/(2 * s*s)) 
                * std::cos(2 * M_PI * kx/l + p); 
            out.at<float>(y, x) = gabor;
            sum += gabor;
        }
    }

    // normalize gabor filter
    out /= sum;
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
            float val = kernel.at<float>(y, x);
            out.at<uchar>(y, x) = (uchar)std::round((val - minVal)/unit);
        }
    }
    return out;
}

cv::Mat conv2DKernel(cv::Mat img, cv::Mat kernel)
{
    int k_size = kernel.rows;
    int img_h = img.rows;
    int img_w = img.cols;

    // distance from center to its frame of the kernel
    int pad = k_size / 2;
    float val;

    cv::Mat result = cv::Mat::zeros(img_h, img_w, CV_32F);
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
                        float imgPixel = (float)img.at<uchar>(y+py, x+px);
                        val += kernel.at<float>(py+pad, px+pad) * imgPixel;
                    }
                }
            }
            /* std::cout << val << '\n'; */
            result.at<float>(y, x) = val;
        }
    }

    // Normalize [0, 255]
    cv::Mat out2 = cv::Mat::zeros(img_h, img_w, CV_8UC1);

    double minVal, maxVal;
    cv::minMaxLoc(result, &minVal, &maxVal);

    double range = maxVal - minVal;
    double unit = range / 255;

    for (int y = 0; y < img_h; y++){
        for (int x = 0; x < img_w; x++){
            // get the computed value
            val = result.at<float>(y, x);
            uchar cvtVal = (uchar)(std::round((val - minVal)/unit));
            out2.at<uchar>(y, x) = cvtVal; 
            /* std::cout << (int)cvtVal << '\n'; */
        }
    }

    return out2;
}


int main()
{
    /* cv::imshow("gaborKernel", gaborKernel); */

    cv::Mat img = cv::imread("../data/imori.jpg", cv::IMREAD_GRAYSCALE);
    /* std::cout << img.size << '\n'; */

    for (int angle = 0; angle <= 3*45; angle +=45){
        cv::Mat gaborKernel = getGaborKernel(13, angle);
        cv::Mat out = conv2DKernel(img, gaborKernel);
        /* out = getMinMaxFilter(out); */

        std::string name = std::to_string(angle) + "_output.png";
        std::string dir = "Results/";
        cv::imshow(name, out);

        // prepare for output
        /* cv::imwrite(dir+name, out); */
    }

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}

