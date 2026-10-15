#include "Engine.h"

Engine::Engine(std::string m_engine_number, int m_enggine_torque, int m_hourse_power, EngineType m_engine_type) : _m_engine_number{m_engine_number}, _m_enggine_torque{m_enggine_torque}, _m_hourse_power{m_hourse_power}, _m_engine_type{m_engine_type}
{
}
std::ostream &operator<<(std::ostream &os, const Engine &rhs)
{
    os << "_m_engine_number: " << rhs._m_engine_number
       << " _m_enggine_torque: " << rhs._m_enggine_torque
       << " _m_hourse_power: " << rhs._m_hourse_power;
    if (rhs._m_engine_type == EngineType::CRDI)
    {
        os << " Engine Type is CRDI ";
    }
    if (rhs._m_engine_type == EngineType::MPFI)
    {
        os << " Engine Type is MPFI ";
    }
    else
    {
        os << " Engine Type is TURBOCHARGED ";
    }
    return os;
}
