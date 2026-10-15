#include "Vehicle.h"

Vehicle::Vehicle(std::string vehicle_id, float vehicle_price, VehicleType vehicle_type, std::string vehicle_model_name)
: _vehicle_id{vehicle_id} , _vehicle_price{vehicle_price} , _vehicle_type{vehicle_type} , _vehicle_model_name{vehicle_model_name}
{
}

Vehicle::Vehicle(std::string vehicle_id, std::string vehicle_model_name, VehicleType vehicle_type)
:_vehicle_id{vehicle_id} , _vehicle_model_name{vehicle_model_name} , _vehicle_type{vehicle_type}
{
}
