#ifndef EVCAR_H
#define EVCAR_H

#include "EpowerType.h"
#include "BatteryType.h"
#include <vector>
#include <memory>
#include <iostream>

class EvCar
{
private:
    std::string _id;
    std::string _brand_name;
    float _price;
    EPowerType _E_power_type;
    BatterType _battery_type;

public:
    EvCar() = default; // Default constructor
    EvCar(std::string id, std::string brand_name, float price, EPowerType E_power_type, BatterType battery_type);
    EvCar(const EvCar &) = default;           // Copy constructor
    EvCar &operator=(const EvCar &) = delete; // Copy assignment operator
    EvCar(EvCar &&) = delete;                 // Move constructor
    EvCar &operator=(EvCar &&) = delete;      // Move assignment operator
    ~EvCar() = default;                       // Destructor

    std::string id() const { return _id; }

    std::string brandName() const { return _brand_name; }

    float price() const { return _price; }

    EPowerType ePowerType() const { return _E_power_type; }

    BatterType batteryType() const { return _battery_type; }

    friend std::ostream &operator<<(std::ostream &os, const EvCar &rhs);
    float CalculateRegistrationCharges();
};

#endif // EVCAR_H
