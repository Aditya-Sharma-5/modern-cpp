#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H
#include"Account.h"
#include <ostream>

class CurrentAccount:public Account
{
private:
    bool m_is_bussiness_loan_applied;
public:
    CurrentAccount() = default;
    ~CurrentAccount() = default;

    CurrentAccount(const CurrentAccount&) = delete;
    CurrentAccount( CurrentAccount&&) = delete;

    CurrentAccount& operator=(const CurrentAccount&) = delete;
    CurrentAccount& operator=(const CurrentAccount&&) = delete;

    CurrentAccount(std::string account_number, float account_balance, std::string account_holder_name , bool is_bussiness_loan_applied);

    CurrentAccount(std::string account_number , float account_balance , std::string account_holder_name , DebitCard* debit_card,bool is_bussiness_loan_applied);

    bool isBussinessLoadApplied() const { return m_is_bussiness_loan_applied; }

    friend std::ostream &operator<<(std::ostream &os, const CurrentAccount &rhs);


    float CalculateAnnualCharges() override;

};

#endif // CURRENTACCOUNT_H
