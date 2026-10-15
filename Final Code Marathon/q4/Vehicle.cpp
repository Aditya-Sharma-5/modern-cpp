#include "Vehicle.h"

Vehicle::Vehicle(std::string id, std::string name, ReferenceWrapper unit)
: m_vehicle_id{id} , m_vehicle_model_name{name} , m_vehicle_sensor_unit{unit}
{
}
std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "m_vehicle_id: " << rhs.m_vehicle_id
       << " m_vehicle_model_name: " << rhs.m_vehicle_model_name
       << " m_vehicle_sensor_unit: " << rhs.m_vehicle_sensor_unit;
    return os;
}
