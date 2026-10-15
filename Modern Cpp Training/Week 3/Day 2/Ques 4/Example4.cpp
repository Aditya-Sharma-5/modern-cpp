#include<iostream>
#include<thread>
#include <mutex>

std::mutex mt;
/*
    lock_guard is used to overcome the mutex lock/unlock conditions in exception cases 
        and also help to overcome the deadlock condition 
*/
int amount = 1000 ; 

void withdraw(){
    for(int i = 0; i<100; i++){
        // mt.lock();
        std::lock_guard<std::mutex> lk(mt);
        amount -= 10;
        // mt.unlock();
    }
}

void deposit(){
    for(int i = 0; i<100; i++){
        // mt.lock();
        std::lock_guard<std::mutex> lk(mt);
        amount += 10;
        // mt.unlock();
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
