#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<iostream>
#include"DebitCard.h"

class Account
{
private:
    std::string m_account_number{""};
    std::string m_account_holder_name{""};
    float m_account_balance{0.0f};
    DebitCard* m_debit_card{nullptr};
public:
    Account() = default ; 
    virtual ~Account()  = default;

    //  Copy and Move Constructor
    Account(const Account&) = default;
    Account(Account&&) = default;


    // Copy And Move Assignment Operator
    Account& operator=(const Account&) = default;
    Account& operator=(Account&&) = default;

    explicit Account(std::string account_number , std::string account_holder_name , float account_balance , DebitCard* debit_card);

    std::string accountNumber() const { return m_account_number; }

    std::string accountHolderName() const { return m_account_holder_name; }

    float accountBalance() const { return m_account_balance; }

    DebitCard* debitCard() const { return m_debit_card; }

    friend std::ostream &operator<<(std::ostream &os, const Account &rhs);

    virtual float CalculateAnnualCharges() = 0;
};

#endif // ACCOUNT_H
