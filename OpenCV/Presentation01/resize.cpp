#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

cv::Mat bilinear_interpolation(cv::Mat img, double xCoeff=1.0, double yCoeff=1.0)
{
    int img_h = img.rows;
    int img_w = img.cols;
    int img_type = img.type();

    int resized_h = img_h * yCoeff;
    int resized_w = img_w * xCoeff;

    cv::Mat out = cv::Mat::zeros(resized_h, resized_w, img_type);

    for (int y = 0; y < resized_h; y++){
        for (int x = 0; x < resized_w; x++){
            /* out = (1-dx) * (1-dy) * img[iy, ix]
            + dx * (1-dy) * img[iy, ix+1]
            + (1-dx) * dy * img[iy+1, ix]
            + dx * dy + img[iy+1, ix+1]
            */
        }
    }
    return out;
}

int main()
{
    cv::Mat img = cv::imread("../data/imori.jpg");
    cv::Mat gimg;
    cv::cvtColor(img, gimg, cv::COLOR_BGR2GRAY);

    bilinear_interpolation(gimg);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
