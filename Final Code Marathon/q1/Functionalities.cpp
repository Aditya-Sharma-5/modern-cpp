#include "Functionalities.h"
std::mutex mt;
void CreateObject(Container &data)
{
    data.push_back(Vehicle("1A" , "Dzire" , VehicleType::TEST_VEHICLE , 35000 , 2024 , true , false));
    data.push_back(Vehicle("2A" , "THAR" , VehicleType::COMMERCIAL , 95000 , 2020 , true , true));
    data.push_back(Vehicle("3A" , "Verna" , VehicleType::PRIVATE_VEHICLE , 85000 , 2023 , true , false));
    data.push_back(Vehicle("4A" , "Bolero" , VehicleType::PUBLIC_TRANSPORT , 75000 , 2022 , true , true));
}

void DisplayAverageInsurancePremiumCost(const Container &data , unsigned int N)
{
    //Exception case if data container is Empty
    if(data.empty())
    {
        std::lock_guard<std::mutex>lk(mt);
        std::cerr<<"Empty Data Container !!\n";
        return;
    }

    // Exception for Value of N
    if(N>data.size() && N<=0){
        std::lock_guard<std::mutex>lk(mt);
        std::cerr<<"INvalid value Of N!!\n";
        return;
    }

    auto itr = data.begin();

    std::advance(itr , N);

    float averageCost = std::accumulate(
        data.begin() , 
        itr ,
        0.0f, 
        [&](float res , Vehicle v){return res += v.InsurancePremiumCost();}
    );

    std::lock_guard<std::mutex>lk(mt);
    std::cout<<"Average Insurance Price Of First N instances : "<<averageCost/N<<"\n";
}

void IsAllObjectsHaveNCAPCertified(const Container &data)
{
    //Exception case if data container is Empty
    if(data.empty())
    {
        std::lock_guard<std::mutex>lk(mt);
        std::cerr<<"Empty Data Container !!\n";
        return;
    }

    bool ncapCertifeid  = std::all_of(
        data.begin(),
        data.end(),
        [](const Vehicle& v){return v.isVehicleNcapCertified();}
    );

    std::lock_guard<std::mutex>lk(mt);
    std::cout<<"The All Vehicle Have NCAP Certified or NOT : "<<std::boolalpha<<ncapCertifeid<<"\n";
}

void FindVehicleTypeForGivenID(const Container &data, std::string id)
{
    //Exception case if data container is Empty
    if(data.empty())
    {
        std::lock_guard<std::mutex>lk(mt);
        std::cerr<<"Empty Data Container !!\n";
        return;
    }

    auto itr = std::find_if(
        data.begin(), 
        data.end(),
        [&](const Vehicle& v){return v.vehicleId()==id;}
    );

// If Id is not match
    if(itr == data.end()){
        std::lock_guard<std::mutex>lk(mt);
        std::cerr<<"Invalid ID !!\n";
    }
    else{
    std::lock_guard<std::mutex>lk(mt);
    std::cout<<"The VehicleType of the given Id is : "<<static_cast<int>(itr->vehicleType())<<"\n";
    }
}

void DisplayCount(const Container &data)
{
    //Exception case if data container is Empty
    if(data.empty())
    {
        std::lock_guard<std::mutex>lk(mt);
        std::cerr<<"Empty Data Container !!\n";
        return;
    }

    int result = std::count_if(
        data.begin(),
        data.end(),
        [&]( Vehicle v){return (v.CalculateGSTAmount()>5000 && v.vehicleManufacturingYear() == 2023);}
    );

    if(result){
        std::lock_guard<std::mutex>lk(mt);
        std::cout<<"The Count of Vehicles that have Manufacturing Year 2023 && GST above 5000 : "<<result<<"\n";
    }
    
    //If no vehicle  found 
    else{
        std::lock_guard<std::mutex>lk(mt);
        std::cerr<<"No Vehicle FOund!!\n";
    }
}

void JoinThread(ThreadContainer &data)
{
    //Exception case if data container is Empty
    if(data.empty())
    {
        std::lock_guard<std::mutex>lk(mt);
        std::cerr<<"Empty Data Container !!\n";
        return;
    }
    std::for_each(data.begin() , data.end(),
    [&]( std::thread& th){if(th.joinable()){th.join();}}
    );
}

void CreateThread(ThreadContainer &data , const Container& data1)
{

    data.emplace_back(std::thread(&DisplayAverageInsurancePremiumCost , std::ref(data1) , 2));
    data.emplace_back(std::thread(&IsAllObjectsHaveNCAPCertified , std::ref(data1)));
    data.emplace_back(std::thread(&FindVehicleTypeForGivenID , std::ref(data1) , "2A"));
    data.emplace_back(std::thread(&DisplayCount , std::ref(data1)));
}
