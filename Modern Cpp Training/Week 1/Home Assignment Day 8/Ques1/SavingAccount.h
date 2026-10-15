#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

#include"Account.h"

class SavingAccount: public Account
{
private:
    float m_minimum_account_balance{5000.0f};
public:
    SavingAccount() = default;
    ~SavingAccount() = default;

    SavingAccount(const SavingAccount&) = delete;
    SavingAccount( SavingAccount&&) = delete;

    SavingAccount& operator=(const SavingAccount&) = delete;
    SavingAccount& operator=(const SavingAccount&&) = delete;

    SavingAccount(std::string account_number , float account_balance , std::string account_holder_name ,  float minimum_account_balance);


    SavingAccount(std::string account_number , float account_balance , std::string account_holder_name , DebitCard* debit_card, float minimum_account_balance);

    float minimumAccountBalance() const { return m_minimum_account_balance; };

    float CalculateAnnualCharges() override;
};

#endif // SAVINGACCOUNT_H
