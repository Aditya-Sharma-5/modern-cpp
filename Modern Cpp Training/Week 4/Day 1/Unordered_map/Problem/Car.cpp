#include "Car.h"



Car::Car(std::string reg, float price, CarType type)
: registration_number{reg} , m_price{price} , m_type{type}
{
}
std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "registration_number: " << rhs.registration_number
       << " m_price: " << rhs.m_price
       << " m_type: " <<static_cast<int>( rhs.m_type);
    return os;
}
