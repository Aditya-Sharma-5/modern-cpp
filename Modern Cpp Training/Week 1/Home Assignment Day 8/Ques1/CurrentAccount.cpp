#include "CurrentAccount.h"

CurrentAccount::CurrentAccount(std::string account_number, float account_balance, std::string account_holder_name, bool is_bussiness_loan_applied)
    : Account(account_number, account_balance, account_holder_name)
{
    m_is_bussiness_loan_applied = is_bussiness_loan_applied;

}

CurrentAccount::CurrentAccount(std::string account_number, float account_balance, std::string account_holder_name, DebitCard *debit_card, bool is_bussiness_loan_applied)
    : Account(account_number, account_balance, account_holder_name, debit_card)
{
    m_is_bussiness_loan_applied = is_bussiness_loan_applied;

}
float CurrentAccount::CalculateAnnualCharges()
{
    return 800.0f;
}
std::ostream &operator<<(std::ostream &os, const CurrentAccount &rhs)
{
    os << static_cast<const Account &>(rhs)
       << " m_is_bussiness_loan_applied: " << rhs.m_is_bussiness_loan_applied;
    return os;
}
