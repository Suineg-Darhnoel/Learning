#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

cv::Mat removeLight(cv::Mat img, cv::Mat pattern, int method)
{
    cv::Mat aux;
    // if method is normalization
    if (method == 1){
        /* Require change our image to 32 float for division */
        cv::Mat img32, pattern32;
        img.convertTo(img32, CV_32F);
        pattern.convertTo(pattern32, CV_32F);
        /* Divide the image by the pattern */
        aux = 1 - (img32 / pattern32);
        /* convert 8 bits format and scale */
        aux.convertTo(aux, CV_8U, 255);
    }else{
        aux = pattern - img;
    }
    return aux;
}

int main()
{
    cv::Mat img = cv::imread("data/screw.jpg", cv::COLOR_BGR2GRAY);
    cv::Mat blurred_img;
    cv::Mat gaussian_img;

    cv::medianBlur(img, blurred_img, 3);
    cv::GaussianBlur(img, gaussian_img, cv::Size(101, 101), 0);

    cv::Mat rm_light_img_diff { removeLight(blurred_img, gaussian_img, 0) };
    cv::Mat rm_light_img_div { removeLight(blurred_img, gaussian_img, 1) };

    cv::imshow("Median", blurred_img);
    cv::imshow("Guassian", gaussian_img);
    cv::imshow("Light Removed : Difference", rm_light_img_diff);
    cv::imshow("Light Removed : Division", rm_light_img_div);

    cv::waitKey(0);
    return 0;
}
