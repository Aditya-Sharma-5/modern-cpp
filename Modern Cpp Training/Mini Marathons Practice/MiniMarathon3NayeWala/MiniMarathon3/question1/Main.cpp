#include<iostream>
#include "DataOperations.h"
#include<thread>
#include "EmptyContainerException.h"
#include "NumberException.h"
#include "FactorialNotAvailableException.h"

using TContainer =std::vector<std::thread>;

int main(){

    std::vector<int> vec{10,2,4,6,3,7,5};
    std::shared_ptr<DataOperations> ptr=DataOperations::createInstance(vec);

    TContainer threads;
    try{
        threads.push_back(std::thread(&DataOperations::FindMax,ptr));
        threads.push_back(std::thread(&DataOperations::SumOfFirstN,ptr,3));
        threads.push_back(std::thread(&DataOperations::FindNthValue,ptr,4));
        threads.push_back(std::thread(&DataOperations::FindOddNumbers,ptr));
        threads.push_back(std::thread(&DataOperations::FindFactorial,ptr));
        threads.push_back(std::thread(&DataOperations::TakeInput,ptr));
        threads.push_back(std::thread(&DataOperations::CheckPrime,ptr));
        

    }
    catch(EmptyContainerException &ex){
        std::cout<<ex.what()<<std::endl;
    }

    catch(NumberException &ex){
        std::cout<<ex.what()<<std::endl;
    }catch(FactorialNotAvailableException &ex){
        std::cout<<ex.what()<<std::endl;
    }

    
    for(std::thread &t:threads){
        if(t.joinable()){
            t.join();
        }
    }


    



    return 0;

}