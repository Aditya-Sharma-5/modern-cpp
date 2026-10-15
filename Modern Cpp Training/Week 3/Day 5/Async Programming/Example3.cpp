#include<iostream>
#include<memory>
#include<array>

#include<future>

using vptr= std::shared_ptr<int>;

/* 
    objective : Use asynchronous mechanism to perform execution of functionalities 

    Main: Drive the whole program . Make Arrangements , connect things , wait for things , execute programs.

    Memory Allocator : Allocate space for 5 integers on heap . This heap is used for storing the square 
                        of 5 integers taken as input in the function below 

    AcceptArrayInput: Will receive an array by reference and it will accept 5 integers into the array 
                    [Fill up the array with 5 integers]

*/

// void MemoryAllocator( vptr & ptr){
//     ptr.reset(new int[5]);    
// }

std::shared_ptr<int[]> MemoryAllocator(){
    return  std::shared_ptr<int[]>(new int[5]);
}

void AcceptArrayInput(std::array<int,5>& data){
    for(int i = 0 ; i<5;i++){
        std::cin>>data[i];
    }
}


void Square(std::array<int,5>&data, std::shared_ptr<int[]>& ptr){
    for(int i = 0 ; i<5 ; i++){
        ptr.get()[i] = data[i]*data[i];
    }
}


int main(){

    std::array<int , 5> data;

    // vptr ptr{nullptr};

    std::thread t1(&AcceptArrayInput , std::ref(data));
    // std::thread t2(&MemoryAllocator , std::ref(ptr));
    std::future<std::shared_ptr<int[]>> result = std::async(&MemoryAllocator );

    std::shared_ptr<int[]> ptr = result.get();

    t1.join();
    // t2.join();

    // std::thread t3(&Square , std::ref(data) , std::ref(ptr));
    // t3.join();
    Square(data , ptr  );
    

    for(int i = 0; i<5;i++){
        std::cout<<ptr.get()[i]<<" ";
    }

    

}