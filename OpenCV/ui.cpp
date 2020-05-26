#include <iostream>

// OPENCV
#include <opencv2/core/utility.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
cv::Mat img;

const char* keys{
    "{help h usage ? | | print this message}"
    "{@image | | Image to process}"
};

void showHistoCallback(int state, void *userData)
{
    /* Separate image in BRG */
    std::vector<cv::Mat> bgr;
    cv::split(img, bgr);

    int numbins = 256;
    float range[] = {0, 256 } ;
    const float* histRange = { range };
    cv::Mat b_hist, g_hist, r_hist;
    cv::calcHist(&bgr[0], 1, 0, cv::Mat(), b_hist, 1, &numbins, &histRange);
    cv::calcHist(&bgr[1], 1, 0, cv::Mat(), g_hist, 1, &numbins, &histRange);
    cv::calcHist(&bgr[2], 1, 0, cv::Mat(), r_hist, 1, &numbins, &histRange);

    int width = 512;
    int height = 300;
    cv::Mat histImage(height, width, CV_8UC3, cv::Scalar(20, 20, 20));
    cv::normalize(b_hist, b_hist, 0, height, cv::NORM_MINMAX);
    cv::normalize(g_hist, g_hist, 0, height, cv::NORM_MINMAX);
    cv::normalize(r_hist, r_hist, 0, height, cv::NORM_MINMAX);

    int binStep = cvRound((float)width/(float)numbins);
    for (int i = 1; i < numbins; i++){
        cv::line(histImage, 
                cv::Point(binStep*(i-1), height-cvRound(b_hist.at<float>(i-1))),
                cv::Point(binStep*(i), height-cvRound(b_hist.at<float>(i))),
                cv::Scalar(255, 0, 0)
            );

        cv::line(histImage, 
                cv::Point(binStep*(i-1), height-cvRound(g_hist.at<float>(i-1))),
                cv::Point(binStep*(i), height-cvRound(g_hist.at<float>(i))),
                cv::Scalar(0, 255, 0)
            );
        cv::line(histImage, 
                cv::Point(binStep*(i-1), height-cvRound(r_hist.at<float>(i-1))),
                cv::Point(binStep*(i), height-cvRound(r_hist.at<float>(i))),
                cv::Scalar(0, 0, 255)
            );
    }
    cv::imshow("Histogram", histImage);
}

int main(int argc, char *argv[])
{
    cv::CommandLineParser parser(argc, argv, keys);
    parser.about("Chapter 4. PhotoTool v1.0.0");
    if (parser.has("help")){
        parser.printMessage();
        return 0;
    }
    
    cv::String imgFile = parser.get<cv::String>(0);
    // Check if params are correctly parsed in variables
    if (!parser.check()){
        parser.printErrors();
        return 0;
    }
    /* Load image to process */
    cv::Mat img = cv::imread(imgFile);
    cv::namedWindow("Input");

    /* Create UI button */
    cv::createButton("Show histogram", showHistoCallback, NULL, cv::QT_PUSH_BUTTON, 0);
    /* cv::createButton("Equalize histogram", equalizeCallback, NULL, cv::QT_PUSH_BUTTON, 0); */
    /* cv::createButton("Lomography effect", lomoCallback, NULL, cv::QT_PUSH_BUTTON, 0); */
    /* cv::createButton("Cartoonize effect", cartoonCallback, NULL, cv::QT_PUSH_BUTTON, 0); */
    return 0;
}
