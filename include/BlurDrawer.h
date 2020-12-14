//
// Created by patryk on 04.12.2020.
//

#ifndef BLURDRAWER
#define BLURDRAWER

#include <opencv4/opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <utility>

class BlurDrawer {
private:
    cv::Mat image;
    std::vector<cv::Rect> face_list;
    int mode;//blur mode

public:
    BlurDrawer(cv::Mat input_image, std::vector<cv::Rect> list, int x);

    void draw();
};

#endif //FACEDETECTOR_BLURDRAWER_H
