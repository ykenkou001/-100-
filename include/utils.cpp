#include "utils.h"

#include <iostream>

cv::Mat grayScale(cv::Mat img) {
    // imgの幅、高さの定義
    int width = img.cols;
    int height = img.rows;

    // 出力用のMatの定義
    cv::Mat out = cv::Mat::zeros(width, height, CV_8UC1);

    // grayScale化
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            out.at<uchar>(y, x) = img.at<cv::Vec3b>(y, x)[2] * 0.2126 +
                                  img.at<cv::Vec3b>(y, x)[1] * 0.7152 +
                                  img.at<cv::Vec3b>(y, x)[0] * 0.0722;
        }
    }

    return out;
}
