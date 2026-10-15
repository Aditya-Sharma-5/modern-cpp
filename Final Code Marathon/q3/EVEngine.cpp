#include "EVEngine.h"

EVEngine::EVEngine(std::string id, int hp, float tq, BatteryType type, bool warranty)
: m_ev_engine_id{id} , m_ev_engine_horsepower{hp} , m_ev_engine_torque{tq} , m_engine_battery_pack_type{type} , m_is_engine_under_warranty{warranty}
{
}
float EVEngine::AnnualMaintainanceCost()
{
    if(m_engine_battery_pack_type == BatteryType::OTHER){
        return(0.03 *  m_ev_engine_horsepower);
    }
    return (0.05 * m_ev_engine_horsepower);
}
std::ostream &operator<<(std::ostream &os, const EVEngine &rhs)
{
    os << "m_ev_engine_id: " << rhs.m_ev_engine_id
       << " m_ev_engine_horsepower: " << rhs.m_ev_engine_horsepower
       << " m_ev_engine_torque: " << rhs.m_ev_engine_torque
       << " m_engine_battery_pack_type: " <<static_cast<int>( rhs.m_engine_battery_pack_type)
       << " m_is_engine_under_warranty: " << rhs.m_is_engine_under_warranty;
    return os;
}
