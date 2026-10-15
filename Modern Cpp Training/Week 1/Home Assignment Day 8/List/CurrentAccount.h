#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H

#include"Account.h"
#include <ostream>

class CurrentAccount : public Account
{
private:
    bool m_is_bussiness_load_applied{false};
public:
    CurrentAccount() = default ; 
    ~CurrentAccount()  = default;

    //  Copy and Move Constructor
    CurrentAccount(const CurrentAccount&) = default;
    CurrentAccount(CurrentAccount&&) = default;


    // Copy And Move Assignment Operator
    CurrentAccount& operator=(const CurrentAccount&) = default;
    CurrentAccount& operator=(CurrentAccount&&) = default;

    CurrentAccount(std::string account_number , std::string account_holder_name , float account_balance , DebitCard* debit_card, bool is_bussiness_loan_applied);

    bool isBussinessLoadApplied() const { return m_is_bussiness_load_applied; }

    friend std::ostream &operator<<(std::ostream &os, const CurrentAccount &rhs);
    
    float CalculateAnnualCharges() override;
};
#endif // CURRENTACCOUNT_H
