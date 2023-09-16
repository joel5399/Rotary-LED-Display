#ifndef RPI_DOTSTAR_HPP
#define RPI_DOTSTAR_HPP

#include <vector>
#include "hardware_controller.hpp"
#include "pixel.hpp"
#include <vector>

const char initialBrightness = 20;

class RpiDotStar {
public:
    RpiDotStar(const unsigned& numPixels, HardwareController* SpiController);
    ~RpiDotStar();
    void setPixelColor(Pixel& pixel, const char& red, const char& green, const char& blue);
    void setBrightness(const char& Brightness);
    void updatePixelPositionsCartesian(const double& currentAngle);
    void setStripColor(const std::vector<std::vector<std::vector<char> > >& image);
    void show() const;
    void clear() const;

    std::vector<Pixel> pixels;
private:
    bool imageIs3Dimensional(const int& thirdDimension);

    float wingspan;
    HardwareController* spiController;
    float brightness = initialBrightness;
};

#endif // RPI_DOTSTAR_HPP
