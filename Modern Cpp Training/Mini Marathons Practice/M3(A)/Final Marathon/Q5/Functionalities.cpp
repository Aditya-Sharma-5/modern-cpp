#include "Functionalities.h"

void CreateObjects(Container &data)
{
    data.emplace_back(std::make_shared<Vehicle>("ID101", 1000.0f,VehicleCategory::GOVT,TransmissionType::AMT,10,true));
    data.emplace_back(std::make_shared<Vehicle>("ID102", 2000.0f,VehicleCategory::PRIVATE,TransmissionType::AUTOMATIC,20,false));
    data.emplace_back(std::make_shared<Vehicle>("ID103", 3000.0f,VehicleCategory::PUBLIC,TransmissionType::MANUAL,30,true));
    data.emplace_back(std::make_shared<Vehicle>("ID104", 4000.0f,VehicleCategory::PRIVATE,TransmissionType::AMT,40,false));
    data.emplace_back(std::make_shared<Vehicle>("ID105", 5000.0f,VehicleCategory::GOVT,TransmissionType::MANUAL,50,true));
}

std::vector<TransmissionType> LastNInstancesTransmissionType(const Container &data, int N)
{
    if(data.empty()){
        throw ExceptionMessage("EMPTY DATA");
    }
    if(N<0 && N>data.size()){
        throw ExceptionMessage("Invalid N");
    }
    std::vector<TransmissionType> result;
    auto itr=data.rbegin();
    while(N>0){
        result.emplace_back(itr->get()->transmissionType());
        itr++;
        N--;
    }
    if(result.empty()){
        throw ExceptionMessage("EMPTY RESULT in Transmission Type");
    }
    return result;
}

std::priority_queue<VehiclePtr, Container, std::function<bool(const VehiclePtr &, const VehiclePtr &)>> PriorityQueueForGivenFunction(const Container &data, std::function<bool(const VehiclePtr &, const VehiclePtr &)> fn)
{
    if(data.empty()){
        throw ExceptionMessage("EMPTY DATA");
    }
    std::priority_queue<VehiclePtr, Container , std::function<bool(const VehiclePtr &, const VehiclePtr &)>>pq(fn);
    for(const VehiclePtr& itr:data){
        pq.emplace(itr);
    }
    if(pq.empty()){
        throw ExceptionMessage("EMPTY QUEUE");
    }
    return pq;
}

std::unordered_set<float> VehiclePriceSet(const Container &data)
{
    if(data.empty()){
        throw ExceptionMessage("EMPTY DATA");
    }
    std::unordered_set<float> result;

    for(const VehiclePtr& itr:data){
        result.emplace(itr->vehiclePrice());
    }

    std::for_each(data.begin(),data.end(),[&result](const VehiclePtr& ptr){
        result.emplace(ptr->vehiclePrice());
    });

    
    if(result.empty()){
        throw ExceptionMessage("EMPTY SET");
    }
    return result;
}

std::unordered_map<std::string, VehicleCategory> MapOfIdAndCategory(const Container &data, int N)
{
    if(data.empty()){
        throw ExceptionMessage("EMPTY DATA");
    }
    if(N<0 && N>data.size()){
        throw ExceptionMessage("Invalid N");
    }
    std::unordered_map<std::string, VehicleCategory> result;
    auto itr = data.begin();
    while(N>0){
        result.emplace(std::pair<std::string,VehicleCategory>(itr->get()->vehicleId(),itr->get()->vehicleCategory()));
        itr++;
        N--;
    }
    if(result.empty()){
        throw ExceptionMessage("EMPTY MAP");
    }
    return result;
}

std::vector<int> BootSpaceOfGivenIds(const Container &data, std::list<std::string> ids)
{
    if(data.empty()){
        throw ExceptionMessage("EMPTY DATA");
    }
    if(ids.empty()){
        throw ExceptionMessage("No id provided");
    }
    std::vector<int> result;
    for(const VehiclePtr& itr:data){
        for( std::string ide : ids){
            if(itr->vehicleId()==ide){
                result.push_back(itr->bootSpace());
            }
        }
    }
    if(result.empty()){
        throw ExceptionMessage("EMPTY Result of ids");
    }
    return result;
}

std::vector<int> BootSpaceOperationContainer(const Container &data, std::function<int(int)> fn)
{
    if(data.empty()){
        throw ExceptionMessage("EMPTY DATA");
    }
    std::vector<int> result;
    for(const VehiclePtr& itr:data){
        result.push_back(fn(itr->bootSpace()));
    }
    if(result.empty()){
        throw ExceptionMessage("EMPTY Result of Boot Space");
    }
    return result;
}

Container InsuredVehicles(const Container &data)
{
    if(data.empty()){
        throw ExceptionMessage("EMPTY DATA");
    }
    Container result;
    for(const VehiclePtr& itr:data){
        if(itr->isVehicleInsured()==true){
            result.emplace_back(itr);
        }
    }
    if(result.empty()){
        std::cerr<<"None vehicle is insured\n";
    }
    return result;
}
