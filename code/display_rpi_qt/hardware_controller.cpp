#include <pigpiod_if2.h>
#include "hardware_controller.hpp"

enum class Pin {
    HALL_SENSOR = 3;            //!< TODO Define correct pin
};

const unsigned int BAUD_RATE = 1_000_000; //!< Baud rate for spi communication


HardwareController::HardwareController() {
    this->pi = pigpio_start(NULL, NULL);
    if (this->pi < 0) {
        throw std::runtime_error("error while trying to initialize pigpio!");
        return;
    }

    this->spi = spiOpen(0, BAUD_RATE, 0);
    if (this->spi < 0) {
        throw std::runtime_error("error while trying to initialize spi!");
        return;
    }

    // PWMs
    set_mode(this->pi, static_cast<uint>(Pin::PWM_LEFT), PI_OUTPUT);
    set_mode(this->pi, static_cast<uint>(Pin::PWM_RIGHT), PI_OUTPUT);

    set_PWM_frequency(this->pi, static_cast<uint>(Pin::PWM_LEFT), PWM_FREQ);
    set_PWM_frequency(this->pi, static_cast<uint>(Pin::PWM_RIGHT), PWM_FREQ);

    set_PWM_range(this->pi, static_cast<uint>(Pin::PWM_LEFT), PWM_RANGE);
    set_PWM_range(this->pi, static_cast<uint>(Pin::PWM_RIGHT), PWM_RANGE);

    // GPIOs
    set_mode(this->pi, static_cast<uint>(Pin::DIR_LEFT_1), PI_OUTPUT);
    set_mode(this->pi, static_cast<uint>(Pin::DIR_LEFT_2), PI_OUTPUT);
    set_mode(this->pi, static_cast<uint>(Pin::DIR_RIGHT_1), PI_OUTPUT);
    set_mode(this->pi, static_cast<uint>(Pin::DIR_RIGHT_2), PI_OUTPUT);

    gpio_write(this->pi, static_cast<uint>(Pin::DIR_LEFT_1), 0);
    gpio_write(this->pi, static_cast<uint>(Pin::DIR_LEFT_2), 0);
    gpio_write(this->pi, static_cast<uint>(Pin::DIR_RIGHT_1), 0);
    gpio_write(this->pi, static_cast<uint>(Pin::DIR_RIGHT_2), 0);
}

HardwareController::~HardwareController() {
    pigpio_stop(this->pi);
    spiClose(this->spi);
}

int HardwareController::updateSpi(char* buf, unsigned count) const {
    int sendedData = spiWrite(this->spi, buf, count);
    return sendedData != count ? 1 : 0;
}



void HardwareController::setInterrupt(const int& pinInterrupt) const {

}


