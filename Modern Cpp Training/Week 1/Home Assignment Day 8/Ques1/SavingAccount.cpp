#include "SavingAccount.h"

SavingAccount::SavingAccount(std::string account_number, float account_balance, std::string account_holder_name, float minimum_account_balance)
    : Account(account_number, account_balance, account_holder_name)
{
    m_minimum_account_balance = minimum_account_balance;
}

SavingAccount::SavingAccount(std::string account_number, float account_balance, std::string account_holder_name, DebitCard *debit_card, float minimum_account_balance)
    : Account(account_number, account_balance, account_holder_name, debit_card)
{
    m_minimum_account_balance = minimum_account_balance;
}

float SavingAccount::CalculateAnnualCharges()
{
    if(debitCard() == nullptr){
        return 100.0f;
    }
    else{
        return 500.0f;
    }
}
