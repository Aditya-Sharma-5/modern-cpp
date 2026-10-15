#include "EvCar.h"

EvCar::EvCar(std::string id, std::string brand_name, float price, EPowerType E_power_type, BatterType battery_type)
    : _id{id}, _brand_name{brand_name}, _price{price}, _E_power_type{E_power_type}, _battery_type{battery_type}
{
}
float EvCar::CalculateRegistrationCharges()
{
    if (_E_power_type == EPowerType::HYBRID)
    {
        return 0.5 * _price;
    }
    else
    {
        return 0.8 * _price;
    }
}
std::ostream &operator<<(std::ostream &os, const EvCar &rhs)
{
    os << "_id: " << rhs._id
       << " _brand_name: " << rhs._brand_name
       << " _price: " << rhs._price
       << " _E_power_type: " << static_cast<int>(rhs._E_power_type)
       << " _battery_type: " << static_cast<int>(rhs._battery_type);
    return os;
}
