#include <iostream>
#include <cmath>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

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

    std::cout << "Threshold value = " << thresh << '\n';

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


int main()
{
    cv::Mat imgGray = cv::imread("../data/imori.jpg", cv::IMREAD_GRAYSCALE);
    cv::Mat binImg;

    binImg = OtsuBin(imgGray);
    cv::imshow("Gray Image", imgGray);
    cv::imshow("Binary Image", binImg);
    
    // output files
    cv::imwrite("Results/otsubin_img.png", binImg);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
