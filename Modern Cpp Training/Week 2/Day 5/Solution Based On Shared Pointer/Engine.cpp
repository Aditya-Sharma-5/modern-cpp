#include "Engine.h"

Engine::Engine(int engine_horse_power, float engine_torque)
: m_engine_horse_power{engine_horse_power} , m_engine_torque{engine_torque}
{
}
std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
    os << "m_engine_horse_power: " << rhs.m_engine_horse_power
       << " m_engine_torque: " << rhs.m_engine_torque;
    return os;
}
