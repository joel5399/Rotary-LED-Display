#include "image_processor.hpp"

ImageProcessor::ImageProcessor(const std::string& imgPath) {
    imageJpg = cv::imread(imgPath);
    if (imageJpg.empty()) {
        std::cerr << "something went wrong while reading picture!" << std::endl;
        return;
    }
}

cv::Mat ImageProcessor::getImage() {
    return imageJpg;
}


