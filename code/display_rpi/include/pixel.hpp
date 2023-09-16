#ifndef PIXEL_HPP
#define PIXEL_HPP

#include <math.h>

class Pixel {
public:
    Pixel(const double& Distance);

    void setDistance(const double& Distance);
    void setRed(const char& Red);
    void setGreen(const char& Green);
    void setBlue(const char& Blue);
    void setXYCartesianFromAngle(const double& angle, const float& wingSpan);


    double getDistance();
    char getRed();
    char getGreen();
    char getBlue();
    float getXPos();
    float getYPos();

private:
    //Collor
    char red;
    char green;
    char blue;

    //Position
    double distance; //distance from beginnning of the strip
    float xPos;
    float yPos;
};

#endif // PIXEL_HPP
