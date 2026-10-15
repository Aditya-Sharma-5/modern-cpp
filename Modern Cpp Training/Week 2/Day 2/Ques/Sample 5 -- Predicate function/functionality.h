/*
    Objective : Accepts a list of integer values and a PREDICATE lambda in the adaptor 

    Display integers from inout that satisfy the predicate 
*/

#include<list>
#include<functional>
#include<iostream>

void Adaptor(const std::list<int>& data , std::function<bool(const int)>fn){
    for(const int val : data){
        if(fn(val)){
            std::cout<<val;
        }
    }
}