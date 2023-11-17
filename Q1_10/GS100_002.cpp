#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

// グレースケール化
// Y = 0.2126 R + 0.7152 G + 0.0722 B

using namespace std;

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

int main() {
    cv::Mat img = cv::imread(
        "/home/ykenkou07/projects/画像処理100本ノック/"
        "Q1_10/imori.jpg");

    cv::Mat out = grayScale(img);

    cout << "img.size: " << img.size << endl;
    cout << "out.size: " << out.size << endl;

    cv::imshow("img", img);
    /* cv::waitKey(0); */

    cv::imshow("out", out);
    cv::waitKey(0);
    cv::destroyAllWindows();


    return 0;
}

