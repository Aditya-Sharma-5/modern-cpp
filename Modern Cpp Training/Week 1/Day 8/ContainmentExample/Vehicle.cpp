#include "Vehicle.h"
std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "_id: " << rhs._id
       << " _name: " << rhs._name
       << " _vehicle_type: " <<static_cast<int>( rhs._vehicle_type)
       << " _permit: " << *(rhs._permit);
    return os;
}

Vehicle::Vehicle(std::string id, std::string name, VehicleType vehicle_type, VehicleRegistrationPermit *permit)
: _id{id} , _name{name} , _vehicle_type{vehicle_type} , _permit{permit}
{
}

Vehicle::Vehicle(std::string id, std::string name, VehicleType vehicle_type, Permit *permit)
{
}
