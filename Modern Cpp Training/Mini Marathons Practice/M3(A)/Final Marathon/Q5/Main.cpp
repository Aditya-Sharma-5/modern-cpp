#include"Functionalities.h"
#include<future>

int main(){
    Container data;
    CreateObjects(data);
    auto fn1 = [](const VehiclePtr& itr1,const VehiclePtr& itr2){
        return itr1->vehiclePrice()<itr2->vehiclePrice();
    };
    auto fn2 = [](int n){return n*n;};

    auto fun1 = std::async(&LastNInstancesTransmissionType,std::ref(data),3);
    auto fun2 = std::async(&PriorityQueueForGivenFunction,std::ref(data),fn1);
    auto fun3 = std::async(&VehiclePriceSet,std::ref(data));
    auto fun4 = std::async(&MapOfIdAndCategory,std::ref(data),2);
    auto fun5 = std::async(&BootSpaceOfGivenIds,std::ref(data),std::list<std::string>{"ID101", "ID103"});
    auto fun6 = std::async(&InsuredVehicles,std::ref(data));
    auto fun7 = std::async(&BootSpaceOperationContainer,std::ref(data),fn2);

    std::vector<TransmissionType> res1 = fun1.get();
    std::priority_queue<VehiclePtr, Container, std::function<bool (const VehiclePtr &, const VehiclePtr &)>>res2 = fun2.get();
    std::unordered_set<float> res3 = fun3.get();
    std::unordered_map<std::string, VehicleCategory> res4 = fun4.get();
    std::vector<int> res5 = fun5.get();
    Container res6 = fun6.get();
    std::vector<int> res7 = fun7.get();

    for(TransmissionType itr:res1){
        std::cout<<"Transmission Type : "<<static_cast<int>(itr)<<std::endl;
    }

    std::cout<<"Size of queue : "<<res2.size()<<std::endl;
    std::cout<<"Set of Price : ";
    for(float itr:res3){
        std::cout<<itr<<"  ";
    }

    std::cout<<"\nMap of Id & Category : \n";
    for(auto& [k,v]:res4){
        std::cout<<k<<"   Vehicle Category : "<<static_cast<int>(v)<<std::endl;
    }

    std::cout<<"\nBoot Space of Given IDs : ";
    for(int i:res5){
        std::cout<<i<<"   ";
    }

    std::cout<<"\nBoot Spaces after operation : ";
    for(int i:res7){
        std::cout<<i<<"   ";
    }

    std::cout<<"\nInsured Vehicle Instances : \n";
    for(VehiclePtr itr:res6){
        std::cout<<*itr<<std::endl;
    }
}