#include "Vehicle.h"

Vehicle::Vehicle(std::string reg_number, float price, VehicleType vtype, float len, float width, TransmissionType transmission_type, VehicleFuelType ftype, EngineRefWrapper ref)
: m_vehicle_reg_number{reg_number} , m_vehicle_price{price} , m_vehicle_type{vtype} , m_vehicle_chassis_length{len} , m_vehicle_chassis_width{width},
m_vehicle_transmission_type{transmission_type} , m_vehicle_fuel_type{ftype} , m_engine_ref{ref}

{}
std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "m_vehicle_reg_number: " << rhs.m_vehicle_reg_number
       << " m_vehicle_price: " << rhs.m_vehicle_price
       << " m_vehicle_type: " <<static_cast<int>( rhs.m_vehicle_type)
       << " m_vehicle_chassis_length: " << rhs.m_vehicle_chassis_length
       << " m_vehicle_chassis_width: " << rhs.m_vehicle_chassis_width
       << " m_vehicle_transmission_type: " <<static_cast<int>( rhs.m_vehicle_transmission_type)
       << " m_vehicle_fuel_type: " <<static_cast<int>( rhs.m_vehicle_fuel_type)
       << " m_engine_ref: " << rhs.m_engine_ref;
    return os;
}
