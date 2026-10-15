#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include<iostream>
#include"AutoMobileType.h"

class Automobile
{
private:
    std::string _id;
    AutomobileType _type;
    float _price;
    int _seat_count;
    int _horse_power;
public:
    Automobile()=delete;
    ~Automobile()=default;
    Automobile(const Automobile&&)=delete;
    Automobile(Automobile&&)=delete;
    Automobile& operator=(Automobile&&)=delete;
    Automobile& operator=(const Automobile&)=delete;
    Automobile(std::string id, AutomobileType type, float price, int seat, int power);
    float CalculateGST();

    std::string id() const { return _id; }

    AutomobileType type() const { return _type; }

    float price() const { return _price; }

    int seatCount() const { return _seat_count; }

    int horsePower() const { return _horse_power; }

    friend std::ostream &operator<<(std::ostream &os, const Automobile &rhs);
};

#endif // AUTOMOBILE_H
