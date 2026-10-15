/*
    No need of bind here , regular function can be stored directky in a conatiner
*/
#include<iostream>
#include<functional>

using FnType = std::function<int(int)>;

void Adaptor(FnType* arr , int size){
    for(int i = 0;i<3;i++){
        std::cout<<arr[i](4)<<"\n";
    }
}

int main(){
    auto f1 = [](int num){return num*num;};
    auto f2 = [](int num){return num*num*num;};
    auto f3 = [](int num){return num*10;};
    FnType arr[3]{f1 , f2 , f3};
    Adaptor(arr , 3);
}