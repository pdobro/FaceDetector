#include <opencv4/opencv2/opencv.hpp>
#include <chrono>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>

#include "FaceDetector.h"
#include "BlurDrawer.h"

int main(int argc, char **argv) {
    //cv::samples::addSamplesDataSearchPath("/home/patryk/CLionProjects/facedetecion/data");
    //std::string image_path = cv::samples::findFile("input.jpg");

    auto start = std::chrono::high_resolution_clock::now();

    cv::Mat img = imread("/home/patryk/CLionProjects/facedetecion/data/input.jpg", cv::IMREAD_COLOR);
    if (img.empty())
    {
        std::cout << "image not found";
    }

    FaceDetector face_detector;
    BlurDrawer drawer(img, face_detector.detected_face(img));
    drawer.draw();

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";

    return 0;
}