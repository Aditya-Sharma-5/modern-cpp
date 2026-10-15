#ifndef FUNCTIONALITY_H
#define FUNCTIONALITY_H

#include<array>
#include<iostream>

void Adapter(const std::array<int , 5>& data , int(*fn)(int)){
    for(const int val:data){
        std::cout<<fn(val)<<"\n";
    }
}

#endif // FUNCTIONALITY_H
