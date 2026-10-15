#include "functionalities.h"

std::mutex mt;

void CreateObject(DataContainer &data)
{
    data.push_back(std::make_shared<Automobile>("1A" , 4 , AutomobileCategory::PERSONAL , 2000 , 65000.0f , AutomobileWheelType::HYBRID , true));
    data.push_back(std::make_shared<Automobile>("2A" , 8 , AutomobileCategory::SPECIAL_PURPOSE , 2010 , 80000.0f , AutomobileWheelType::ULTRA_DURABLE , false));
    data.push_back(std::make_shared<Automobile>("3A" , 5 , AutomobileCategory::PERSONAL , 2007 , 510000.0f , AutomobileWheelType::REGULAR , true));
    data.push_back(std::make_shared<Automobile>("4A" , 4 , AutomobileCategory::COMMERCIAL , 2020 , 55000.0f , AutomobileWheelType::OFF_ROAD , false));
    data.push_back(std::make_shared<Automobile>("5A" , 5 , AutomobileCategory::PERSONAL , 2019 , 90000.0f , AutomobileWheelType::HYBRID , true));
}

DataContainer SatisfiedDataContainer(const DataContainer &data, AutomobileWheelType wheel_type, AutomobileCategory category)
{
    //  Exception for Empty Data
    if(data.empty())
    {
        std::lock_guard<std::mutex>lk(mt);
        throw EmptyContainerError("Empty Data!!!" , std::future_errc::no_state);
    }

    DataContainer result ; 

    for(Sptr ptr : data)
    {
        if(ptr.get()->automobileCategory() == category && ptr.get()->automobileWheelType() == wheel_type){
            result.push_back(ptr);
        }
    }

// Exception for Unmatch Condition
    if(result.empty())
    {
        std::lock_guard<std::mutex>lk(mt);
        throw UnmatchCondition("No Condition Satisied \n", std::future_errc::no_state);
    }

    std::lock_guard<std::mutex>lk(mt);
    return result;
}


int CountOfAutoMobileSatisfiedYear(const DataContainer &data, unsigned int begin, unsigned int end)
{
    //  Exception for Empty Data
    if(data.empty())
    {
        std::lock_guard<std::mutex>lk(mt);
        throw EmptyContainerError("Empty Data!!!" , std::future_errc::no_state);
    }

//Exception for Invalid COnditions
    if(begin < 1980 && end >2024)
    {
        std::lock_guard<std::mutex>lk(mt);
        throw InvalidInputError("Invalid Input !! \n", std::future_errc::no_state);
    }
    
    int count = 0;

    for(Sptr ptr : data)
    {
        if(ptr.get()->automobileManufacturingYear() <= end && ptr.get()->automobileManufacturingYear()>=begin){
            count++;
        }
    }

// Exception for Unmatch Condition of Manufacturing Year
    if(count == 0)
    {   
        std::lock_guard<std::mutex>lk(mt);
        throw UnmatchCondition("No condition Satisfied \n" , std::future_errc::no_state);
    }

    std::lock_guard<std::mutex>lk(mt);
    return count;
}


bool CheckObjectsBasedOnConditions(const DataContainer &data)
{
    //  Exception for Empty Data
    if(data.empty())
    {
        std::lock_guard<std::mutex>lk(mt); 
        throw EmptyContainerError("Empty Data!!!" , std::future_errc::no_state);
    }

    bool check = false;
    bool all = true ; 

    for(Sptr ptr : data)
    {
        if(ptr.get()->automobileSeatCount()>2 || ptr.get()->automobilePrice() >40000 || ptr.get()->isAutomobileNcapCertified() == true  ){
            check = true ;
        }
        else{
            all = false;
        }
    }

    if(all == false)
    {
        std::lock_guard<std::mutex>lk(mt);
        return false;
    }
    else
    {
        std::lock_guard<std::mutex>lk(mt);
        return true;
    }
}

std::string IdWithMaximumSeatCount(const DataContainer &data)
{
    //  Exception for Empty Data
    if(data.empty())
    {
        std::lock_guard<std::mutex>lk(mt);
        throw EmptyContainerError("Empty Data!!!" , std::future_errc::no_state);
    }

    unsigned int max_seat = data.front().get()->automobileSeatCount();
    std::string  id_of_max_seat = data.front().get()->automobileId();

    for(const Sptr& ptr : data)
    {
        if(ptr.get()->automobileSeatCount()> max_seat)
        {
            id_of_max_seat = ptr.get()->automobileId();
            max_seat = ptr.get()->automobileSeatCount();
        }
    }

    std::lock_guard<std::mutex>lk(mt);
    return id_of_max_seat;
}
