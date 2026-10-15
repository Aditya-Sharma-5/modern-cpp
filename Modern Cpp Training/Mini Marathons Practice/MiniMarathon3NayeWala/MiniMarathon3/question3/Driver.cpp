#include "Driver.h"
std::ostream &operator<<(std::ostream &os, const Driver &rhs) {

    std::string val="";

    if(rhs.driverRating()==DriverRating::ONESTAR){
        val= "1 Star";
    }
    else if(rhs.driverRating()==DriverRating::TWOSTAR){
        val="2 Star";
    }
    else{
        val="3 Star";
    }
    os << "_driver_id: " << rhs._driver_id
       << " _driver_rating: " << val;
    return os;
}

Driver::Driver(std::string id, DriverRating rating)
:_driver_id{id},_driver_rating{rating}
{
}