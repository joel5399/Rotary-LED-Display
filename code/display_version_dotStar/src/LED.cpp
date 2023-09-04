#include "LED.h"
#include <math.h>


LEDClass::LEDClass(){
    distance = 0;
    red = 0;
    green = 0;
    blue = 0;
    xPos = 0;
    yPos = 0;
}

void LEDClass::setDistance(const double &Distance) {
    distance = Distance;
}

void LEDClass::setRed(const uint8_t &Red){
    red = Red;
}

void LEDClass::setGreen(const uint8_t &Green){
    green = Green;
}

void LEDClass::setBlue(const uint8_t &Blue){
    blue = Blue;
}

void LEDClass::setXYCartesianFromAngle(const double& angle, const int &wingSpan) {
    const double radius = (-1) * ((wingSpan/2) - distance);
    const double midPoint = (wingSpan/2);
    const int xPos = radius * sin(angle) + midPoint;
    const int yPos = (-1) * radius * cos(angle) + midPoint;
    this->setXPos(xPos);
    this->setYPos(yPos);
}

void LEDClass::setXPos(const int &XPos){
    xPos = XPos;
}

void LEDClass::setYPos(const int &YPos){
    yPos = YPos;
}

double LEDClass::getDistance(){
    return distance;
}

uint8_t LEDClass::getRed(){
    return red;
}

uint8_t LEDClass::getGreen(){
    return green;
}

uint8_t LEDClass::getBlue(){
    return blue;
}

int LEDClass::getXPos(){
    return xPos;
}

int LEDClass::getYPos(){
    return yPos;
}
