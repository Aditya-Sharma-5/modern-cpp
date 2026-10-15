#include"functionality.h"

int main(){
    Container _data;
    createObject(_data);
    showObject(_data);

    bool ans = AllSavingAccountHaveDebitCard(_data);
    if(ans){
        std::cout << "All have debit card !! \n";
    }
    else{
        std::cout << "All have not debit card !! \n";
    }
    return 0 ;
}