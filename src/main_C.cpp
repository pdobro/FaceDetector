#include <BlurDrawer.h>
#include "FaceDetector.h"

int main() {

    cv::Mat img;

    //
    boost::interprocess::managed_shared_memory segment(boost::interprocess::open_only, "face_list");
    std::pair<std::vector<cv::Rect> *, boost::interprocess::managed_shared_memory::size_type> res;
    res = segment.find<std::vector<cv::Rect>> ("list");
    std::vector<cv::Rect> list = *res.first;


    BlurDrawer drawer(img, list, 0);
    drawer.draw();

    return 0;
}
