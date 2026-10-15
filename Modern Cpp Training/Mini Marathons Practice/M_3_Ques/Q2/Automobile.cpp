#include "Automobile.h"

Automobile::Automobile(std::string id, AutomobileType type, float price, int seat, int power)
    : _id{id}, _type{type}, _price{price}, _seat_count{seat}, _horse_power{power}
{
}

float Automobile::CalculateGST()
{
    return (0.18)*_price;
}

std::ostream &operator<<(std::ostream &os, const Automobile &rhs) {
    os << "_id: " << rhs._id
       << " _type: " << static_cast<int>(rhs._type)
       << " _price: " << rhs._price
       << " _seat_count: " << rhs._seat_count
       << " _horse_power: " << rhs._horse_power;
    return os;
}
