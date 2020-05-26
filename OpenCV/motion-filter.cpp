/* Motion Filter */
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

/* Motion Filter */
cv::Mat motion_filter(cv::Mat img, int kernel_size)
{
    int height = img.rows;
    int width = img.cols;
    int channel = img.channels();

    // Prepare output
    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC3);

    int pad = std::floor(kernel_size / 2);
    double kernel[kernel_size][kernel_size];

    for (int y = 0; y < kernel_size; y++){
        for (int x = 0; x < kernel_size; x++){
            if (y == x){
                kernel[y][x] = 1. / kernel_size;
            }else{
                kernel[y][x] = 0;
            }
        }
    }

    // Filtering
    double v = 0;

    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            for (int c = 0; c < channel; c++){
                v = 0;

                for (int dy =-pad; dy < pad + 1; dy++){
                    for (int dx = -pad; dx < pad + 1; dx++){
                        if (
                                ((y+dy)>=0) 
                                && 
                                ((x+dx)>=0) 
                                    && ((y+dy) < height) 
                                    && ((x+dx) < width)
                                ){
                            v += (double)img.at<cv::Vec3b>(y+dy, x+dx)[c] * kernel[dy+pad][dx+pad];
                        }
                    }
                }

                out.at<cv::Vec3b>(y, x)[c] = (uchar)v;
                std::cout << v << '\n';
            }
        }
    }
    return out;
}

int main()
{
    cv::Mat img = cv::imread("data/imori.jpg", cv::IMREAD_COLOR);

    // motion filter
    cv::Mat out = motion_filter(img, 3);

    // cv::imwrite("out.jpg", out);
    cv::imshow("answer", out);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
