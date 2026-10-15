#include "CabRide.h"

std::ostream &operator<<(std::ostream &os, const CabRide &rhs) {
    
    std::visit([&](auto &&val ){os<<val;},rhs.id());

    std::string val1="";
    std::string val2="";
    if(rhs.rideType()==RideType::RENT){
        val1="Rental";
    }
    else if(rhs.rideType()==RideType::OUTSTATION){
        val1="Outstation";
    }
    else{
        val1="Local";
    }

    if(rhs.paymentMode()==PaymentMode::CASH){
        val2="Cash";
    }
    else if(rhs.paymentMode()==PaymentMode::UPI){
        val2="UPI";
    }
    else if(rhs.paymentMode()==PaymentMode::CARD){
        val2="CARD";
    }
    else{
        val2="Wallet";
    }



      os << " _ride_type: " << val1
       << " _payment_mode: " << val2
       << " _fare: " << rhs._fare
       << " _drop_location: " << rhs._drop_location
       << " _pickup_location: " << rhs._pickup_location
       << " _cab_driver: " << rhs._cab_driver;
    return os;
}

CabRide::CabRide(std::variant<std::string, int> id, RideType rtype, PaymentMode pmode, float fare, std::string drop, std::string pickup, std::reference_wrapper<Driver> driver)
:_id{id},_ride_type{rtype},_payment_mode{pmode},_fare{fare},_drop_location{drop},_pickup_location{pickup},_cab_driver{driver}
{

}
