#include<iostream>
#include<list>

template <typename T>
void DisplayValues(const std::list<T>& data){
    for(const T val : data){
        std::cout<<val<<" ";
    }
} 

/*
    Template Parameter deduction
    A) Template function 
        starting from c++ 14 : it is not mandatory
    B) Template Class
        starting from c++ 20 
*/

int main(){
    // DisplayValues(std::list<int>{1 , 2, 34, 5534 ,343});   This will also work , not mandatory from c++14
    DisplayValues<int>(std::list<int>{1 , 2, 34, 5534 ,343});
    DisplayValues(std::list<std::string>{"Aadi" , "Prashant"});
    return 0 ;
}