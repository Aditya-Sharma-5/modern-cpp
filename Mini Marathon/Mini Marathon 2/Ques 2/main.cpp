#include"Functionalities.h"

int main(){
    DataContainer _data;

    CreateObject(_data);
    // show(_data);

  

    FnContainer _fns;
    _fns[0] = std::ref(FN_A);
    _fns[1] = std::ref(FN_B);
    _fns[2] = std::ref(FN_C);
    _fns[3] = std::ref(FN_D);


    // Operation(std::ref(_data) , _fns);

    // DisplayDiscount(_data , [](Product obj){return 0.1*obj.productPrice();});
    
    return 0 ;
}