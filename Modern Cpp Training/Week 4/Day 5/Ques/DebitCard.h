#ifndef DEBITCARD_H
#define DEBITCARD_H

#include<iostream>

class DebitCard
{
private:
    static size_t card_number ;
    int exp_year {2025} ; 
    static int CVV ; 

public:
    DebitCard(){
        card_number++;
        CVV++;
    }
    ~DebitCard()  = default;

    DebitCard(const DebitCard&) = delete;
    DebitCard(DebitCard&&) = delete;

    DebitCard& operator=(const DebitCard&) = delete;
    DebitCard& operator=(DebitCard&&) = delete;

    int expYear() const { return exp_year; }
    void setExpYear(int expYear) { exp_year = expYear; }

    static int cVV() { return DebitCard::CVV; }
    static void setCVV(int cVV) { DebitCard::CVV = cVV; }

    void DisplayDetails();

    static size_t cardNumber() { return DebitCard::card_number; }
    static void setCardNumber(const size_t &cardNumber) { DebitCard::card_number = cardNumber; }

};

#endif // DEBITCARD_H
