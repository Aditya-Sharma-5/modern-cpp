#ifndef DEBITCARD_H
#define DEBITCARD_H
#include<iostream>
class DebitCard
{
private:
    std::string _CVV;
    std::string _card_number;
    int _expiry_date;

public:
    DebitCard() = delete;
    ~DebitCard() = default;

    DebitCard(const DebitCard&) = delete;
    DebitCard( DebitCard&&) = delete;

    DebitCard& operator=(const DebitCard&) = delete;
    DebitCard& operator=(const DebitCard&&) = delete;

    DebitCard(std::string CVV , std::string card_number , int expiry_date );

    std::string cVV() const { return _CVV; }

    std::string cardNumber() const { return _card_number; }

    int expiryDate() const { return _expiry_date; }

    friend std::ostream &operator<<(std::ostream &os, const DebitCard &rhs);
};

#endif // DEBITCARD_H
