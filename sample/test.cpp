#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

/* imori.jpgの左上半分のRとBを入れ替える */

using namespace std;

int main() {
    /* imori.jpgの読み込み */
    cv::Mat imori;
    imori = cv::imread(
        "/home/ykenkou07/projects/画像処理100本ノック/sample/imori.jpg");

    /* imoriの幅、高さの取得 */
    int width = imori.cols;
    int height = imori.rows;

    /* cv::imshow("Original", imori); */
    /* cv::waitKey(0); */

    cv::Mat imori2;
    imori2 = imori.clone();

    for (int i = 0; i < width; i++){
        for (int j = 0; j < height / 2; j++){
            unsigned char tmp = imori2.at<cv::Vec3b>(j, i)[0];
            imori2.at<cv::Vec3b>(j, i)[0] = imori2.at<cv::Vec3b>(j, i)[2];
            imori2.at<cv::Vec3b>(j, i)[2] = tmp;
        }
    }

    cv::Mat disp;
    cv::Mat mat[2];

    mat[0] = imori;
    mat[1] = imori2;
    cv::hconcat(mat, 2, disp);

    cv::imshow("Images", disp);
    cv::waitKey(0);

    return 0;
}

