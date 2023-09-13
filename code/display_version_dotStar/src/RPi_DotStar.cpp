#include "RPi_DotStar.h"

RPi_DotStar::RPi_DotStar(const int numLeds, const int &spiChannel = 0, const int &spiSpeed = 1000000) {
    
}

int RPi_DotStar::clear(void) {
    uint8_t color[numLeds * 4] = {0};  // Initialize with zeros
}
