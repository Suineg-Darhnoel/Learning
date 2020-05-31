#include <iostream>
#include <algorithm>
#include <vector>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

void drawingAxis(cv::Mat frame, cv::Point2f center);
bool compareContourAreas(std::vector<cv::Point> contour1, std::vector<cv::Point> contour2){
    double i = std::fabs(cv::contourArea(cv::Mat(contour1)));
    double j = std::fabs(cv::contourArea(cv::Mat(contour2)));
    return (i < j);
}

int main()
{
    int height, width;
    cv::VideoCapture cap;
    cap.open("data/eye_movement_cut.mkv");

    cv::Mat frame, gray_frame;
    cv::Mat ret;

    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Vec4i> hierarchy;


    double thresh;
    for (;;){
        // Read each frame
        cap.read(frame);
        if (frame.empty()){
            std::cerr << "ERROR! blank frame grabbed\n";
            break;
        }

        height = frame.rows;
        width = frame.cols;

        cv::cvtColor(frame, gray_frame, cv::COLOR_BGR2GRAY);
        cv::GaussianBlur(gray_frame, gray_frame, cv::Size(7, 7), 0, 0);
        thresh = cv::threshold(gray_frame, ret, 3, 255, cv::THRESH_BINARY_INV);

        cv::findContours(
                    gray_frame, 
                    contours, 
                    hierarchy,
                    cv::RETR_TREE,
                    cv::CHAIN_APPROX_SIMPLE
                );

        auto cont_size {contours.size()};
        std::vector<std::vector<cv::Point>> contours_poly (cont_size);
        std::vector<cv::Point2f> centers (cont_size);
        std::vector<float> radius (cont_size);

        // circle around the discovered contours
        for (size_t i = 0; i < contours.size(); i++){
            cv::approxPolyDP(contours[i], contours_poly[i], 3, true);
            cv::minEnclosingCircle(contours_poly[i], centers[i], radius[i]);
        }
        // Start Drawing Contour Over the frame
        for (size_t i = 0; i < contours.size(); i++){
            /* cv::drawContours( */
            /*             frame, */ 
            /*             contours, */ 
            /*             int(i), */ 
            /*             cv::Scalar(0, 255, 0) */
            /*         ); */
            cv::circle(frame, centers[i], (int)radius[i], cv::Scalar(0, 0, 255), 2);
        }

        // sort contours
        std::sort(contours.begin(), contours.end(), compareContourAreas);
        // grab the beggest contour
        int bContourPos = contours.size()-1;
        std::vector<cv::Point> biggestContour = contours[bContourPos];

        auto bCenter = centers[bContourPos];
        int thickness = 2;
        // Vertical line passing through the center of the biggestContour
        cv::Point startP = cv::Point(bCenter.x, 0);
        cv::Point endP = cv::Point(bCenter.x, height);
        cv::line(frame, startP, endP, cv::Scalar(0,255,0), thickness);

        // Vertical line passing through the center of the biggestContour
        startP = cv::Point(0, bCenter.y);
        endP = cv::Point(width, bCenter.y);
        cv::line(frame, startP, endP, cv::Scalar(0,255,0), thickness);

        // Output the frame to the screen
        /* cv::imshow("gray_frame", ret); */
        cv::imshow("Live", frame);
        if (cv::waitKey(5) >= 0)
            break;
    }
    cv::destroyAllWindows();
    return 0;
}
