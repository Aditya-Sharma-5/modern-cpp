#ifndef CARUNIT_H
#define CARUNIT_H

#include "CarType.h"
#include "GearSystemType.h"
#include <iostream>

class CarUnit 
{
private:
   std::string _m_car_brand;
   float _m_car_price;
   CarType _m_car_type;
   int _m_car_top_speed;
   int _m_car_top_rpm;
   GearSystemType _m_car_gear_system;
    
public:
    CarUnit() = default; // Default constructor
    CarUnit(std::string m_car_brand,float m_car_price,CarType m_car_type,int m_car_top_speed,int m_car_top_rpm,GearSystemType m_car_gear_system );
    CarUnit(const CarUnit&) = default; // Copy constructor
    CarUnit& operator=(const CarUnit&) = delete; // Copy assignment operator
    CarUnit(CarUnit&&) = delete; // Move constructor
    CarUnit& operator=(CarUnit&&) = delete; // Move assignment operator
    ~CarUnit() = default; // Destructor

    std::string mCarBrand() const { return _m_car_brand; }

    float mCarPrice() const { return _m_car_price; }

    CarType mCarType() const { return _m_car_type; }

    int mCarTopSpeed() const { return _m_car_top_speed; }

    int mCarTopRpm() const { return _m_car_top_rpm; }

    GearSystemType mCarGearSystem() const { return _m_car_gear_system; }

    friend std::ostream &operator<<(std::ostream &os, const CarUnit &rhs);
};

#endif // CARUNIT_H
