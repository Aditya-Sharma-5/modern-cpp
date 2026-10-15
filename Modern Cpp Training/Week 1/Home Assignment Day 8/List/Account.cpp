#include "Account.h"

Account::Account(std::string account_number, std::string account_holder_name, float account_balance, DebitCard *debit_card)
: m_account_number{account_number} , m_account_holder_name{account_holder_name} , m_account_balance{account_balance} , m_debit_card{debit_card}
{
}
std::ostream &operator<<(std::ostream &os, const Account &rhs) {
    os << "m_account_number: " << rhs.m_account_number
       << " m_account_holder_name: " << rhs.m_account_holder_name
       << " m_account_balance: " << rhs.m_account_balance
       << " m_debit_card: " ;
       if( rhs.m_debit_card){
        os<<*rhs.m_debit_card;
       }

    return os;
}
