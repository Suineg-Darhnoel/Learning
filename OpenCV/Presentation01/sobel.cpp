#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

cv::Mat sobel_filter(cv::Mat img, bool sobel_right=true)
{
    int img_h = img.rows;
    int img_w = img.cols;
    cv::Mat out = cv::Mat::zeros(img_h, img_w, CV_8UC1);

    if (sobel_right){
        for (int y = 0; y < img_h; y++){
            for (int x = 0; x < img_w; x++){
                out.at<uchar>(y, x) = (int)std::fmax(
                        0,
                            - 0.5 * img.at<uchar>(y, (int)fmax(x-1, 0)) 
                            + 0.5 * img.at<uchar>(y, (int)fmin(x, img_w-1))
                        );
            }
        }
    }

    else{
        for (int y = 0; y < img_h; y++){
            for (int x = 0; x < img_w; x++){
                out.at<uchar>(y, x) = (int)std::fmax(
                        0,
                            + 0.5 * img.at<uchar>(y, (int)fmax(x-1, 0)) 
                            - 0.5 * img.at<uchar>(y, (int)fmin(x, img_w-1))
                        );
            }
        }
    }

    return out;
}

cv::Mat corner(cv::Mat img)
{
    int img_h = img.rows;
    int img_w = img.cols;

    cv::Mat out = cv::Mat::zeros(img_h, img_w, CV_8UC1);
    for (int y = 0; y < img_h; y++){
        for (int x = 0; x < img_w; x++){
            int val = (int)std::abs(
                        0.5 * img.at<uchar>(y, (int)fmax(x-1, 0))
                        - img.at<uchar>(y, x)
                        + 0.5 * img.at<uchar>(y, (int)fmin(x, img_w-1))
                    );
            out.at<uchar>(y, x) = val;
        }
    }
    
    return out;
}

int main()
{
    cv::Mat img = cv::imread("../data/imori.jpg");
    cv::Mat imgGray;

    cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);
    cv::Mat out1 = sobel_filter(imgGray);
    cv::Mat out2 = corner(imgGray);
    cv::Mat sb_left = sobel_filter(imgGray, false);

    cv::imshow("imgGray", imgGray);
    cv::imshow("out1", out1);
    cv::imshow("out2", out2);
    cv::imshow("sb_left", sb_left);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
