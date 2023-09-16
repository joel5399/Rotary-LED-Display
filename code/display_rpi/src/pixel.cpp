#include "pixel.hpp"
#include <iostream>

Pixel::Pixel(const double& Distance) : red(0x00), green(0x00), blue(0x00), xPos(0), yPos(0) {
    distance = Distance;
}


void Pixel::setDistance(const double& Distance) {
    distance = Distance;
}

void Pixel::setRed(const char& Red) {
    red = Red;
}

void Pixel::setGreen(const char& Green) {
    green = Green;
}

void Pixel::setBlue(const char& Blue) {
    blue = Blue;
}

void Pixel::setXYCartesianFromAngle(const double& angle, const float& wingSpan) {
    const double radius = (wingSpan / 2) - distance;
    const double midPoint = (wingSpan / 2);
    this->xPos = radius * sin(angle) + midPoint;
    this->yPos = (-1.0) * radius * cos(angle) + midPoint;
}

double Pixel::getDistance() {
    return distance;
}

char Pixel::getRed() {
    return red;
}

char Pixel::getGreen() {
    return green;
}

char Pixel::getBlue() {
    return blue;
}

float Pixel::getXPos() {
    return xPos;
}

float Pixel::getYPos() {
    return yPos;
}
