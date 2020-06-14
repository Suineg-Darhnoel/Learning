#ifndef MYFUNC
#define MYFUNC

#include <iostream>
#include <cmath>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

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

cv::Mat getMask(cv::Mat hsv, int hueLow=180, int hueHigh=260)
{
    int height = hsv.rows;
    int width = hsv.cols;
    cv::Mat mask = cv::Mat::zeros(hsv.size(), CV_8UC1);

    hueLow = std::fmax(0, hueLow);
    hueHigh = std::fmin(hueHigh, 260);
    double h;
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            h = (double)hsv.at<cv::Vec3f>(y, x)[0];
            if (h <= hueHigh && h >= hueLow){
                mask.at<uchar>(y, x) = 255;
            }
        }
    }

    return mask;
}

cv::Mat setMask(cv::Mat img, cv::Mat _mask){
    cv::Mat mask = (255 - _mask)/255;
    int height = img.rows;
    int width = img.cols;
    cv::Mat out = img.clone();

    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            // loop through BGR
            for (int i = 0; i < 3; i++)
                out.at<cv::Vec3b>(y, x)[i] = mask.at<uchar>(y, x) * out.at<cv::Vec3b>(y, x)[i];
        }
    }

    return out;
}

cv::Mat OtsuBin(cv::Mat& grayImg)
{
    int img_h = grayImg.rows;
    int img_w = grayImg.cols;

    double w0 = 0, w1 = 0;
    double m0 = 0, m1 = 0;
    double max_sb = 0, sb = 0;
    int thresh = 0;
    int curr_pixel;

    // Compute for threshold
    for (int pixel = 0; pixel < 255; pixel++){
        w0 = 0;
        w1 = 0;
        m0 = 0;
        m1 = 0;
        for (int y = 0; y < img_h; y++){
            for (int x = 0; x < img_w; x++){
                curr_pixel = (int)(grayImg.at<uchar>(y, x));
                if (curr_pixel < pixel){
                    w0++;
                    m0 += curr_pixel;
                }
                else{
                    w1++;
                    m1 += curr_pixel;
                }
            }
        }
        m0 /= w0;
        m1 /= w1;
        w0 /= (img_h * img_w);
        w1 /= (img_h * img_w);
        // true formula sb = 
        // w0 * w1 * std::pow(m0-m1, 2) / std::pow(m1+m2, 2)
        sb = w0 * w1 * std::pow(m0-m1, 2);

        if (sb > max_sb){
            max_sb = sb;
            thresh = pixel;
        }
    }

    cv::Mat binImg = cv::Mat::zeros(img_h, img_w, CV_8UC1);
    for (int y = 0; y < img_h; y++){
        for (int x = 0; x < img_w; x++){
            if (grayImg.at<uchar>(y, x) > thresh){
                binImg.at<uchar>(y, x) = 255;
            }
            else{
                binImg.at<uchar>(y, x) = 0;
            }
        }
    }

    return binImg;
}

// Dilation
cv::Mat dilate(cv::Mat& imgBin, int N)
{
    int img_h = imgBin.rows;
    int img_w = imgBin.cols;

    cv::Mat out = imgBin.clone();

    for (int i = 0; i < N; i++){
        // loop through each pixel
        cv::Mat tmpImg = out.clone();
        for (int y = 0; y < img_h; y++){
            for (int x = 0; x < img_w; x++){
                if ((x > 0) && (tmpImg.at<uchar>(y, x-1) == 0)){
                    out.at<uchar>(y, x) = 0;
                    continue;
                }

                if ((y > 0) && (tmpImg.at<uchar>(y-1, x) == 0)){
                    out.at<uchar>(y, x) = 0;
                    continue;
                }

                if ((x < img_w - 1) && (tmpImg.at<uchar>(y, x+1) == 0)){
                    out.at<uchar>(y, x) = 0;
                    continue;
                }

                if ((y < img_h - 1) && (tmpImg.at<uchar>(y+1, x) == 0)){
                    out.at<uchar>(y, x) = 0;
                    continue;
                }
            }
        }
    }

    return out;
}

// Erosion
cv::Mat erode(cv::Mat& imgBin, int N)
{
    int img_h = imgBin.rows;
    int img_w = imgBin.cols;

    cv::Mat out = imgBin.clone();

    for (int i = 0; i < N; i++){
        // loop through each pixel
        cv::Mat tmpImg = out.clone();
        for (int y = 0; y < img_h; y++){
            for (int x = 0; x < img_w; x++){
                if ((x > 0) && (tmpImg.at<uchar>(y, x-1) == 255)){
                    out.at<uchar>(y, x) = 255;
                    continue;
                }

                if ((y > 0) && (tmpImg.at<uchar>(y-1, x) == 255)){
                    out.at<uchar>(y, x) = 255;
                    continue;
                }

                if ((x < img_w - 1) && (tmpImg.at<uchar>(y, x+1) == 255)){
                    out.at<uchar>(y, x) = 255;
                    continue;
                }

                if ((y < img_h - 1) && (tmpImg.at<uchar>(y+1, x) == 255)){
                    out.at<uchar>(y, x) = 255;
                    continue;
                }
            }
        }
    }

    return out;
}

cv::Mat closing(cv::Mat mask, int N)
{
    cv::Mat out;
    out = dilate(mask, N);
    out = erode(out, N);
    return out;
}

cv::Mat opening(cv::Mat mask, int N)
{
    cv::Mat out;
    out = erode(mask, N);
    out = dilate(out, N);
    return out;
}

#endif
