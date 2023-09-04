#include "LED.h"



LED::LED(){
    Distance_ = 0;
    Red_ = 0;
    Green_ = 0;
    Blue_ = 0;
    x_ = 0;
    y_ = 0;
}

void LED::set_Distance(double Distance){
    Distance_ = Distance;
}

void LED::set_Red(uint8_t Red){
    Red_ = Red;
}

void LED::set_Green(uint8_t Green){
    Green_ = Green;
}

void LED::set_Blue(uint8_t Blue){
    Blue_ = Blue;
}

void LED::set_x(int x){
    x_ = x;
}

void LED::set_y(int y){
    y_ = y;
}

double LED::get_Distance(){
    return Distance_;
}

uint8_t LED::get_Red(){
    return Red_;
}

uint8_t LED::get_Green(){
    return Green_;
}

uint8_t LED::get_Blue(){
    return Blue_;
}

int LED::get_x(){
    return x_;
}

int LED::get_y(){
    return y_;
}