#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <algorithm>

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

void genGaussianPyramid(cv::Mat img, std::vector<cv::Mat>& imgVect, bool equalSize=false)
{
    // clean up the space for new images
    if (!imgVect.empty())
        imgVect.clear();

    cv::Mat tmp_img;
    // include the original image in the list
    tmp_img.push_back(img);
    // Start processing
    double scale = 1;
    for (int i = 0; i < 5; i++){
        scale *= 0.5;
        tmp_img = bilinear_interpolation(img, scale, scale);
        imgVect.push_back(tmp_img);
    }

    std::vector<cv::Mat> newImgVect;
    newImgVect.push_back(img);

    if (equalSize == true){
        for ( auto iv : imgVect ){
            scale = img.rows / iv.rows;
            tmp_img = bilinear_interpolation(iv, scale, scale);
            newImgVect.push_back(tmp_img);
        }
    }

    imgVect = newImgVect;
}

cv::Mat imgDiff(cv::Mat img1, cv::Mat img2)
{
    assert(img1.size() == img2.size());
    int img_h = img1.rows;
    int img_w = img1.cols;

    // use float type for output
    // since we will apply the summation later for saliencyMap
    cv::Mat out = cv::Mat::zeros(img_h, img_w, CV_32F);
    for (int y = 0; y < img_h; y++){
        for (int x = 0; x < img_w; x++){
            out.at<float>(y, x) = std::fabs(img1.at<uchar>(y, x) 
                                - img2.at<uchar>(y, x));
        }
    }

    // Normalize the output
    // such that their values
    // lie between 0 and 1
    // for future summation
    double _, maxVal;
    cv::minMaxLoc(out, &_, &maxVal);

    // Normalization
    out /= maxVal;
    return out;
}

cv::Mat saliencyMap(cv::Mat img)
{   
    int img_h = img.rows;
    int img_w = img.cols;
    std::vector<cv::Mat> imgVect;
    genGaussianPyramid(img, imgVect, true);

    // Compute the differences of chosen images
    // use type float since the returned types of
    // imgDiff is float
    cv::Mat tmp_img = cv::Mat::zeros(img_h, img_w, CV_32F);
    tmp_img += imgDiff(imgVect.at(0), imgVect.at(1));
    tmp_img += imgDiff(imgVect.at(0), imgVect.at(3));
    tmp_img += imgDiff(imgVect.at(0), imgVect.at(5));
    tmp_img += imgDiff(imgVect.at(1), imgVect.at(4));
    tmp_img += imgDiff(imgVect.at(2), imgVect.at(3));
    tmp_img += imgDiff(imgVect.at(3), imgVect.at(5));

    // Prepare for output
    cv::Mat out = img.clone();
    // since minVal has to be zero, we can ignore
    double _, maxVal;
    cv::minMaxLoc(tmp_img, &_, &maxVal);

    // Normalize the output image
    // such that the pixel values
    // lie between 0 and 255
    for (int y = 0; y < img_h; y++){
        for (int x = 0; x < img_w; x++){
            out.at<uchar>(y, x) = (int)(255 * tmp_img.at<float>(y, x)/maxVal);
        }
    }

    return out;
}

int main()
{
    cv::Mat img = cv::imread("../data/imori.jpg");
    cv::Mat gimg;
    cv::cvtColor(img, gimg, cv::COLOR_BGR2GRAY);

    cv::Mat out = saliencyMap(gimg);
    cv::imshow("out", out);
    /* cv::imwrite("out.jpg", out); */

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
