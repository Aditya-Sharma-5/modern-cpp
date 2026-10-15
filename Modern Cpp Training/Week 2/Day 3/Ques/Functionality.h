#include<iostream>
#include<functional>
#include<array>


//transform_if
void Adaptor(const std::array<int , 5>& arr , std::function<bool(int)>fn)
{
    for(const int i:arr){
        if(fn(i)){
            std::cout<<i<<" ";
        }
    }
    std::cout<<"\n";
}


//std::transform
void Adaptor1(const std::array<int , 5>& arr , std::function<const int(const int)>fn){

    for(const int val:arr){
        std::cout<<val<<"\n";
    }
    std::cout<<"\n";
}
