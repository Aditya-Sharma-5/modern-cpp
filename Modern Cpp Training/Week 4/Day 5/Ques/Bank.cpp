#include "Bank.h"

void Bank::getInput()
{
    std::cout<<"\nEnter Your Name : ";
    std::cin>>name;

    std::cout<<"\nEnter your phone number : ";
    std::cin>>ph_number;

    int accType ; 
    std::cout<<"\nAccount Type :\nPRESS 1 for Saving\nPRESS 2 for Current\nPRESS 3 for PENSION Account\n";
    std::cin>>accType;
    if(accType == 1){
        accounttype = AccountType::SAVING;
    }
    else if(accType == 2){
        accounttype = AccountType::CURRENT;
    }
    else{
        accounttype= AccountType::PENSION;
    }

    int boolDebit ; 
    std::cout<<"If Want a Debit Card PRESS 1 Or Else PRESS 0\n";
    std::cin>>boolDebit;
    if(boolDebit){
        have_debit = true;
        ApplyDebitCard();
    }

    int boolCheque ; 
    std::cout<<"If Want a ChequeBook PRESS 1 Or Else PRESS 0\n";
    std::cin>>boolDebit;
    if(boolDebit){
        int page;
        std::cout<<"Enter the Number of Pages : ";
        std::cin>>page;
        have_cheque = true;
        ApplyChequeBook(page);
    }


}

void Bank::ApplyDebitCard()
{
    DebitCard* debitcard = new DebitCard();
}

void Bank::ApplyChequeBook(int leaves)
{
    ChequeBook* cheque = new ChequeBook(leaves);
}
