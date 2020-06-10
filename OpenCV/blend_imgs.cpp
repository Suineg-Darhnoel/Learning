#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>

cv::Mat alpha_blend(cv::Mat& img1, cv::Mat& img2, double alpha=255)
{
    cv::Mat output = img1 * alpha + img2 * alpha;
    return output;
}

int main()
{
    cv::Mat img1 = cv::imread("data/imori.jpg");
    cv::Mat img2 = cv::imread("data/thorino.jpg");

    cv::Mat out {alpha_blend(img1, img2, 0.6)};
    cv::imshow("img1", img1);
    cv::imshow("img2", img2);
    cv::imshow("output", out);

    cv::imwrite("imori_thorino_06_blended.jpg", out);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
