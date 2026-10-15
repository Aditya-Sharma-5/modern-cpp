#include "SavingAccount.h"

SavingAccount::SavingAccount(std::string account_number, std::string account_holder_name, float account_balance, DebitCard *debit_card, float minimum_account_balance)
: Account(account_number , account_holder_name , account_balance , debit_card)
{
    m_minimum_account_balance = minimum_account_balance;
}

std::ostream &operator<<(std::ostream &os, const SavingAccount &rhs) {
    os << static_cast<const Account &>(rhs)
       << " m_minimum_account_balance: " << rhs.m_minimum_account_balance;
    return os;
}

float SavingAccount::CalculateAnnualCharges()
{
    if(debitCard() == nullptr){
        return 100.0f;
    }
    return 500.0f;
}
