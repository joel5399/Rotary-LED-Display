#ifndef HARDWARE_CONTROLLER_HPP
#define HARDWARE_CONTROLLER_HPP

#include <pigpiod_if2.h>
#include <iostream>

#include "rotation_controller.hpp"

class HardwareController {
public:
    HardwareController();
    ~HardwareController();

    /*returns 1 if transfer wasnt successfully*/
    int updateSpi(char* buf, unsigned count) const;
    void setInterrupt(const unsigned& pinInterrupt, RotationController* RotationController_);
    unsigned getCurrentTick() const;

    static RotationController* rotationController;
private:
    static void callbackFunction(int pi, unsigned user_gpio, unsigned level, unsigned int tick);

    int pi; //< the ID returned by pigpio_start
    int spi; //< the handle returned by spiOpen
};


#endif  // HARDWARE_CONTROLLER_HPP
