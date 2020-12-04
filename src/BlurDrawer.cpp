//
// Created by patryk on 04.12.2020.
//

#include "BlurDrawer.h"

BlurDrawer::BlurDrawer(cv::Mat input_image, std::vector<cv::Rect> list) {
image = std::move(input_image);
face_list = std::move(list);
}

void BlurDrawer::draw() {

    cv::Scalar color(0, 0, 200);//red
    int frame_thickness = -1;//fill rectangle

    for(const auto & r : face_list){
        cv::rectangle(image, r, color, frame_thickness);
    }


    cv::imwrite("result.jpg", image);

}


