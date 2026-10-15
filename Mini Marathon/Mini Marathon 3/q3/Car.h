#ifndef CAR_H
#define CAR_H

#include"VehicleType.h"
#include"InvalidInput.h"
#include<iostream>

class Car
{
private:
    float _carPrice;
    std::string _carBrand;
    VehicleType _carVehicleType;
    int _carSeatCount;
    float _carBootSpace;
public:
    Car() = default;
    ~Car() = default;

    Car(const Car&) = default;
    Car(Car&&) = default;

    Car& operator=(Car&&) = default;
    Car& operator=(const Car&) = default;

    Car(float price , std::string brand , VehicleType vtype , int seat , float bspace);

    float carPrice() const { return _carPrice; }
    void setCarPrice(float carPrice) { _carPrice = carPrice; }

    std::string carBrand() const { return _carBrand; }
    void setCarBrand(const std::string &carBrand) { _carBrand = carBrand; }

    VehicleType carVehicleType() const { return _carVehicleType; }
    void setCarVehicleType(const VehicleType &carVehicleType) { _carVehicleType = carVehicleType; }

    int carSeatCount() const { return _carSeatCount; }
    void setCarSeatCount(int carSeatCount) { _carSeatCount = carSeatCount; }

    float carBootSpace() const { return _carBootSpace; }
    void setCarBootSpace(float carBootSpace) { _carBootSpace = carBootSpace; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);

    float CalculateRTOCharges();

};

#endif // CAR_H
