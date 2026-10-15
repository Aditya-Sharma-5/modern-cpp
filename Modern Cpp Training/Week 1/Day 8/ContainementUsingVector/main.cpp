#include"functionalities.h"

int main(){
    Container _data;
    createObject(_data);
    // showObject(_data);


    try{
    std::cout<<countObjectByVehicleType(_data , VehicleType::PRIVATE)<<"\n";
    }catch(const EmptyContainer& ex){
        std::cerr<<ex.what()<<"\n";
    }


    try{
    std::cout<<IsSamePermitYear(_data)<<"\n";
    }catch(const EmptyContainer& ex){
        std::cerr<<ex.what()<<"\n";
    }

    try{
    Container result = LastNInstances(_data , 2);
    showObject(result);
    }catch(const EmptyContainer& ex){
        std::cerr<<ex.what()<<"\n";
    }

        
    try{
    deleteObject(_data);
    }catch(const EmptyContainer& ex){
        std::cerr<<ex.what()<<"\n";
    }
    return 0 ;
}