#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

cv::Mat bilinear_interpolation(cv::Mat img, double xScaleFactor=1.0, double yScaleFactor=1.0)
{
    int img_h = img.rows;
    int img_w = img.cols;
    int img_type = img.type();

    int resized_h = img_h * xScaleFactor;
    int resized_w = img_w * yScaleFactor;

    // input image coordinates
    int ix, iy;
    // delta x and delta y
    double dx, dy;
    int val1, val2, val3, val4, sum;

    cv::Mat out = cv::Mat::zeros(resized_h, resized_w, img_type);

    for (int y = 0; y < resized_h; y++){
        for (int x = 0; x < resized_w; x++){

            double rf = y / yScaleFactor;
            double cf = x / xScaleFactor;

            iy = (int)std::floor(rf);
            ix = (int)std::floor(cf);

            dy = rf - iy;
            dx = cf - ix;

            val1 = (1-dx) * (1-dy) * img.at<uchar>(iy, ix);
            val2 = dx * (1-dy) * img.at<uchar>(iy, ix+1);
            val3 = (1-dx) * dy * img.at<uchar>(iy+1, ix);
            val4 = dx * dy * img.at<uchar>(iy+1, ix+1);

            sum = val1 + val2 + val3 + val4;
            out.at<uchar>(y, x) = sum;
        }
    }
    return out;
}

int main()
{
    cv::Mat img = cv::imread("../data/imori.jpg");
    cv::Mat gimg;
    cv::cvtColor(img, gimg, cv::COLOR_BGR2GRAY);

    // Gausian Pyramid
    double scale = 1;
    for (int i = 0; i < 5; i++){
        scale *= 0.5;
        cv::Mat tmp_img = bilinear_interpolation(gimg, scale, scale);
        int timg_h = tmp_img.rows;
        int timg_w = tmp_img.cols;

        std::string name = "Results/out" + std::to_string(timg_h) + "x" + std::to_string(timg_w) + ".png";
        cv::imwrite(name, tmp_img);
    }


    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
