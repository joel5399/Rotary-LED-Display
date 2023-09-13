#ifndef SPI_CONTROLLER_HPP
#define SPI_CONTROLLER_HPP


class SpiController {
public:
    SpiController();
    ~SpiController();
    void setLedCollor(const int &ledNumber, const char &red, const char &green, const char &blue) const;

private:
    int pi; //< the ID returned by pigpio_start
};


#endif  // SPI_CONTROLLER_HPP
