#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

// 大津の二値化
// Binarization of Otsu

using namespace std;

cv::Mat myFunciton(cv::Mat img){
    
    int width  = img.cols;
    int height = img.rows;

    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC1);

    return out;
    }

int main() {

    return 0;
}

