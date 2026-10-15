#ifndef CAR_H
#define CAR_H

#include"ChassisType.h"
#include <ostream>

class Car
{
private:
    int _seat_count;
    float _price;
    float _wheel_base;
    ChassisType _chassis;
public:
    Car()=delete;
    ~Car()=default;
    Car(const Car&&)=delete;
    Car(Car&&)=default;
    Car& operator=(Car&&)=delete;
    Car& operator=(const Car&)=delete;
    Car(int seat, float price, float wheel, ChassisType type);

    int seatCount() const { return _seat_count; }

    float price() const { return _price; }

    float wheelBase() const { return _wheel_base; }

    ChassisType chassis() const { return _chassis; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif // CAR_H
