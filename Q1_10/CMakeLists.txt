cmake_minimum_required(VERSION 3.10)

project(Q1_10)

add_executable(GS100_001 /home/ykenkou07/projects/画像処理100本ノック/Q1_10/GS100_001.cpp)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-std=c++17")

# ターゲットに対してC++のバージョンを設定する
# target_compile_features(GS100_001 PRIVATE cxx_std_17)

# Includeディレクトリの設定
set(OPENCV_INCLUDE_DIR /usr/include/opencv4)
target_include_directories(GS100_001 PUBLIC "${OPENCV_INCLUDE_DIR}")

# ライブラリディレクトリの設定
set(OPENCV_LIB_DIR /usr/lib)
target_link_directories(GS100_001 PUBLIC "${OPENCV_LIB_DIR}")

# 必要なライブラリのリンク
target_link_libraries(GS100_001 opencv_imgcodecs opencv_core opencv_imgproc opencv_highgui opencv_videoio)

