#ifndef ROTATION_CONTROLLER_HPP
#define ROTATION_CONTROLLER_HPP

class RotationController {
public:
    RotationController();
    void setCurrentAngleToZero(const unsigned& tick);
    double getCurrentAngle(const unsigned& currentTick) const;

private:
    double currentAngle;
    unsigned currentCycleTime_us;
    unsigned tickLastZeroCrossing;
    const double angleOffset = 1.5;
};

#endif  // ROTATION_CONTROLLER_HPP
