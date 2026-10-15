#include "EvCar.hpp"

EvCar::EvCar(int id, ChasisType chasis, BatteryType bat, float cap)
:_id{id}, _chasis{chasis}, _battery{bat}, _cap{cap}
{}

std::ostream &operator<<(std::ostream &os, const EvCar &rhs) {

    std::string ch {""};
    std::string bt {""};

    if(rhs._chasis == ChasisType::LADDER){
        ch = "Ladder";
    }
    else{
        ch = "Tubular";
    }

    if(rhs._battery == BatteryType::LI_ION){
        bt = "Li-ion";
    }
    else{
        bt = "Ni-Cad";
    }

    os << "_id: " << rhs._id
       << " _chasis: " << ch
       << " _battery: " << bt
       << " _cap: " << rhs._cap;
    return os;
}
