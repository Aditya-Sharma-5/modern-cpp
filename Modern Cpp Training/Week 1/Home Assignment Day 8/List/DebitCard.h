#ifndef DEBITCARD_H
#define DEBITCARD_H

#include<iostream>
class DebitCard
{
private:
    int m_CVV{234};
    int m_expiry_date{2020};
public:
    DebitCard() = default ; 
    ~DebitCard()  = default;

    //  Copy and Move Constructor
    DebitCard(const DebitCard&) = default;
    DebitCard(DebitCard&&) = default;


    // Copy And Move Assignment Operator
    DebitCard& operator=(const DebitCard&) = default;
    DebitCard& operator=(DebitCard&&) = default;


    // Parametrized Constructor
    DebitCard(int CVV , int expiry_date);

    int cVV() const { return m_CVV; }

    int expiryDate() const { return m_expiry_date; }

    friend std::ostream &operator<<(std::ostream &os, const DebitCard &rhs);
    


};

#endif // DEBITCARD_H

