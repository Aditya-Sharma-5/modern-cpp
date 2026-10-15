#include "Car.h"

Car::Car(float price, std::string brand, VehicleType vtype, int seat, float bspace)
: _carPrice{price} , _carBrand{brand} , _carVehicleType{vtype} , _carSeatCount{seat} , _carBootSpace{bspace}
{
    if(_carSeatCount >7 && _carSeatCount<2){
        throw InvalidInput("Invalid Seat Count Input \n" , std::future_errc::no_state);
    }
}
float Car::CalculateRTOCharges()
{
    if(_carVehicleType == VehicleType::SPORTS || _carVehicleType == VehicleType::UTILITY){
        return (_carPrice * 0.2);
    }
    else{
        return (_carPrice* 0.1);
    }
}
std::ostream &operator<<(std::ostream &os, const Car &rhs)
{
    os << "_carPrice: " << rhs._carPrice
       << " _carBrand: " << rhs._carBrand
       << " _carVehicleType: " <<static_cast<int>( rhs._carVehicleType)
       << " _carSeatCount: " << rhs._carSeatCount
       << " _carBootSpace: " << rhs._carBootSpace;
    return os;
}
