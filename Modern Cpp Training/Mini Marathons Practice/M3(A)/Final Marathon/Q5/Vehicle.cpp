#include "Vehicle.h"

Vehicle::Vehicle(std::string vehicle_id, float vehicle_price, VehicleCategory vehicle_category, TransmissionType transmission_type, int boot_space, bool is_vehicle_insured)
    : m_vehicle_id{vehicle_id}, m_vehicle_price{vehicle_price}, m_vehicle_category{vehicle_category}, m_transmission_type{transmission_type}, m_boot_space{boot_space},m_is_vehicle_insured{is_vehicle_insured}
{
}
std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "m_vehicle_id: " << rhs.m_vehicle_id
       << " m_vehicle_price: " << rhs.m_vehicle_price
       << " m_vehicle_category: " << static_cast<int>(rhs.m_vehicle_category)
       << " m_transmission_type: " << static_cast<int>(rhs.m_transmission_type)
       << " m_boot_space: " << rhs.m_boot_space
       << " m_is_vehicle_insured: " << rhs.m_is_vehicle_insured;
    return os;
}
