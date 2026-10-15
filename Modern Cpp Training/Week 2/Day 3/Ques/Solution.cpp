#include"Functionality.h"


int main(){
    std::array<int , 5>arr{10 , 20 , 30 , 40 , 50};

    Adaptor(arr , [](const int num){return (num%4 == 0);});

    Adaptor(arr , [](const int num){return (num >10);});

    Adaptor1(arr , [&](int num){ return  num*num;});
}