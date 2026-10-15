#include "BussinessOwner.h"

BussinessOwner::BussinessOwner(std::string name, BussinessType type, std::string location, float profit)
: m_registered_name{name} , m_bussinessType{type} , m_bussiness_location{location} , m_profit{profit}
{
}
float BussinessOwner::CalculateTaxAmount() const
{
    if(m_bussinessType== BussinessType::PVT_LTD){
        return (0.15 * m_profit);
    }
    return 0.1*m_profit;
}
std::ostream &operator<<(std::ostream &os, const BussinessOwner &rhs)
{
    os << "m_registered_name: " << rhs.m_registered_name
       << " m_bussinessType: " <<static_cast<int>( rhs.m_bussinessType)
       << " m_bussiness_location: " << rhs.m_bussiness_location
       << " m_profit: " << rhs.m_profit;
    return os;
}
