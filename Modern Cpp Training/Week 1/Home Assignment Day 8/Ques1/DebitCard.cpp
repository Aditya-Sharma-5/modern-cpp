
#include"DebitCard.h"
std::ostream &operator<<(std::ostream &os, const DebitCard &rhs) {
    os << "_CVV: " << rhs._CVV
       << " _card_number: " << rhs._card_number
       << " _expiry_date: " << rhs._expiry_date;
    return os;
}

DebitCard::DebitCard(std::string CVV, std::string card_number, int expiry_date)
:_CVV{CVV} , _card_number{card_number} , _expiry_date{expiry_date}
{
}
