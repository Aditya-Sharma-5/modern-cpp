#include "DebitCard.h"

size_t DebitCard::card_number{1234567812345678};
int DebitCard::CVV{123};

void DebitCard::DisplayDetails()
{
    std::cout<<"Card Number : " <<card_number<<"\nVALID : "<<exp_year<<"\nCVV : "<<CVV<<"\n";
}