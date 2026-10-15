#ifndef EVCAR_H
#define EVCAR_H

#include"ChargingType.h"
#include<iostream>

class EvCar
{
private:
    float _battery_capacity;
    float _price;
    ChargingType _charging_type;
public:
    EvCar()=delete;
    ~EvCar()=default;
    EvCar(const EvCar&&)=delete;
    EvCar(EvCar&&)=delete;
    EvCar& operator=(EvCar&&)=delete;
    EvCar& operator=(const EvCar&)=delete;
    EvCar(float battery, float price, ChargingType type);

    float CalculateGST();

    float batteryCapacity() const { return _battery_capacity; }

    float price() const { return _price; }

    ChargingType chargingType() const { return _charging_type; }

    friend std::ostream &operator<<(std::ostream &os, const EvCar &rhs);
};

#endif // EVCAR_H
