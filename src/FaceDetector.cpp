//
// Created by patryk on 04.12.2020.
//

#include "FaceDetector.h"

FaceDetector::FaceDetector() :
        confidence_threshold(0.5),
        image_width(300),
        image_height(300),
        image_scale(1.0),
        mean_val({104., 177.0, 123.0}) {
    detection_network = cv::dnn::readNetFromCaffe(FACE_DETECTION_CONFIGURATION, FACE_DETECTION_WEIGHTS);
    if (detection_network.empty()) {
        std::cout<<"err reading network";
    }


}

void FaceDetector::detected_face(const cv::Mat &frame) {
    cv::Mat input_blob = cv::dnn::blobFromImage(frame, image_scale, cv::Size(image_width, image_height), mean_val, false, false);

    detection_network.setInput(input_blob, "data");
    cv::Mat detection = detection_network.forward("detection_out");
    cv::Mat detection_matrix(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());

    std::vector<cv::Rect> faces;

    for (int i = 0; i < detection_matrix.rows; i++) {
        float confidence = detection_matrix.at<float>(i, 2);

        if (confidence > confidence_threshold) {
            //left bottom pixel
            int x1 = static_cast<int>(detection_matrix.at<float>(i, 3) * frame.cols);
            int y1 = static_cast<int>(detection_matrix.at<float>(i, 4) * frame.rows);

            //right top pixel
            int x2 = static_cast<int>(detection_matrix.at<float>(i, 5) * frame.cols);
            int y2 = static_cast<int>(detection_matrix.at<float>(i, 6) * frame.rows);

            faces.emplace_back(x1, y1, x2 - x1, y2 - y1);
        }

    }

    boost::interprocess::shared_memory_object::remove("face_list");

    boost::interprocess::managed_shared_memory sch(boost::interprocess::open_or_create, "face_list", 1024);
    std::vector<cv::Rect> *instance = sch.construct<std::vector<cv::Rect>> ("list") (faces);



}
