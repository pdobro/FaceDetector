//
// Created by patryk on 04.12.2020.
//

#include "BlurDrawer.h"

BlurDrawer::BlurDrawer(cv::Mat input_image, std::vector<cv::Rect> list, int x) {
image = std::move(input_image);
face_list = std::move(list);
mode = x;
}

void BlurDrawer::draw() {
    //fill face rect
     if( mode == 0) {
         cv::Scalar color(0, 0, 200);//red
         int frame_thickness = -1;//fill
         for (const auto &r : face_list) {
             cv::rectangle(image, r, color, frame_thickness);
         }
         //add gaussian blur on face rect
     } else if (mode == 1) {
         for (const auto &r : face_list) {
             cv::GaussianBlur(image(r), image(r), cv::Size(0,0), 4);
         }
     }

    cv::imshow("wideło", image);

    int k = cv::waitKey(0);
    if(k == 's')
    {
        cv::imwrite("result.jpg", image);
    }
}


