#include "ICECar.hpp"

ICECar::ICECar(int id, ChasisType type, FuelType ft, int cap)
:_id{id}, _type{type}, _fl{ft}, _cap{cap}
{}

std::ostream &operator<<(std::ostream &os, const ICECar &rhs) {
    std::string ch {""};
    std::string bt {""};

    if(rhs._type == ChasisType::LADDER){
        ch = "Ladder";
    }
    else{
        ch = "Tubular";
    }

    if(rhs._fl == FuelType::DIESEL){
        bt = "Diesel";
    }
    else{
        bt = "Petrol";
    }
    
    os << "_id: " << rhs._id
       << " _type: " << ch
       << " _fl: " << bt
       << " _cap: " << rhs._cap;
    return os;
}
