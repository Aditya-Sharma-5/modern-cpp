#include<iostream>
#include<thread>
#include<future>    //for async programming


void funcA(int * ptr){
    /*
        s
    */

    std::this_thread::sleep_for(std::chrono::seconds(4));
    ptr  = new int;
}

void funcB(int &n1){
    std::cin>>n1;
}

int main(){
    int n1{0};
    int* ptr {nullptr};
    funcA(ptr);
    funcB(n1);

    //final activity is : to store the square of n1 in memory allocated to ptr 

    *ptr = n1*n1;
}


/*

    FuncA



*/