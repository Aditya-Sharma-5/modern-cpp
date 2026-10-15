#include "Functionaities.h"

void CreateObject(DataContainer &data)
{
    data.emplace("1A" , std::make_shared<Cab>("1A" , CabType::LUXURY , CabStatus::COMPANY_OWNED , 5 , CabFuelType::ALTERNATIVE_FUEL , true));
    data.emplace("2A" , std::make_shared<Cab>("2A" , CabType::MINI , CabStatus::GOVT_OWNED , 5 , CabFuelType::ALTERNATIVE_FUEL , true));
    data.emplace("3A" , std::make_shared<Cab>("3A" , CabType::PRIME , CabStatus::PRIVATELY_OWNED , 5 , CabFuelType::IC_ENGINE , true));
    data.emplace("4A" , std::make_shared<Cab>("4A" , CabType::LUXURY , CabStatus::COMPANY_OWNED , 7 , CabFuelType::ALTERNATIVE_FUEL , true));
}

std::vector<CabFuelType> ContainerOfFUELType(const DataContainer &data, unsigned int N)
{
    //Exception for Empty Data Container
    if(data.empty()){
        throw EmptyContainerError("Empty Data Container!!!\n");
    }

    if(N>data.size() && N<=0){
        throw InvalidInput("Invalid N!!\n");
    }

    std::vector<CabFuelType> result;

    auto itr = data.begin();
    std::advance(itr , N);

    std::transform(data.begin() , itr , 
    std::inserter(result , result.begin()) , 
    [&](std::pair<std::string , Cptr> ptr){return ptr.second.get()->cabFuelType();} 
    );

    return result;
}

int CountOfMatchCABSTATUS(const DataContainer &data, CabStatus status)
{
    //Exception for Empty Data Container
    if(data.empty()){
        throw EmptyContainerError("Empty Data Container!!!\n");
    }

    int countOfMatchCabStatus = std::count_if(
        data.begin() , 
        data.end(),
        [&](std::pair<std::string , Cptr> ptr){return ptr.second.get()->cabStatus()== status;}
    );
    
    if(countOfMatchCabStatus){
        return countOfMatchCabStatus;
    }
    throw UnmatchConditionError("No condition Match!!\n");

}

bool Atleast1CabHaveSeatAbove5(const DataContainer &data)
{
    //Exception for Empty Data Container
    if(data.empty()){
        throw EmptyContainerError("Empty Data Container!!!\n");
    }

    bool check = std::any_of(data.begin() , data.end() , 
    [&](std::pair<std::string , Cptr> ptr){return ptr.second.get()->cabSeatCount()>5;}
    );

    return check;
}

std::vector<CabType> ContainerOfCABTYPE(const DataContainer &data, unsigned int N)
{
    //Exception for Empty Data Container
    if(data.empty()){
        throw EmptyContainerError("Empty Data Container!!!\n");
    }

    if(N>data.size() && N<=0){
        throw InvalidInput("Invalid N!!\n");
    }

    std::vector<CabType> result;
    int jump = data.size() - N;
    auto itr = data.begin();
    std::advance(itr , jump);

    std::transform(itr , data.end() , 
    std::inserter(result , result.begin()) , 
    [&](std::pair<std::string , Cptr> ptr){return ptr.second.get()->cabType();} 
    );

    return result;
}

int AverageSeatCount(const DataContainer &data)
{
    //Exception for Empty Data Container
    if(data.empty()){
        throw EmptyContainerError("Empty Data Container!!!\n");
    }

    int countSeat = std::count_if(
        data.begin(),
        data.end(),
        [&](std::pair<std::string , Cptr> ptr){return ptr.second.get()->cabSeatCount();}
    );

    if(countSeat){
        return countSeat;
    }

    throw UnmatchConditionError("No Seat Found !!!\n");
}

std::pair<bool, CabFuelType> PairForGivenId(const DataContainer &data, std::string id)
{
    //Exception for Empty Data Container
    if(data.empty()){
        throw EmptyContainerError("Empty Data Container!!!\n");
    }


    auto itr = std::find_if(
        data.begin(),
        data.end(),
        [&](std::pair<std::string , Cptr> ptr){return ptr.second.get()->cabRegNumber()== id;}
    );

    if(itr == data.end()){
        throw InvalidInput("Id Not Found!!\n");
    }

    std::pair<bool , CabFuelType> result{itr->second.get()->isCabInsured() , itr->second.get()->cabFuelType()};
    return result;

}
