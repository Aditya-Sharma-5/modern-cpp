#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

#include"Account.h"
#include <ostream>

class SavingAccount: public Account
{
private:
    float m_minimum_account_balance{2000.0f};
public:
    SavingAccount() = default ; 
    ~SavingAccount()  = default;

    //  Copy and Move Constructor
    SavingAccount(const SavingAccount&) = default;
    SavingAccount(SavingAccount&&) = default;


    // Copy And Move Assignment Operator
    SavingAccount& operator=(const SavingAccount&) = default;
    SavingAccount& operator=(SavingAccount&&) = default;

    SavingAccount(std::string account_number , std::string account_holder_name , float account_balance , DebitCard* debit_card, float minimum_account_balance);

    float minimumAccountBalance() const { return m_minimum_account_balance; }

    float CalculateAnnualCharges() override;

    friend std::ostream &operator<<(std::ostream &os, const SavingAccount &rhs);

};

#endif // SAVINGACCOUNT_H
