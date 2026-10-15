#include "Engine.h"

Engine::Engine(std::string engine_number, EngineType engine_type, int engine_horsepower, int engine_torque)
: _engine_number{engine_number} , _engine_type{engine_type} , _engine_horsepower{engine_horsepower}, _engine_torque{engine_torque}
{
}
std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
    os << "_engine_number: " << rhs._engine_number<<" \n"
       << " _engine_type: ";

    if(static_cast<int>(rhs._engine_type) == 1){
        os<<"ICT \n";
    }
    else{
        os<<"HYBRID \n";
    }

    os   << " _engine_horsepower: " << rhs._engine_horsepower<<" \n"
       << " _engine_torque: " << rhs._engine_torque;
    return os;
}
