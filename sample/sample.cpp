#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <string>

using namespace std;

int main(int argc, const char* argv[]) {
    cv::Mat redImag(cv::Size(320, 240), CV_8UC3, cv::Scalar(0, 0, 255));
    /* cv::namedWindow("Red", cv::WINDOW_AUTOSIZE); */

    // 画像を表示するかどうか
    char showImg;

    // y, nが押されたら終了
    cout << "画像を表示するか<y/n>" << endl;
    do {
        cin >> showImg;

        if (showImg == 'y' || showImg == 'n') {
            break;

            cout << "yかnを押してください" << endl;
        }
    } while (true);

    cout << "showImg: " << showImg << endl;

    // showImg = "y" なら表示する
    if (showImg == 'y') {
        cv::imshow("Red", redImag);
        cv::waitKey(0);

        cv::destroyAllWindows();

        // 画像の幅、高さを読み取る
        int width = redImag.cols;
        int height = redImag.rows;

        cout << "redImag width: " << width << endl;
        cout << "redImag height: " << height << endl;
    }

    // 画素をいじる
    cv::Mat img;
    img = cv::imread(
        "/home/ykenkou07/projects/画像処理100本ノック/"
        "sample/imori.jpg",
        cv::IMREAD_COLOR);

    if (img.empty()){
        cout << "Can`t Load Image" << endl;
        return 0;
    }

    int width  = img.cols;
    int height = img.rows;

    string dashes(30, '*');

    cout << dashes << endl;
    cout << "img width:  " << width << endl;
    cout << "img height: " << height << endl;
    cout << "img channels: " << img.channels() << endl;

    cv::imshow("Original: akahara", img);
    cv::waitKey(0);
    cv::destroyAllWindows();

    // 画素のx=30, y=20にアクセス
    cout << img.at<cv::Vec3b>(30, 20) << endl;

    /* 画像の左上半分を赤に */
    int i = 0, j = 0;
    for (i = 0; i < width / 2; i++){
        for (j = 0; j < height / 2; j++){
            img.at<cv::Vec3b>(j,i)[0] =   0;
            img.at<cv::Vec3b>(j,i)[1] =   0;
            img.at<cv::Vec3b>(j,i)[2] = 255;
        }
    }

    cout << img.at<cv::Vec3b>(height/2 - 1, width/2 - 1) << endl;

    /* for (int i = 0; i < 10; i++){ */
    /*     for (int j = 0; j < 10; j++){ */
    /*         cout << img.at<cv::Vec3b>(j, i) << endl; */
    /*     } */
    /* } */

    cv::imshow("Img", img);
    cv::waitKey(0);
    cv::destroyAllWindows();

    /* cv::Vec3b tmp =  img.at<cv::Vec3b>(29,10); */

    /* cout << "tmp: " << tmp << endl; */

    cv::Mat img2 = img.clone();

    /* 複数画像の表示 */
    cv::Mat disp;
    cv::Mat tmp[3];
    tmp[0] = img;
    tmp[1] = cv::Mat (cv::Size(10, height), CV_8UC3, cv::Scalar(0, 0, 0));
    tmp[2] = img2;

    // tmpを水平方向で連結
    cv::hconcat(tmp, 3, disp);

    cv::imshow("Sample", disp);
    cv::waitKey(0);
    cv::destroyAllWindows();

    /* 画像を保存 */
    cv::imwrite("out.jpg", disp);

    cv::Mat outjpg;
    outjpg = cv::imread("/home/ykenkou07/projects/画像処理100本ノック/sample/out.jpg");

    cv::imshow("outjpg", outjpg);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

