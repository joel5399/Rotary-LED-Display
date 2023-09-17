#ifndef RPI_DOTSTAR_HPP
#define RPI_DOTSTAR_HPP

#include <vector>
#include "hardware_controller.hpp"
#include "pixel.hpp"
#include <vector>
#include <opencv2/opencv.hpp>

const char initialBrightness = 20;

class RpiDotStar {
public:
    RpiDotStar(const unsigned& numPixels, HardwareController* SpiController);
    ~RpiDotStar();
    void loadImage(const cv::Mat& Image);
    void setPixelColor(Pixel& pixel, const char& red, const char& green, const char& blue);
    void setBrightness(const char& Brightness);
    void updatePixelPositionsCartesian(const double& currentAngle);
    void setStripColor();
    void show() const;
    void clear() const;

    std::vector<Pixel> pixels;
private:
    bool imageIs3Dimensional(const int& thirdDimension);

    cv::Mat image;
    float wingspan;
    HardwareController* spiController;
    float brightness = initialBrightness;
};

#endif // RPI_DOTSTAR_HPP
