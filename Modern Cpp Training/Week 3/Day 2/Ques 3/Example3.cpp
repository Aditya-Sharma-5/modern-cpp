#include<iostream>
#include<thread>
#include <mutex>

std::mutex mt;

int amount = 1000 ; 

void withdraw(){
    for(int i = 0; i<100; i++){
        mt.lock();
        amount -= 10;
        mt.unlock();
    }
}

void deposit(){
    for(int i = 0; i<100; i++){
        mt.lock();
        amount += 10;
        mt.unlock();
    }
}

void CreateThread(std::thread* arr , unsigned int size ){

    arr[0] = std::thread(&deposit);
    arr[1] = std::thread(&withdraw);
}

void JoinThread(std::thread* arr , unsigned int size ){
    for(unsigned int i = 0; i<size ; i++){
        if(arr[i].joinable()){
            arr[i].join();
        }
    }
}

void Display(){
    std::cout<<"Final Amount : "<<amount<<"\n";
}

void RunFunctions(){
    std::thread arr[2];
    CreateThread(arr , 2);
    JoinThread(arr , 2);
    Display();

}

int main(){
    RunFunctions();
    return 0 ;
}


/* 
amount[1000] [static code segment]

        Withdraw 
         RAM------>l3----> l2----> l1 cache----> registers----->ALU[1000 -10]
        [1000]                                                          |
                        <------------------------------------------------

        Deposit
        [1000]------> l3---->l2---->l1------>registers--------->ALU[1000+10 = 1010]
                                                                        |
        [1010]<----------------------------------------------------------
*/