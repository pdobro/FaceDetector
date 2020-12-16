
#include "FaceDetector.h"
int main () {
    //get image
    cv::Mat img;


    FaceDetector face_detector;
    face_detector.detected_face(img);

    return 0;
}