#include "Automobile.h"

Automobile::Automobile(std::string id, unsigned int seat, AutomobileCategory category, unsigned int year, float price, AutomobileWheelType wtype, bool ncap)
: m_automobile_id{id} , m_automobile_seat_count{seat} , m_automobile_category{category} , m_automobile_manufacturing_year{year} , m_automobile_price{price} , m_automobile_wheel_type{wtype} , m_is_automobile_ncap_certified{ncap}
{
}
std::ostream &operator<<(std::ostream &os, const Automobile &rhs) {
    os << "m_automobile_id: " << rhs.m_automobile_id
       << " m_automobile_seat_count: " << rhs.m_automobile_seat_count
       << " m_automobile_category: " <<static_cast<int>( rhs.m_automobile_category)
       << " m_automobile_manufacturing_year: " << rhs.m_automobile_manufacturing_year
       << " m_automobile_price: " << rhs.m_automobile_price
       << " m_automobile_wheel_type: " <<static_cast<int>( rhs.m_automobile_wheel_type)
       << " m_is_automobile_ncap_certified: " << rhs.m_is_automobile_ncap_certified;
    return os;
}
