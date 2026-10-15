#include "ICeCar.h"

ICeCar::ICeCar(std::string id, std::string brand_name, float price, EngineType engine_type) : _id{id}, _brand_name{brand_name}, _price{price}, _engine_type{engine_type}
{
}
float ICeCar::CalculateRegistrationCharges()
{
    if (_engine_type == EngineType::DIESEL)
    {
        return 0.13 * _price;
    }
    else
    {
        return 0.10 * _price;
    }
}
std::ostream &operator<<(std::ostream &os, const ICeCar &rhs)
{
    os << "_id: " << rhs._id
       << " _brand_name: " << rhs._brand_name
       << " _price: " << rhs._price
       << " _engine_type: " << static_cast<int>(rhs._engine_type);
    return os;
}
