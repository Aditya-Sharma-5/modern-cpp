#include "functionalities.h"


void createObject(DataContainer &data)
{
    // Saving Account Instances
    // data.push_back(new SavingAccount("7236653" , "Chiku" , 1238.0f , new DebitCard(123 , 2021) , 1100.0f));
    // data.push_back(new SavingAccount("2234445" , "Vaishnavi" , 12323.0f ,nullptr , 1100.0f));

    // Current Account Instances
    data.push_back(new CurrentAccount("21767534" , "Aadi" , 100 , new DebitCard(234 , 2024) , true));
    data.push_back(new CurrentAccount("13413244" , "Aryan" , 2300 , nullptr, false));

}


void showObject(const DataContainer &data)
{
    if(data.empty()){
        throw EmptyContainer("Data is Empty\n");
    }

    for(Account* ptr : data){
        std::cout<<*ptr<<"\n";
    }

}

bool IsAllSavingAccountHaveDebitCard(const DataContainer &data)
{
    if(data.empty()){
        throw EmptyContainer("Data is Empty\n");
    }

    bool is_saving_account_found{false};

    for(Account* ptr:data)
    {
        const SavingAccount* s1 =  dynamic_cast<SavingAccount*>(ptr);

        if(s1 && s1->debitCard() == nullptr){
            return false;
        }

        if(s1 && !is_saving_account_found){
            is_saving_account_found = true;
        }

    }

    if(!is_saving_account_found){
        throw NoSavingAccountInstanceError("Not a Single Saving Account is found\n");
    }

    return true;

}


std::string AccountHavingMaximumBalance(const DataContainer &data)
{
    if(data.empty()){
        throw EmptyContainer("Data is Empty\n");
    }

    float maxi = data.front()->accountBalance();
    std::string acc = data.front()->accountNumber();

    for(Account* p : data){
        if(maxi< p->accountBalance()){
            maxi = p->accountBalance();
            acc = p->accountNumber();
        }
    }

    return acc;

}


DebitCard* FindDebitCard(const DataContainer &data, std::string acc_num)
{
    if(data.empty()){
        throw EmptyContainer("Data is Empty\n");
    }

    for(Account* p : data){

        if( p && p->debitCard() &&  p->accountNumber() == acc_num){
            return p->debitCard();
        }

        if(p && p->accountNumber() == acc_num && !p->debitCard()){
            throw DebitCardInvalidError("Debit Card not attached to given Account\n");
        }

    }

    throw InvalidAccountNumber("Account Number Not Exists\n");

}

void deleteObject(DataContainer &data)
{
    if(data.empty()){
        throw EmptyContainer("Data is Empty\n");
    }

    for(Account* p:data){
        if(p)
        {
            if(p->debitCard()){
                delete p->debitCard();
            }
            delete p;
        }
    }
}
