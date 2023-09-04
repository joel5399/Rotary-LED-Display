#ifndef LED_H
#define LED_H

typedef unsigned char uint8_t;

class LED
{
public:
    LED();

    void set_Distance(double Distance);
    void set_Red(uint8_t Red);
    void set_Green(uint8_t Green);
    void set_Blue(uint8_t Blue);
    void set_x(int x);
    void set_y(int y);


    double get_Distance();
    uint8_t get_Red();
    uint8_t get_Green();
    uint8_t get_Blue();
    int get_x();
    int get_y();
    
private:
    //Variables
    //Collor
    uint8_t Red_;
    uint8_t Green_;
    uint8_t Blue_;

    //Position
    double Distance_;
    int x_;
    int y_;
};

#endif // LED_H
