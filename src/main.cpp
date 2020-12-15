#include <opencv4/opencv2/opencv.hpp>
#include <chrono>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>

#include "FaceDetector.h"
#include "BlurDrawer.h"

int main(int argc, char **argv) {

    auto start = std::chrono::high_resolution_clock::now();
//get image
    cv::Mat img = imread("/home/patryk/CLionProjects/facedetecion/data/input.jpg", cv::IMREAD_COLOR);
    if (img.empty())
    {
        std::cout << "image not found";
    }
//run detector
    FaceDetector face_detector;
    face_detector.detected_face(img);
//get list
    boost::interprocess::managed_shared_memory segment(boost::interprocess::open_only, "face_list");
    std::pair<std::vector<cv::Rect> *, boost::interprocess::managed_shared_memory::size_type> res;
    res = segment.find<std::vector<cv::Rect>> ("list");
    std::vector<cv::Rect> list = *res.first;
//draw rectangles
    BlurDrawer drawer(img, list, 1);
    drawer.draw();

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    //std::cout << "Elapsed time: " << elapsed.count() << " s\n";

    return 0;
}