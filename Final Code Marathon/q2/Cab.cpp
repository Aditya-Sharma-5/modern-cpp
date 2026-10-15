#include "Cab.h"

Cab::Cab(std::string reg, CabType type, CabStatus status, unsigned int seat, CabFuelType ftype, bool insured)
: m_cab_reg_number{reg} , m_cab_type{type} , m_cab_status{status} , m_cab_seat_count{seat} , m_cab_fuel_type{ftype} , m_is_cab_insured{insured}
{
}
std::ostream &operator<<(std::ostream &os, const Cab &rhs) {
    os << "m_cab_reg_number: " << rhs.m_cab_reg_number
       << " m_cab_type: " <<static_cast<int>( rhs.m_cab_type)
       << " m_cab_status: " <<static_cast<int>( rhs.m_cab_status)
       << " m_cab_seat_count: " << rhs.m_cab_seat_count
       << " m_cab_fuel_type: " <<static_cast<int>( rhs.m_cab_fuel_type)
       << " m_is_cab_insured: " << rhs.m_is_cab_insured;
    return os;
}
