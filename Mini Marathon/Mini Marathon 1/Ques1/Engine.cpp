#include "Engine.h"

Engine::Engine(std::string engineId, unsigned int horsepower, EngineType engineType, float engineCapacity, float engineTorque)
: _engineId{engineId} , _horsepower{horsepower} , _engineType{engineType} , _engineCapacity{engineCapacity} , _engineTorque{engineTorque}
{
}
std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
    os << "_engineId: " << rhs._engineId
       << " _horsepower: " << rhs._horsepower
       << " _engineType: " <<static_cast<int> (rhs._engineType)
       << " _engineCapacity: " << rhs._engineCapacity
       << " _engineTorque: " << rhs._engineTorque;
    return os;
}
