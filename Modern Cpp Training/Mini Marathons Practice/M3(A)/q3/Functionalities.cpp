#include "Functionalities.hpp"

fncreate CreateObject = [](Container &obj){
    
    // obj.push_back(std::make_shared<EvCar>(1,ChasisType::LADDER,BatteryType::LI_ION,1200));
    // obj.push_back(std::make_shared<EvCar>(12,ChasisType::TUBULAR,BatteryType::LI_ION,1200));
    // obj.push_back(std::make_shared<EvCar>(123,ChasisType::LADDER,BatteryType::NI_CAD,1200));
    // obj.push_back(std::make_shared<EvCar>(1234,ChasisType::TUBULAR,BatteryType::NI_CAD,1200));

    // obj.push_back(std::make_shared<ICECar>(2345,ChasisType::TUBULAR,FuelType::DIESEL,123));
    // obj.push_back(std::make_shared<ICECar>(234,ChasisType::LADDER,FuelType::DIESEL,123));
    // obj.push_back(std::make_shared<ICECar>(23,ChasisType::TUBULAR,FuelType::PETROL,123));
    // obj.push_back(std::make_shared<ICECar>(2,ChasisType::LADDER,FuelType::DIESEL,123));

    EvPtr a1 = std::make_shared<EvCar>(1,ChasisType::LADDER,BatteryType::LI_ION,1200);
    EvPtr a2 = std::make_shared<EvCar>(1,ChasisType::LADDER,BatteryType::LI_ION,1200);
    EvPtr a3 = std::make_shared<EvCar>(1,ChasisType::LADDER,BatteryType::LI_ION,1200);

    IcePtr b1 = std::make_shared<ICECar>(2345,ChasisType::TUBULAR,FuelType::DIESEL,123);
    IcePtr b2 = std::make_shared<ICECar>(2345,ChasisType::TUBULAR,FuelType::DIESEL,123);
    IcePtr b3 = std::make_shared<ICECar>(2345,ChasisType::TUBULAR,FuelType::DIESEL,123);

    obj.push_back(a1);
    
    
    obj.push_back(b1);
    obj.push_back(a2);
    obj.push_back(b2);
    obj.push_back(a3);
    obj.push_back(b3);
};

fntype Ninstance = [](const Container& obj, std::string type, int n)->Container{
    if(obj.empty()){
        throw EmptyContainer(std::future_errc::no_state, "The Given Container is Empty");
    }

    if(n <= 0){
        throw Underflow(std::future_errc::no_state, "The Given Number is less than or equal to 0");
    }

    if(n > obj.size()){
        throw Underflow(std::future_errc::no_state, "The Given Number is greter than the container size");
    }

    Container res;
    if(type == "ICECAR"){
        int count = 0;
        for(auto &it : obj){
            if(std::holds_alternative<IcePtr>(it)){
                res.push_back(it);
                count++;
            if(count == n){
                break;
            }
            }
            
        }
        if(count != n){
            throw NotEnough(std::future_errc::broken_promise, "the given number is too high for the specific type");
        }
    }
    else{
        int count = 0;
        for(auto &it : obj){
            if(std::holds_alternative<EvPtr>(it)){
                res.push_back(it);
            }
            count++;
            if(count == n){
                break;
            }
        }
        if(count != n){
            throw NotEnough(std::future_errc::broken_promise, "the given number is too high for the specific type");
        }
    }

    return res;
};

fnice IsOne = [](const Container& obj)->bool{
    
    if(obj.empty()){
        throw EmptyContainer(std::future_errc::no_state, "The Given Container is Empty");
    }

    for(auto &it : obj){
        if(std::holds_alternative<IcePtr>(it)){
            
            IcePtr ptr = std::get<0>(it);
            std::cout << *ptr << std::endl;
            if(ptr->cap() > 30){
                return true;
            }
            // if(it.index<it>(1)- > 30){
            //     return true;
            // }
        }
    }
    return false;
};