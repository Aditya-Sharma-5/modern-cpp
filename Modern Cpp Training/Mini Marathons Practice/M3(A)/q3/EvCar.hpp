#ifndef EVCAR_HPP
#define EVCAR_HPP

#include "ChasisType.hpp"
#include "BatteryType.hpp"
#include<iostream>

class EvCar
{
private:
    /* data */
    int _id;
    ChasisType _chasis;
    BatteryType _battery;
    float _cap;
public:
    EvCar(/* args */) = delete;
    
    EvCar(int id, ChasisType chasis, BatteryType bat, float cap);

    ~EvCar() {}

    BatteryType battery() const { return _battery; }

    ChasisType chasis() const { return _chasis; }

    int id() const { return _id; }

    float cap() const { return _cap; }

    friend std::ostream &operator<<(std::ostream &os, const EvCar &rhs);
};


#endif // EVCAR_HPP
