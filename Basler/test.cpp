#include "pylon/InstantCamera.h"
#include "pylon/TlFactory.h"
#include <pylon/PylonIncludes.h>

#include <pylon/usb/BaslerUsbInstantCamera.h>
#include <pylon/ParameterIncludes.h>

typedef Pylon::CBaslerUsbInstantCamera Camera_t;

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

int main()
{
    int exitCode = 0;
    Pylon::PylonInitialize();

    /* Create the format converter */
    Pylon::CImageFormatConverter fconverter;
    fconverter.OutputPixelFormat = Pylon::PixelType_BGR8packed;

    /* Create a target image for display */
    Pylon::CPylonImage targetImage;

    /* OpenCV Mat image */
    cv::Mat cvBGRImage;
    try{
        Pylon::CDeviceInfo d_info;
        d_info.SetDeviceClass( Pylon::CBaslerUsbInstantCamera::DeviceClass() );


        Camera_t cam( Pylon::CTlFactory::GetInstance().CreateFirstDevice(d_info) );
        std::cout << "Using device: " << cam.GetDeviceInfo().GetModelName() << std::endl;

        cam.Open();

        /* MaxNumBuffer is used to control the count of buffers
         * default: 10
         */
        cam.MaxNumBuffer = 10;

        /* cam.ExposureAuto.SetValue(Basler_UsbCameraParams::ExposureAutoEnums::ExposureAuto_Continuous); */
        cam.StartGrabbing( Pylon::GrabStrategy_LatestImages );

        Pylon::CGrabResultPtr ptrGrabResult;
        while ( cam.IsGrabbing() )
        {
            /* timeout: 5000 */
            cam.RetrieveResult(5000, ptrGrabResult, Pylon::TimeoutHandling_ThrowException);
            if (ptrGrabResult->GrabSucceeded())
            {
                fconverter.Convert(targetImage, ptrGrabResult);
                int w = ptrGrabResult->GetWidth();
                int h = ptrGrabResult->GetHeight();
                cvBGRImage = cv::Mat(w, h, CV_8UC3, targetImage.GetBuffer());
                std::cout << "BImageCenterPixel = " << (int)cvBGRImage.at<uchar>(w/2, h/2, 0) << std::endl;

                cv::imshow("bgrImage", cvBGRImage);
                int key = cv::waitKey(1) & 0xFF;
                if (key == int('q')){
                    break;
                }
            }
        }
        cam.Close();
    }catch (const Pylon::GenericException &e){
        std::cerr << "Could not grab an image: " << "\n"
                  << e.GetDescription() << "\n";
    }

    Pylon::PylonTerminate();
    return exitCode;
}
