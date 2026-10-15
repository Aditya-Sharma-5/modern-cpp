#ifndef CAR_H
#define CAR_H

#include <iostream>
#include "Engine.h"
#include <functional>

using RefWrapper = std::reference_wrapper<Engine>;

class Car
{
private:
    std::string _m_car_reg_num;
    float _m_price;
    RefWrapper _m_car_engine;

public:
    Car() = default;                      // Default constructor
    Car(  std::string m_car_reg_num,float m_price,RefWrapper m_car_engine);
    Car(const Car &) = default;           // Copy constructor
    Car &operator=(const Car &) = delete; // Copy assignment operator
    Car(Car &&) = delete;                 // Move constructor
    Car &operator=(Car &&) = delete;      // Move assignment operator
    ~Car() = default;                     // Destructor

    std::string mCarRegNum() const { return _m_car_reg_num; }

    float mPrice() const { return _m_price; }

    RefWrapper mCarEngine() const { return _m_car_engine; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif // CAR_H
