#include "Functionalities.hpp"

fncreate CreateObject = [](Container& obj){

    obj.push_back(Car("Volvo X", "123", Category::SPORTS, 1234323.0f, RimSize::INCH_18, 40));
    obj.push_back(Car("Volvo Y", "1234", Category::COMMUTE, 12343.0f, RimSize::INCH_16, 30));
    obj.push_back(Car("Volvo Z", "12345", Category::TOURIST, 123433.0f, RimSize::INCH_14, 39));
    obj.push_back(Car("Volvo A", "123456", Category::SPORTS, 234323.0f, RimSize::INCH_15, 40));

};

fnprice ByPrice = [](const Container& obj, float price)->Container {
    
    if(obj.size() == 0){
        throw EmptyContainer(std::future_errc::no_state, "The Given Container is Empty");
    }

    Container res;
    for(Car it : obj){
        if(it.price() > price){
            res.push_back(it);
        }
    }
    
    return res;
};

fnchasis ByChasis = [](const Container& obj, std::string num) -> Car {

    if(obj.size() == 0){
        throw EmptyContainer(std::future_errc::no_state, "The Given Container is Empty");
    }

    for(Car it : obj){
        if(it.chasisNumber() == num){
            return it;
        }
    }

    throw ChasisNotFound(std::future_errc::broken_promise, "The Given Number of Chasis Not Found");

};

fncat AntiGivenCategory = [](const Container& obj, Category ct)->std::optional<Container> {

    if(obj.size() == 0){
        throw EmptyContainer(std::future_errc::no_state, "The Given Container is Empty");
    }

    Container res; 

    for(Car it : obj){
        if(it.category() != ct){
            res.push_back(it);
        }
    }

    if(res.empty()){
        return std::nullopt;
    }

    return res;
    
};

fnsize rimsize = [](const Container& obj)->std::list<float>{

    if(obj.size() == 0){
        throw EmptyContainer(std::future_errc::no_state, "The Given Container is Empty");
    }

    std::list<float> ll;
    float avg14 = 0;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    float avg15 = 0;
    float avg16 = 0;
    float avg18 = 0;

    for(Car it : obj){
        if(it.rimSize() == RimSize::INCH_14){
            count1++;
            avg14 += it.price();
        }
        else if(it.rimSize() == RimSize::INCH_15){
            count2++;
            avg15 += it.price();
        }
        else if(it.rimSize() == RimSize::INCH_16){
            count3++;
            avg16 += it.price();
        }
        else{
            count4++;
            avg18 += it.price();
        }
    }

    avg14 = avg14/count1;
    avg15 = avg15/count2;
    avg16 = avg15/count3;
    avg18 = avg18/count4;

    ll.push_back(avg14);
    ll.push_back(avg15);
    ll.push_back(avg16);
    ll.push_back(avg18);

    return ll;

};

fnpres CheckPres = [](const Container& obj)->bool{

    if(obj.size() == 0){
        throw EmptyContainer(std::future_errc::no_state, "The Given Container is Empty");
    }

    for(Car it : obj){
        if(!(it.tyrePressure() >= 30 && it.tyrePressure() <= 40)){
            return false;
        }
        
    }

    return true;
};