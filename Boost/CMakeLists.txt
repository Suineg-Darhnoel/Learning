cmake_minimum_required(VERSION 3.10)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set project name
set(PROJECT_NAME learnBoost)
project(${PROJECT_NAME})

# find package
find_package(Boost
    COMPONENTS
    # listing necessary libraries
    thread
    system
    filesystem
    # condition
    REQUIRED)

# use multisources
file(GLOB SRCS RELATIVE ${CMAKE_BINARY_DIR} *.cpp)

# get original filenames
set(FILE_LIST "")
foreach(filename ${SRCS})
    string(REGEX REPLACE "../" "" fn ${filename})
    string(REGEX REPLACE ".cpp" "" fn ${fn})
    list(APPEND FILE_LIST ${fn})
endforeach()

# add the executable files and link library
foreach(fn ${FILE_LIST})
    add_executable(${fn} "${fn}.cpp")
    target_link_libraries(${fn} ${Boost_LIBRARIES})
endforeach()
