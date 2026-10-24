#include<iostream>
#include<array>
#include"Functionality.h"

/*
    Objectives : Create a function "adapter" which accepts
            i) an array of 5 integers
            ii) A function of the following signature 
                -->Accepts one integer by value
                --> Return one integer by value

            Execute the input function on each valueand print the output on the cout buffer 
*/

int square(int number){
    return number*number;
}

int cube(int num){
    return num*num*num;
}

int Times10(int number){
    return number*10;
}

int factorial(int num){
    if(num<0){
        throw std::runtime_error("Cannot calculate factorial for a negative number");
    }
    int result = 1; 
    for(int cnt = 2 ; cnt <= num ;cnt++){
        result+= cnt ; 
    }
    return result;
}

int main(){

    // Function pointer
    int (*fn)(int) = &square;      //int square(int num)
    // fn(10)  == square(10) both are same

    std::array<int , 5> data{1 , 2,3 ,4 , 5};

    Adapter(data , square);  // Adapter receives one array and a "logic"

    std::cout<<"\n";
    Adapter(data , cube);

    std::cout<<"\n";
    Adapter(std::array<int , 5>{8 , 11, 23, 97 , 9} , factorial );

    std::cout<<"\n";
    Adapter(data , Times10);

}