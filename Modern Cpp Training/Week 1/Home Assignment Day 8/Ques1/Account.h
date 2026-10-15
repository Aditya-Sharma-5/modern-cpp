#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "DebitCard.h"
#include<iostream>

class Account
{
private:
    std::string m_account_number{""};
    float m_account_balance{0};
    std::string m_account_holder_name{""};
    DebitCard* m_debit_card{nullptr};
public:
    Account() = default;
    ~Account() = default;

    Account(const Account&) = delete;
    Account( Account&&) = delete;

    Account& operator=(const Account&) = delete;
    Account& operator=(const Account&&) = delete;

    Account(std::string account_number , float account_balance , std::string account_holder_name );

    Account(std::string account_number , float account_balance , std::string account_holder_name , DebitCard* debit_card);

    std::string accountNumber() const { return m_account_number; }

    float accountBalance() const { return m_account_balance; }

    std::string accountHolderName() const { return m_account_holder_name; }

    DebitCard* debitCard() const { return m_debit_card; }

    friend std::ostream &operator<<(std::ostream &os, const Account &rhs);

    virtual float CalculateAnnualCharges() = 0;

};

#endif // ACCOUNT_H
