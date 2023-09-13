#include <pigpiod_if2.h>
#include "smt_movement_controller/gpio_controller.hpp"
#include "smt_movement_controller/movement_controller.hpp"

enum class Pin {
    PWM_LEFT = 4,      //!< pwm motor Left (Pyhsical 7)
    PWM_RIGHT = 5,     //!< pwm motor right (Physical 29)
    DIR_LEFT_1 = 17,   //!< direction pin left 1 (Physical 11)
    DIR_LEFT_2 = 27,   //!< direction pin left 2 (Physical 13)
    DIR_RIGHT_1 = 6,   //!< direction pin right 1 (Physical 31)
    DIR_RIGHT_2 = 13,  //!< direction pin right 2 (Physical 33)
};

const int PWM_FREQ = 20000;      //!< Hertz
const int PWM_RANGE = 100;       //!< Range for pwm 0% to 100%
const double MAX_SPEED = 0.715;  //!< m/s measured


        SpiController::SpiController() {
            this->pi = pigpio_start(NULL, NULL);
            if (this->pi < 0) {
                throw std::runtime_error("error while trying to initialize pigpio!");
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

        SpiController::~SpiController() {
            pigpio_stop(this->pi);
        }



