#ifndef LED_H
#define LED_H

typedef unsigned char uint8_t;

class LEDClass
{
public:
    LEDClass();

    void setDistance(double Distance);
    void setRed(uint8_t Red);
    void setGreen(uint8_t Green);
    void setBlue(uint8_t Blue);
    void setXPos(int x);
    void setYPos(int y);


    double getDistance();
    uint8_t getRed();
    uint8_t getGreen();
    uint8_t getBlue();
    int getXPos();
    int getYPos();
    
private:
    //Variables
    //Collor
    uint8_t red;
    uint8_t green;
    uint8_t blue;

    //Position
    double distance; //Distanz vom Mittelpunkt aus
    int xPos;
    int yPos;
};

#endif // LED_H
