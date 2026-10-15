#include "functionality.h"

void createObject(Container &data)
{
    data.push_back(new SavingAccount("32861440503" , 8600.0 , "Aditya" , new DebitCard("123" , "28738638648" , 2020) , 5000));
    data.push_back(new SavingAccount("hdsbhhbh03" , 3200.0 , "Aryan"  , 2300));
    data.push_back(new CurrentAccount("7364872937" , 30000.0 , "vipin" , new DebitCard("983" , "98398379" , 2026) , 1));
    data.push_back(new CurrentAccount("7877erd4464" , 24000.0 , "chahat" ,  0));
}

void showObject(const Container &data)
{
    for(Account* ptr : data){
        std::cout<<*ptr<<"\n";
    }
}

bool AllSavingAccountHaveDebitCard(const Container &data)
{

    for(Account* ptr:data){
        SavingAccount* s1 = dynamic_cast<SavingAccount*>(ptr);
        if(s1 && s1->debitCard() == nullptr){
            std::cout << "hii\n";
            return false;
        }
    }
    return true;
}
