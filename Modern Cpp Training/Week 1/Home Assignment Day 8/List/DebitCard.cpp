#include "DebitCard.h"

DebitCard::DebitCard(int CVV, int expiry_date)
: m_CVV{CVV} , m_expiry_date{expiry_date}
{
}
std::ostream &operator<<(std::ostream &os, const DebitCard &rhs) {
    os << "m_CVV: " << rhs.m_CVV
       << " m_expiry_date: " << rhs.m_expiry_date;
    return os;
}
