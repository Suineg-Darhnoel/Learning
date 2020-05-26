#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

void debug_info(std::string info, int debug_code)
{
    std::cout << "Error: " << debug_code << " " << info << '\n';
}

int main(int argc, char** argv)
{
    if (argc < 1)
    {
        debug_info("Lack of arguments", 0);
        exit(1);
    }

    cv::String imageName = argv[1];
    
    cv::Mat image;
    image = cv::imread(imageName, cv::IMREAD_COLOR); // Read the file

    if (image.empty())
    {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    /* Convert Color to Gray */
    cv::Mat gray, edge, draw;
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    cv::Canny(gray, edge, 50, 150, 3);

    edge.convertTo(draw, 0);

    cv::namedWindow("Display window", cv::WINDOW_KEEPRATIO); // Create a window for display
    cv::imshow("Display window", draw); // Show our image inside it.
    cv::waitKey(0); // Wit for a keystroke in the window

    return 0;
}
