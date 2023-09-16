#ifndef RPI_DOTSTAR_HPP
#define RPI_DOTSTAR_HPP

#include <iostream>
#include <vector>
#include "hardware_controller.hpp"

const char initialBrightness = 20;

class Pixel {
public:
    Pixel(const char& Red, const char& Green, const char& Blue) {
        red = Red;
        green = Green;
        blue = Blue;
    }

    char red;
    char green;
    char blue;
}

class RPi_DotStar {
public:
    RPi_DotStar(const unsigned& numPixels, HardwareController SpiController);
    void setPixelColor(const unsigned& index, const char& red, const char& green, const char& blue);
    void setBrightness(const char& Brightness);
    void show();
    int clear(void);

private:
    std::vector<Pixel> pixels;
    HardwareController spiController;
    char brightness = initialBrightness;
};

#endif // RPI_DOTSTAR_HPP
