#include"functionalities.h"

int main(){
    std::shared_ptr<functionalities> obj = functionalities::getInstance();
    obj->CreateObject();

    std::string id {"UP19T9811"};
    std::cout<<static_cast<int>( obj->FindCarTypeById(id))<<"\n";
    std::cout<<obj->CountOfMatchedCarType(CarType::SPORTS)<<"\n";
    obj->DisplayLastNInstance(2);
    return 0 ;
}