#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include "../include/utils.h"

// 二値化
// Binarization

cv::Mat binarize(cv::Mat img, int th) {
    cv::Mat gray = grayScale(img);

    int width = gray.cols;
    int height = gray.rows;

    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC1);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // 二値化
            if (gray.at<uchar>(y, x) < th) {
                out.at<uchar>(y, x) = 0;
            } else {
                out.at<uchar>(y, x) = 255;
            }
        }
    }
    return out;
}

int main() {
    cv::Mat img;
    img = cv::imread("/home/ykenk07/C++_project/GS100KNOCK/Q1_10/imori.jpg");

    cv::Mat binary;
    binary = binarize(img, 128);

    cv::imshow("img", img);

    cv::imshow("binary", binary);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

