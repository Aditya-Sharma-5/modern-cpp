#include"Operation.h"

int main(){
    IntegerContainer int_data{1 , 2, 3 , 1, 4 , 5};
    StringContainer str_data{"Aditya" , "Python" , "KPIT" , "Prashant"};

    std::shared_ptr<Operation> obj = Operation::getInstance(int_data , str_data);
    obj->MapThreads();
    obj->JoinThreads();

}