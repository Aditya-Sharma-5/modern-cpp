#include<iostream>

/*
    Objective : 
*/

template<typename... T>
auto PlusOperation(T... args){
    return ( ... - args);     //Left Associativity    (((( 10 - 20 ) - 30) - 40) - 50)
    //return ( args - ...);   // Right  Associativity    (10 - (20  -( 30 - ( 40 - 50))))
}
int main(){
    std::cout<< PlusOperation<int>(10 , 20 , 30 , 40 , 50);
}