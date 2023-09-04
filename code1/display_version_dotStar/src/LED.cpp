#include "LED.h"



LEDClass::LEDClass(){
    distance = 0;
    red = 0;
    green = 0;
    blue = 0;
    xPos = 0;
    yPos = 0;
}

void LEDClass::setDistance(double distance){
    distance = distance;
}

void LEDClass::setRed(uint8_t red){
    red = red;
}

void LEDClass::setGreen(uint8_t green){
    green = green;
}

void LEDClass::setBlue(uint8_t blue){
    blue = blue;
}

void LEDClass::setXPos(int xPos){
    xPos = xPos;
}

void LEDClass::setYPos(int yPos){
    yPos = yPos;
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