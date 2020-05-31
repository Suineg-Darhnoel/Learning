#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <complex>
#include <cmath>

const int height = 128, width = 128;

struct fourier_str{
    std::complex<double> coef[height][width];
};

fourier_str dft(cv::Mat img, fourier_str fourier_s)
{
    double I;
    double theta;
    std::complex<double> val;

    for (int l = 0; l < height; l++){
        for (int k = 0; k < width; k++){
            val.real(0);
            val.imag(0);

            for (int y = 0; y < height; y++){
                for (int x = 0; x < width; x++){
                    I = (double)img.at<uchar>(y, x);
                    theta = -2 * M_PI * ((double)k * (double)x / width + (double)l * (double)y/ height);
                    val += std::complex<double>(cos(theta), sin(theta)) * I;
                }
            }

            val /= sqrt(height * width);
            std::cout << "dft: "<< val << '\n';
            fourier_s.coef[l][k] = val;
        }
    }
    return fourier_s;
}

cv::Mat idft(cv::Mat out, fourier_str fourier_s)
{
    double theta;
    double g;
    std::complex<double> G;
    std::complex<double> val;

    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            val.real(0);
            val.imag(0);

            for (int l = 0; l < height; l++){
                for (int k = 0; k < width; k++){
                    G = fourier_s.coef[l][k];
                    theta = 2 * M_PI * (((double)k*x / width) + ((double)l*y) / height);
                    val +=  std::complex<double>(cos(theta), sin(theta)) * G;
                }
            }

            g = std::abs(val) / sqrt(height * width);
            out.at<uchar>(y, x) = (uchar)g;
            std::cout << "(" << y << ", " << x << ") : " << g << '\n';
        }
    }

    return out;
}

int main()
{
    cv::Mat img = cv::imread("data/imori.jpg", cv::IMREAD_COLOR);
    fourier_str fourier_s;

    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC1);

    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    fourier_s = dft(gray, fourier_s);

    out = idft(out, fourier_s);

    // spectral density
    cv::Mat spect_img = cv::Mat::zeros(height, width, CV_8UC1);
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            int magnitute = std::abs(fourier_s.coef[y][x]);
            spect_img.at<uchar>(y, x) = magnitute;
            std::cout << "spect_img : " << magnitute << '\n';
        }
    }

    cv::imshow("answer", out);
    cv::imshow("spect_img", spect_img);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
