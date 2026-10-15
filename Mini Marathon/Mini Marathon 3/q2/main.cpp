#include"functionalities.h"

int main(){
    DataContainer _data;

    try{
    CreateObject(_data);
    }
    catch(const InvalidInputError& obj){
        std::cerr<<obj.what()<<"\n";
    }


    try{
    std::future<DataContainer> r1 = std::async(&SatisfiedDataContainer , std::ref(_data)  , AutomobileWheelType::HYBRID , AutomobileCategory::PERSONAL );
    for(Sptr ptr : r1.get()){
        std::cout<<*ptr<<"\n";
    }
    }
    catch(const EmptyContainerError& obj){
        std::cerr<<obj.what()<<"\n";
    }
    catch(const UnmatchCondition& obj){
        std::cerr<<obj.what()<<"\n";
    }


    try{
    std::future<int> r2 = std::async(&CountOfAutoMobileSatisfiedYear , std::ref(_data)  , 2000 , 2021 );
        std::cout<<"The count of Satisfed Auto mobiles : "<<r2.get()<<"\n";
    }
    catch(const EmptyContainerError& obj){
        std::cerr<<obj.what()<<"\n";
    }
    catch(const UnmatchCondition& obj){
        std::cerr<<obj.what()<<"\n";
    }

    catch(const InvalidInputError& obj){
        std::cerr<<obj.what()<<"\n";
    }
    
    
    try{
    std::future<bool> r3 = std::async(&CheckObjectsBasedOnConditions , std::ref(_data) );
        std::cout<<"Is All Automobiles Satisfed the conditions  : "<<std::boolalpha <<r3.get()<<"\n";
    }
    catch(const EmptyContainerError& obj){
        std::cerr<<obj.what()<<"\n";
    }


    try{
    std::future<std::string> r4 = std::async(&IdWithMaximumSeatCount , std::ref(_data) );
        std::cout<<"Id with Max Seat Count : "<<r4.get()<<"\n";
    }
    catch(const EmptyContainerError& obj){
        std::cerr<<obj.what()<<"\n";
    }
}