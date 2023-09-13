#include "RPi_DotStar.hpp"
#include "hardware_controller.hpp"


RPi_DotStar::RPi_DotStar(const unsigned& numPixels, HardwareController SpiController) {
    spiController = SpiController;
    pixels.resize(numPixels);
}

void RPi_DotStar::setBrightness(const char& Brightness) {
}

void RPi_DotStar::setPixelColor(const unsigned& index, const char& red, const char& green, const char& blue) {

}

void RPi_DotStar::show() {

}

int RPi_DotStar::clear(void) {
    for (auto pixel : pixels) {
        pixel.red = 0x00;
        pixel.green = 0x00;
        pixel.blue = 0x00;
    }

}
