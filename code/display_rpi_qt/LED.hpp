#ifndef LED_HPP
#define LED_HPP

typedef unsigned char uint8_t;

class LEDClass
{
public:
    LEDClass();

    void setDistance(const double& Distance);
    void setRed(const uint8_t& Red);
    void setGreen(const uint8_t& Green);
    void setBlue(const uint8_t& Blue);
    void setXYCartesianFromAngle(const double& angle, const int& wingSpan);


    double getDistance();
    uint8_t getRed();
    uint8_t getGreen();
    uint8_t getBlue();
    int getXPos();
    int getYPos();

private:
    void setXPos(const int& XPos);
    void setYPos(const int& YPos);
    //Variables

    //Collor
    uint8_t red;
    uint8_t green;
    uint8_t blue;

    //Position
    double distance; //distance from beginnning of the strip
    int xPos;
    int yPos;
};

#endif // LED_HPP
