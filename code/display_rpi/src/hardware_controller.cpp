#include "hardware_controller.hpp"


const unsigned SPI_CHANNEL = 0;
const unsigned BAUD_RATE = 8000000; //!< Baud rate for spi communication

// Definition der statischen Member-Variable
RotationController* HardwareController::rotationController = nullptr;

HardwareController::HardwareController() {
    this->pi = pigpio_start(NULL, NULL);
    if (this->pi < 0) {
        std::cout << this->pi << "\n";
        throw std::runtime_error("error while trying to initialize pigpio!");
        return;
    }

    this->spi = spi_open(this->pi, SPI_CHANNEL, BAUD_RATE, 0);
    if (this->spi < 0) {
        throw std::runtime_error("error while trying to initialize spi!");
        return;
    }
    std::cout << "pi ID: " << this->pi << "\n";
    std::cout << "spi ID: " << this->spi << "\n";

    rotationController = nullptr;
}

HardwareController::~HardwareController() {
    spi_close(this->pi, this->spi);
    pigpio_stop(this->pi);
}

int HardwareController::updateSpi(char* buf, unsigned count) const {
    int sendedData = spi_write(this->pi, this->spi, buf, count);
    return unsigned(sendedData) != count ? 1 : 0;
}

void HardwareController::setInterrupt(const unsigned& pinInterrupt, RotationController* RotationController_) {
    rotationController = RotationController_;
    int callbackId = callback(this->pi, pinInterrupt, RISING_EDGE, this->callbackFunction);
    std::cout << "callback ID: " << callbackId << "\n";
}

unsigned HardwareController::getCurrentTick() const {
    return get_current_tick(this->pi);
}

void HardwareController::callbackFunction(int pi, unsigned user_gpio, unsigned level, unsigned tick) {
    rotationController->setCurrentAngleToZero(tick);
}
