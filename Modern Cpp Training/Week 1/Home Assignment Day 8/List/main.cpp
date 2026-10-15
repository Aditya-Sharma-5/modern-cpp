#include"functionalities.h"

int main(){
    DataContainer info ; 

    createObject(info);

    try{
        showObject(info);
    }catch(const EmptyContainer& obj){
        std::cerr<<obj.what();
    }

    try{
        bool check = IsAllSavingAccountHaveDebitCard(info);
        std::cout<<"Is DebitCard Attached to All Saving Account: "<<std::boolalpha<<check<<"\n";
    }catch(const EmptyContainer& obj){
        std::cerr<<obj.what();
    }catch(const NoSavingAccountInstanceError& obj){
        std::cerr<<obj.what();
    }

    try{
        std::cout<<"Account Having Maximum Balance : "<<AccountHavingMaximumBalance(info)<<"\n";
    }catch(const EmptyContainer& obj){
        std::cerr<<obj.what();
    }

    try{
        std::cout<<*FindDebitCard(info , "7236653");
    }catch(const EmptyContainer& obj){
        std::cerr<<obj.what();
    }catch(const InvalidAccountNumber& obj){
        std::cerr<<obj.what();
    }catch(const NoSavingAccountInstanceError& obj){
        std::cerr<<obj.what();
    }catch(const DebitCardInvalidError& obj){
        std::cerr<<obj.what();
    }

    try{
        deleteObject(info);
    }catch(const EmptyContainer& obj){
        std::cerr<<obj.what();
    }

    return 0 ;
}




 
/*
while working in the inheritance upcasting , marks the destructor virtual 
*/