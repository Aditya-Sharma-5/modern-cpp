#include "ElectricVehicle.h"

ElectricVehicle::ElectricVehicle(std::string id, std::string model, BatteryType battery_type,float batteryCapacity, Motor *motor)
: _id{id} , _model{model} , _battery_type{battery_type},_batteryCapacity{batteryCapacity} , _motor{motor}
{
    if(_batteryCapacity>80.0f){
        throw InvalidInputError("Battery Capacity cannot be above 80");
    }
}

std::ostream &operator<<(std::ostream &os, const ElectricVehicle &rhs) {
    os << "_id: " << rhs._id
       << " _model: " << rhs._model
       << " _battery_type: " <<static_cast<int> (rhs._battery_type);
       if(rhs._motor){
       os<< " _motor: " << rhs._motor;
       }
    return os;
}

float ElectricVehicle::EvaluateChargingRate()
{
    if(_battery_type == BatteryType::LITHIUM_ION){
        return (3.3 * _batteryCapacity);
    }
    else{
        return (2.7 * _batteryCapacity);
    }
}

float ElectricVehicle::operator+(const ElectricVehicle &obj)
{

    return (this->batteryCapacity() + obj.batteryCapacity());
}
