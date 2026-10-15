#include "EvCar.h"

EvCar::EvCar(float battery, float price, ChargingType type)
    : _battery_capacity{battery}, _price{price}, _charging_type{type}
{
}

float EvCar::CalculateGST()
{
    return (0.1)*_price;
}

std::ostream &operator<<(std::ostream &os, const EvCar &rhs) {
    os << "_battery_capacity: " << rhs._battery_capacity
       << " _price: " << rhs._price
       << " _charging_type: " << static_cast<int>(rhs._charging_type);
    return os;
}
