#ifndef ICECAR_HPP
#define ICECAR_HPP

#include "ChasisType.hpp"
#include "FuelType.hpp"
#include<iostream>

class ICECar
{
private:
    /* data */
    int _id;
    ChasisType _type;
    FuelType _fl;
    int _cap;
public:
    ICECar(/* args */) = delete;

    ICECar(int id, ChasisType type, FuelType ft, int cap);
    ~ICECar() {}

    int id() const { return _id; }

    ChasisType type() const { return _type; }

    FuelType fl() const { return _fl; }

    int cap() const { return _cap; }

    friend std::ostream &operator<<(std::ostream &os, const ICECar &rhs);
};

#endif // ICECAR_HPP
