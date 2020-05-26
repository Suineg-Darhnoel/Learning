#include <iostream>
// INCLUDE OPENCV
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp> // blur
int blurAmount = 15;
/* Trackbar callback function */
static void onChange(int pos, void * userInput);
/* Mous callback function */
static void onMouse(int event, int x, int y, int, void * userInput);

int main()
{
    cv::Mat lena = cv::imread("data/lena.jpg");

    // Create windows
    cv::namedWindow("Lena");

    // Create Trackbar
    cv::createTrackbar("Lena", "Lena", &blurAmount, 30, onChange, &lena);
    cv::setMouseCallback("Lena", onMouse, &lena);

    // Call to onChange ot init
    onChange(blurAmount, &lena);
    // wait app for a key to exit
    cv::waitKey(0);
    // Destroy the windows
    cv::destroyWindow("Lena");
    return 0;
}

// Trackbar callback function
static void onChange(int pos, void * userInput)
{
    if (pos <= 0) return;
    cv::Mat imgBlur;
    cv::Mat* img = (cv::Mat*) userInput;
    cv::blur(*img, imgBlur, cv::Size(pos, pos));
    cv::imshow("Lena", imgBlur);
}

/* Mous callback function */
static void onMouse(int event, int x, int y, int, void * userInput)
{
    if (event != cv::EVENT_LBUTTONDOWN)
        return ;
    cv::Mat* img = (cv::Mat*) userInput;
    cv::circle(*img, cv::Point(x, y), 10, cv::Scalar(0,255,0), 3);
    onChange(blurAmount, img);
}
