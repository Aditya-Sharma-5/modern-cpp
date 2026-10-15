#include"functionalities.h"


/*
    1 try block have only 1 type of functions 
*/


int main(){
    DataContainer car_data;

    // Creating Objects
    createObject(car_data);


    // Fetching N Intances 
    try{        
        unsigned int N = 7;
        CarUnit* result = FetchNInstances(car_data , N);
        for(int i = 0; i<N;i++){
            std::cout<<result[i] <<"\n";
        }
        delete [] result;

    }catch(const InvalidError& ex){
        std::cerr<<ex.what()<<"\n";
    }


    //  Finding CarType by Providing Id
    try{
        FindCarTypeById(car_data , "102");
    }
    catch(const IdNotFoundError& ex){
        std::cerr<<ex.what()<<"\n";
    }


    // Average Prices 
    float result = AveragePrice(car_data);
    std::cout<<"Average Price : "<<result<<"\n";


    //Model Name 
    std::string model_name = MaxCarModelName(car_data);
    std::cout<<"Model Name having highest price : "<<model_name<<"\n";

    return 0 ; 



}