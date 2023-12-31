#include "rpi_dotstar.hpp"
#include <iostream>


const char startFrame = 0x00;           // Start frame for spi-protocol (APA102)
const char endFrame = 0xFF;             // End Frame for spi-protocol
const double pixelDistance = 6.944444;  // Distance between each pixel [mm]

RpiDotStar::RpiDotStar(const unsigned& numPixels, HardwareController* SpiController) {
    spiController = SpiController;
    wingspan = numPixels * pixelDistance;
    for (unsigned i = 0; i < numPixels;i++) {
        pixels.push_back(Pixel(i * pixelDistance));
    }
}

RpiDotStar::~RpiDotStar() {
    this->clear();
    this->show();
}

void RpiDotStar::loadImage(const cv::Mat& Image) {
    image = Image;
}


void RpiDotStar::setBrightness(const char& Brightness) {
    if (Brightness > 100) {
        std::cout << "brightness can't be more than 100%! brightness is set to 100%!\n";
        brightness = 1.0;
    }
    else {
        brightness = static_cast<float>(Brightness) / 100.0;
    }

}

void RpiDotStar::updatePixelPositionsCartesian(const double& currentAngle) {
    for (auto& pixel : pixels) {
        pixel.setXYCartesianFromAngle(currentAngle, this->wingspan);
    }
}

void RpiDotStar::setStripColor() {

    //TODO: the image files will be distorted if they are not square.

    const unsigned widthImage = image.rows;
    const unsigned heightImage = image.cols;

    const double imageScaleX = static_cast<double>(widthImage - 1) / this->wingspan;
    const double imageScaleY = static_cast<double>(heightImage - 1) / this->wingspan;

    for (auto& pixel : pixels) {
        // determinate pixelcoordinates for the current pixel
        unsigned xPosImg = static_cast<unsigned>(pixel.getXPos() * imageScaleX);
        unsigned yPosImg = static_cast<unsigned>(pixel.getYPos() * imageScaleY);

        if (image.channels() == 3) {
            const cv::Vec3b bgrCollors = image.at<cv::Vec3b>(cv::Point(xPosImg, yPosImg));
            this->setPixelColor(pixel, bgrCollors[2], bgrCollors[1], bgrCollors[0]);
        }
        else {
            unsigned char pixelValue = image.at<uchar>(xPosImg, yPosImg);
            this->setPixelColor(pixel, pixelValue, pixelValue, pixelValue);
        }
    }
}

void RpiDotStar::setPixelColor(Pixel& pixel, const char& red, const char& green, const char& blue) {
    pixel.setRed(static_cast<char>((float)red * brightness));
    pixel.setGreen(static_cast<char>((float)green * brightness));
    pixel.setBlue(static_cast<char>((float)blue * brightness));
}

void RpiDotStar::show() const {
    std::vector<char> buffer;

    for (int i = 0; i < 4; i++) {
        buffer.push_back(startFrame);
    }
    for (auto pixel : pixels) {
        buffer.push_back(0xFF); //StartFrame
        buffer.push_back(pixel.getBlue());
        buffer.push_back(pixel.getGreen());
        buffer.push_back(pixel.getRed());
    }
    buffer.push_back(endFrame);
    if (spiController->updateSpi(buffer.data(), buffer.size())) {
        std::cout << "error while sending data\n";
    }
}

void RpiDotStar::clear() const {
    for (auto pixel : pixels) {
        pixel.setRed(0x00);
        pixel.setGreen(0x00);
        pixel.setBlue(0x00);
    }
}

bool RpiDotStar::imageIs3Dimensional(const int& thirdDimension) {
    return thirdDimension > 1;
}
