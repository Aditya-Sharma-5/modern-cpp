#include "CurrentAccount.h"

CurrentAccount::CurrentAccount(std::string account_number, std::string account_holder_name, float account_balance, DebitCard *debit_card, bool is_bussiness_loan_applied)
: Account(account_number , account_holder_name , account_balance , debit_card)
{
    m_is_bussiness_load_applied = is_bussiness_loan_applied;
}
float CurrentAccount::CalculateAnnualCharges()
{
    return 800.0f;
}
std::ostream &operator<<(std::ostream &os, const CurrentAccount &rhs)
{
    os << static_cast<const Account &>(rhs)
       << " m_is_bussiness_load_applied: " << rhs.m_is_bussiness_load_applied;
    return os;
}
