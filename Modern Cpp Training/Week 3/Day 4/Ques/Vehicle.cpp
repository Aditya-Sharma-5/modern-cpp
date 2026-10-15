#include "Vehicle.h"


Vehicle::Vehicle(std::string id, float price, ChassisType ctype, VehicleCategory vCategory, float len, FeatureList feature)
: m_id{id} , m_price{price} , m_chassis_type{ctype} , m_vehicle_category{vCategory} , m_chassis_length{len} , m_feature{feature}
{
}
std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "m_id: " << rhs.m_id
       << " m_price: " << rhs.m_price
       << " m_chassis_type: " <<static_cast<int>( rhs.m_chassis_type)
       << " m_vehicle_category: " <<static_cast<int>( rhs.m_vehicle_category)
       << " m_chassis_length: " <<static_cast<int>( rhs.m_chassis_length)
       << " m_feature: " ; 
       for(const Feature&  ft : rhs.m_feature){
            os<<static_cast<int>(ft)<<" ";
       }
       return os;
}
