#ifndef IMAGE_PROCESSOR_HPP
#define IMAGE_PROCESSOR_HPP

#include <opencv2/opencv.hpp>


class ImageProcessor {
public:
    ImageProcessor(const std::string& imgPath);

    cv::Mat getImage();
private:
    cv::Mat imageJpg;

};

#endif // IMAGE_PROCESSOR_HPP
