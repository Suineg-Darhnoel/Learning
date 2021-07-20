cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE RELEASE)
project(BASLER_TEST)

# find OPENCV
include_directories([BEFORE]
        /usr/local/opencv4.5/include/opencv4
    )

find_package(OpenCV REQUIRED)
message("OpenCV version: " ${OPENCV_VERSION})

include_directories(/opt/pylon5/include)
link_directories(/opt/pylon5/lib64)
set(Pylon_LIBS
        pylonbase
        pylonutility
        GCBase_gcc_v3_1_Basler_pylon
        GenApi_gcc_v3_1_Basler_pylon # Params
    )

add_executable(pl_test test.cpp)
target_link_libraries(pl_test ${Pylon_LIBS} ${OpenCV_LIBS})
