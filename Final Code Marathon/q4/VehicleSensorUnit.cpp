#include "VehicleSensorUnit.h"

VehicleSensorUnit::VehicleSensorUnit(SensorUnitType type, std::array<float, 5> last, float value)
: m_sensor_unit_type{type} , m_sensor_last_5_reading{last} , m_sensor_threshol_value{value}
{
}

std::ostream &operator<<(std::ostream &os, const VehicleSensorUnit &rhs) {
    os << "m_sensor_unit_type: " <<static_cast<int>( rhs.m_sensor_unit_type)
       << " m_sensor_last_5_reading: ";
       for(float val :  rhs.m_sensor_last_5_reading){
        std::cout<<val<<" ";
       }
      os << " m_sensor_threshol_value: " << rhs.m_sensor_threshol_value;
    return os;
}
