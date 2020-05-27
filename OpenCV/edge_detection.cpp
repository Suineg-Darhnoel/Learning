#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

cv::Mat img, img_gray;
cv::Mat dst, detected_edges;

int lowThreshold = 0;
const int max_lowThreshold = 100;
const int ratio = 3;
const int kernel_size = 3;
const char* window_name = "Edge Map";

static void CannyThreshold(int, void*)
{
    cv::blur(img_gray, detected_edges, cv::Size(3, 3));
    cv::Canny(detected_edges, detected_edges, lowThreshold, lowThreshold * ratio, kernel_size);
    dst = cv::Scalar::all(0);
    img.copyTo(dst, detected_edges);
    cv::imshow(window_name, dst);
}

int main(int argc, char** argv)
{
    cv::CommandLineParser parser(argc, argv, "{@input | data/eye2.jpg | input image}");

    img = cv::imread(cv::samples::findFile(parser.get<cv::String>("@input")), cv::IMREAD_COLOR);

    if (img.empty()){
        std::cout << "Could not open or find the image!\n";
        std::cout << "Usage: " << argv[0] << " <Input image>\n";
        return -1;
    }

    dst.create(img.size(), img.type());
    cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);
    cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);

    cv::createTrackbar("Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThreshold);
    CannyThreshold(0, 0);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
