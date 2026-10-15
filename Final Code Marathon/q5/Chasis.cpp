#include "Chasis.h"

Chasis::Chasis(ChasisType ctype, float wid, float len, bool ev, bool ncap, ChasisMaterial mat)
: m_chasis_type{ctype} , m_chasis_width{wid} , m_chasis_length{len} , m_is_chasis_platform_ev_compatible{ev} , m_is_chasis_ncap_compliant{ncap} , m_chasis_material{mat}
{
}
std::ostream &operator<<(std::ostream &os, const Chasis &rhs) {
    os << "m_chasis_type: " <<static_cast<int>( rhs.m_chasis_type)
       << " m_chasis_width: " << rhs.m_chasis_width
       << " m_chasis_length: " << rhs.m_chasis_length
       << " m_is_chasis_platform_ev_compatible: " << rhs.m_is_chasis_platform_ev_compatible
       << " m_is_chasis_ncap_compliant: " << rhs.m_is_chasis_ncap_compliant
       << " m_chasis_material: " <<static_cast<int>( rhs.m_chasis_material)<<"\n\n";
    return os;
}
