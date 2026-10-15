#include "Vehicle.h"

Vehicle::Vehicle(int id, std::string name, float price, unsigned int s_cnt, VehicleType vtype)
: m_id{id} , m_name{name} , m_price{price} , m_seat_count{s_cnt} , m_vehicle_type{vtype}
{
}
std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "m_id: " << rhs.m_id
       << " m_name: " << rhs.m_name
       << " m_price: " << rhs.m_price
       << " m_seat_count: " << rhs.m_seat_count
       << " m_vehicle_type: " <<( rhs.m_vehicle_type);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VehicleType &rhs)
{
    if(rhs == VehicleType::DEFENCE){
        os<<"DEFENCE";
    }
    else if(rhs == VehicleType::PUBLIC_TRANSPORT){
        os<<"PUBLIC_TRANSPORT";
    }
    else{
        os<<"PRIVATE";
    }
    return os;
}
