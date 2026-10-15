#include "ICEngine.h"

ICEngine::ICEngine(std::string id, int hp, float tq, EngineType type, bool warranty)
: m_ic_engine_id{id} , m_ic_engine_horsepower{hp} , m_ic_engine_torque{tq} , m_engine_type{type} , m_is_engine_under_warranty{warranty}
{
}
float ICEngine::AnnualEngineMaintenanceCost()
{
    if(m_engine_type == EngineType::DIESEL){
        return (10*m_ic_engine_horsepower);
    }
    return (8*m_ic_engine_horsepower);
}
std::ostream &operator<<(std::ostream &os, const ICEngine &rhs)
{
    os << "m_ic_engine_id: " << rhs.m_ic_engine_id
       << " m_ic_engine_horsepower: " << rhs.m_ic_engine_horsepower
       << " m_ic_engine_torque: " << rhs.m_ic_engine_torque
       << " m_engine_type: " <<static_cast<int>( rhs.m_engine_type)
       << " m_is_engine_under_warranty: " << rhs.m_is_engine_under_warranty;
    return os;
}
