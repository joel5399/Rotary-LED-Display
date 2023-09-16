#include "rotation_controller.hpp"

#include <iostream>
#include <cmath>

RotationController::RotationController() : currentAngle(0.0), tickLastZeroCrossing(0) {

}

void RotationController::setCurrentAngleToZero(const unsigned& tick) {
    currentAngle = 0.0;
    currentCycleTime_us = tick - tickLastZeroCrossing;
    tickLastZeroCrossing = tick;
}

double RotationController::getCurrentAngle(const unsigned& currentTick) const {
    const double currentAngle = (((double)(currentTick - tickLastZeroCrossing) / (double)(currentCycleTime_us)) * 2.0 * 3.14 + this->angleOffset);
    if (std::isinf(currentAngle)) {
        return 0;
    }
    return currentAngle;
}
