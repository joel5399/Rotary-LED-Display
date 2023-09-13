#ifndef HARDWARE_CONTROLLER_HPP
#define HARDWARE_CONTROLLER_HPP

class HardwareController {
public:
    HardwareController();
    ~HardwareController();

    /*returns 1 if transfer wasnt successfully*/
    int updateSpi(char* buf) const;
    void setInterrupt(const int& pinInterrupt) const;

private:
    int pi; //< the ID returned by pigpio_start
    int spi; //< the handle returned by spiOpen
};

#endif  // HARDWARE_CONTROLLER_HPP
