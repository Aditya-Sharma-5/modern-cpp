#include "functionalities.h"

void createObject(Container &data)
{
    data.push_back(new Vehicle("101" , "Dzire" , VehicleType::PRIVATE , new Permit("12sjbhgd" , 2021 , "Pune")));
    data.push_back(new Vehicle("102" , "Mustang" , VehicleType::SPECIAL_PURPOSE , new Permit("12sjfdfbhgd" , 2023 , "Mohali")));
    data.push_back(new Vehicle("103" , "SUV" , VehicleType::COMMERCIAL , new Permit("1234sjbhgd" , 2022 , "Delhi")));
    data.push_back(new Vehicle("104" , "Verna" , VehicleType::PRIVATE , new Permit("1sded" , 2021 , "Shamli")));
}

void showObject(const Container &data)
{
    if(data.empty()){
        throw EmptyContainer("Data is Empty");
    }
    for(Vehicle* p:data){
        std::cout<<*p<<"\n";
    }
}

int countObjectByVehicleType(const Container &data, VehicleType type)
{
    if(data.empty()){
        throw EmptyContainer("Data is Empty");
    }
    int cnt = 0;
    for(Vehicle* p : data){
        if(p->vehicleType() == type){
            cnt++;
        }
    }
    return cnt;
}

bool IsSamePermitYear(const Container &data)
{    
    if(data.empty()){
        throw EmptyContainer("Data is Empty");
    }
    int check = data[0]->permit()->permitIssueYear();
    for(Vehicle* ptr : data){
        if(ptr->permit()->permitIssueYear() != check){
            return false;
        }
    }
    return true;
}

Container LastNInstances(const Container &data, int N)
{
    if(data.empty()){
        throw EmptyContainer("Data is Empty");
    }
    if(N > data.size() && N == 0){
        throw EmptyContainer("N is Invalid");
    }
    Container result ; 
    int begin = data.size() - N;
    for(int i = begin ; i<data.size() ; i++ ){
        result.push_back(data[i]);
    }
    return result;
}

void deleteObject(Container &data)
{    
    if(data.empty()){
        throw EmptyContainer("Data is Empty");
    }
    for(Vehicle* ptr : data){
        delete ptr->permit();
        delete ptr;
    }
}
