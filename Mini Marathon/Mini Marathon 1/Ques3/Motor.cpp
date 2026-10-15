#include "Motor.h"

Motor::Motor(float time, float maxPower, int maxTorque)
: _time{time} , _maxPower{maxPower} , _maxTorque{maxTorque}
{
    if(_maxPower > 400){
        throw InvalidInputError("Max Power cannot be above 400");
    }
}


float Motor::operator+(const Motor &obj)
{
    return (obj.maxPower() + this->_maxPower);
}


std::ostream &operator<<(std::ostream &os, const Motor &rhs)
{
    os << "_time: " << rhs._time
       << " _maxPower: " << rhs._maxPower
       << " _maxTorque: " << rhs._maxTorque;
    return os;
}
