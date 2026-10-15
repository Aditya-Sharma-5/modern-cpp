#include "Bike.h"

Bike::Bike(float price, std::string brand, VehicleType vtype, float engine, int seat)
: bikePrice{price} , bikeBrand{brand} , bikeVehicleType{vtype} , bikeEngineCC{engine} , bikeSeatCount{seat}
{
    if(bikeSeatCount <0 && bikeSeatCount>2){
        throw InvalidInput("Invalid Seat Provided !!\n" , std::future_errc::no_state);
    }
}
std::ostream &operator<<(std::ostream &os, const Bike &rhs) {
    os << "bikePrice: " << rhs.bikePrice
       << " bikeBrand: " << rhs.bikeBrand
       << " bikeVehicleType: " <<static_cast<int>( rhs.bikeVehicleType)
       << " bikeEngineCC: " << rhs.bikeEngineCC
       << " bikeSeatCount: " << rhs.bikeSeatCount;
    return os;
}
