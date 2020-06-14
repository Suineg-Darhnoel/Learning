#include <iostream>
#include <cmath>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "gaborLib.hpp"


int main()
{
    std::vector<cv::Mat> kernels;

    // generate GaborKernel with different angles
    for (int angle = 0; angle <= 45*3; angle +=45)
    {
        cv::Mat gbk = getGaborKernel(111, 10, angle, 10, 1.2, 0);
        kernels.push_back(getNormalizedKernel(gbk));
    }

    for (int i = 0; i < (int)kernels.size(); i++){
        cv::imshow("gabor_"+std::to_string(i), kernels.at(i));
    }

    // write outputs to disk
    for (int i = 0; i < (int)kernels.size(); i++){
        std::string name = "Results/gabor_" + std::to_string(i) + ".png";
        /* cv::imwrite(name, kernels.at(i)); */
    }

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
