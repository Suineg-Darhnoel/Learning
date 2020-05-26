#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

int main()
{
    std::string fileName = "filename.mp4";
    cv::VideoCapture capture(fileName);
    cv::Mat frame;
    cv::Mat grayFrame;

    if (!capture.isOpened())
        throw "Error";

    cv::namedWindow("window", 1);
    for(;;){
        capture >> frame;
        if(frame.empty())
            break;
        cv::cvtColor(frame, grayFrame, cv::COLOR_BGR2GRAY);
        cv::imshow("window", grayFrame);
        cv::waitKey(20);
    }
    cv::waitKey(0);
    return 0;
}
