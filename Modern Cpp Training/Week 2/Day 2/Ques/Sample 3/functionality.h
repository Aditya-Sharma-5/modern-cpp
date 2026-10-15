
/*

Objective : Create an adapter that 
        Accepts a function of the following signature
             - accepts one integer by value 
             - returns void
            
        Accepts a c-style array 

        Map the function on the data in the c-style array 
*/

#include<iostream>
#include<functional>

void Adaptor(std::function<void(int)>fn , int* data , unsigned int size){
    for(unsigned int i = 0; i<size; i++){
        fn(data[i]);
    }
}