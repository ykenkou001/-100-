#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

// Q.1 チャネル入れ替え, RGB -> BGR

using namespace std;

cv::Mat channel_swap(cv::Mat img) {
    // 幅、高さの取得
    int width = img.cols;
    int height = img.rows;

    // 画像の初期化
    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC3);

    // OpenCVはBGR
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // R -> B
            out.at<cv::Vec3b>(y, x)[0] = img.at<cv::Vec3b>(y, x)[2];
            // G -> G
            out.at<cv::Vec3b>(y, x)[1] = img.at<cv::Vec3b>(y, x)[1];
            // B -> R
            out.at<cv::Vec3b>(y, x)[2] = img.at<cv::Vec3b>(y, x)[0];
        }
    }

    return out;
}

int main() {

    cv::Mat img;
    img = cv::imread(
        "/home/ykenkou07/projects/画像処理100本ノック/Q1_10/imori.jpg");

    cv::Mat change_channel;
    change_channel = channel_swap(img);

    cv::Mat disp;
    cv::Mat tmp[2];
    tmp[0] = img;
    tmp[1] = change_channel;
    cv::hconcat(tmp, 2, disp);

    cv::imshow("Result", disp);
    cv::waitKey(0);

    return 0;
}
