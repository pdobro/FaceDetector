//
// Created by patryk on 04.12.2020.
//

#ifndef FACEDETECTOR
#define FACEDETECTOR

#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/dnn.hpp>
#include <sstream>
#include <vector>
#include <string>
#include <boost/interprocess/managed_shared_memory.hpp>


class FaceDetector {

private:
    //requires prototxt file and pretrained Caffe model(with weights)
    cv::dnn::Net detection_network;

    int image_width;
    int image_height;
    int image_scale;
    //mean values network was trained with
    cv::Scalar mean_val;
    //confidence (default 0.5)
    float confidence_threshold;


public:
    //detect faces in image
    explicit FaceDetector();

    //return list of detected faces
    void detected_face(const cv::Mat &frame);
};


#endif //FACEDETECTOR