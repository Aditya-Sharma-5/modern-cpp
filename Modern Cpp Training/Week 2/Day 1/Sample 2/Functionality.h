#ifndef FUNCTIONALITY_H
#define FUNCTIONALITY_H

#include<functional>
#include<array>
#include<iostream>

void Adapter(const std::array<int , 5>& data , std::function<int(int)>fn){
    for(const int val:data){
        std::cout<<fn(val)<<"\n";
    }
}

#endif // FUNCTIONALITY_H
/*
    std::function<void(int)>fn ==> fn is a wrapper that can accept any function with the following sognatures 
                                        - input parameter int by value 
                                        - return type void

    std::function<char(int , int)>fn ==> fn is a wrapper that can accept any function having signature 
                                         - input parameters = int by value , int by value 
                                         - return type char
*/