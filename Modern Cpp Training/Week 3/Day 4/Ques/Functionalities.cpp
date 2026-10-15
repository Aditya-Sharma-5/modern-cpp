#include "Functionalities.h"

std::mutex mt;
void CreateObject(DataContainer &data)
{
    data.push_back(std::make_shared<Vehicle>("1A" , 25000.0f , ChassisType::LADDER , VehicleCategory::PRIVATE , 2.2 , FeatureList{Feature::ADAS , Feature::CLIMATE_CONTROL, Feature::INFOTAINMENT , Feature::NCAP_RATING_5}));
    data.push_back(std::make_shared<Vehicle>("1B" , 32000.0f , ChassisType::LADDER , VehicleCategory::SPECIAL_PURPOSE , 1.8 , FeatureList{Feature::_4_WHEEL_DRIVE , Feature::CLIMATE_CONTROL , Feature::INFOTAINMENT}));
    data.push_back(std::make_shared<Vehicle>("1C" , 28000.0f , ChassisType::OTHER , VehicleCategory::DEFENCE, 3.2 , FeatureList{Feature::_4_WHEEL_DRIVE , Feature::CLIMATE_CONTROL , Feature::NCAP_RATING_5}));
    data.push_back(std::make_shared<Vehicle>("1D" , 11000.0f , ChassisType::MONO , VehicleCategory::TRANSPORT , 2.1 , FeatureList{Feature::_4_WHEEL_DRIVE , Feature::CLIMATE_CONTROL , Feature::INFOTAINMENT}));
}

void DisplayChassisTypeForGivenIds(const DataContainer &data, std::list<std::string> ids)
{
    if(data.empty())
    {
        std::lock_guard<std::mutex>lk(mt);
        std::cerr<<"Empty Data Container!!\n";
        return ;
    }

    if(ids.empty())
    {
        std::lock_guard<std::mutex>lk(mt);
        std::cerr<<"No Id given \n";
        return ;
    }

    for(std::string id : ids)
    {
        for(Vptr v : data)
        {
            if(v->id() == id)
            {
                std::lock_guard<std::mutex>lk(mt);
                std::cout<<"The Chassis Type of Id "<<id<<" is : "<<static_cast<int>(v->chassisType())<<"\n";
                break;
            }
        }
    }
}

void MaxPriceOfFirstNInstances(const DataContainer &data, unsigned int N)
{
    if(data.empty())
    {
        std::lock_guard<std::mutex>lk(mt);
        std::cerr<<"Empty Data Container!!\n";
        return ;
    }

    if(N<=0 ||N>data.size())
    {
        std::lock_guard<std::mutex>lk(mt);
        std::cerr<<"Invalid Value of N \n";
        return ;
    }

    float maxPrice = data[0].get()->price();

    for(int i = 0 ; i<N; i++)
    {
        if(maxPrice<data[i].get()->price())
        {
            maxPrice = data[i].get()->price();
        }
    }

    std::lock_guard<std::mutex>lk(mt);
    std::cout<<"The Max Price is : "<<maxPrice<<"\n";

}

void CountVehicleOfGivenCategory(const DataContainer &data, VehicleCategory category)
{
    if(data.empty())
    {
        std::lock_guard<std::mutex>lk(mt);
        std::cerr<<"Empty Data Container!!\n";
        return ;
    }

    int count = 0 ;

    for(Vptr v : data){
        if(v->vehicleCategory() == category){
            count++;
        }
    }

    if(count == 0 ){
        std::lock_guard<std::mutex>lk(mt);
        std::cerr<<"No Vehicle Found for this Id \n";
        return ;
    }
    else{
        std::lock_guard<std::mutex>lk(mt);
        std::cout<<"The Count of the given category are : "<<count<<"\n";
    }

}

void DisplayFirstNVehicle(const DataContainer &data, unsigned int N)
{
    if(data.empty())
    {
        std::lock_guard<std::mutex>lk(mt);
        std::cerr<<"Empty Data Container!!\n";
        return ;
    }

    if(N<=0 ||N>data.size())
    {
        std::lock_guard<std::mutex>lk(mt);
        std::cerr<<"Invalid Value of N \n";
        return ;
    }

    // std::lock_guard<std::mutex>lk(mt);
    // std::cout<<"The Data of First "<<N<<" Objects : \n";

    for(int i = 0 ; i<N ; i++)
    {
        std::lock_guard<std::mutex>lk(mt);
        std::cout<<*data[i]<<"\n";
    }

}

void AreAllCarPricesAboveGivenThreshold(const DataContainer &data, float threshold)
{
    if(data.empty())
    {
        std::lock_guard<std::mutex>lk(mt);
        std::cerr<<"Empty Data Container!!\n";
        return;
    }

    bool flag = false;
    for(Vptr v:data)
    {
        if(v.get()->price()<threshold){ 
            flag = true;
        }
    }
    if(flag == true )
    {
        std::lock_guard<std::mutex>lk(mt);
        std::cout <<"False : Not all the Car Prices are above the given Threshold\n";
    }
    else
    {
        std::lock_guard<std::mutex>lk(mt);
        std::cout<<"True : All the Car Prices are above the given Threshold\n";
    }

}
