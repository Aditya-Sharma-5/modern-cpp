#include "Functionalities.h"
/*
This function is used to create objects of the class and push data into it.
*/
void CreateData(Container &data)
{
    data.emplace(std::make_pair<std::string, CarPtr>("101", std::make_shared<CarUnit>("101", 455, CarType::HATCHBACK, 89, 76, GearSystemType::CLASSIC)));
    data.emplace(std::make_pair<std::string, CarPtr>("102", std::make_shared<CarUnit>("102", 456, CarType::HATCHBACK, 90, 65, GearSystemType::CLASSIC)));
    data.emplace(std::make_pair<std::string, CarPtr>("103", std::make_shared<CarUnit>("103", 559, CarType::SEDAN, 99, 61, GearSystemType::CLASSIC)));
    data.emplace(std::make_pair<std::string, CarPtr>("104", std::make_shared<CarUnit>("104", 455, CarType::HATCHBACK, 89, 21, GearSystemType::CLASSIC)));
    data.emplace(std::make_pair<std::string, CarPtr>("105", std::make_shared<CarUnit>("105", 459, CarType::SUV, 91, 60, GearSystemType::CLASSIC)));
}
/*
This function checks does all the objects have same gear box or not
*/
bool CheckAllGearBox(Container &data)
{
    if (data.empty())
    {
        throw DataEmpty("Container is Emptyy!!!");
    }
    bool count = std::all_of(data.begin(), data.end(), [](const MapEntry &Mv)
                             { return Mv.second->mCarGearSystem() == GearSystemType::CLASSIC; });
    bool count1 = std::all_of(data.begin(), data.end(), [](const MapEntry &Mv)
                              { return Mv.second->mCarGearSystem() == GearSystemType::PRNDL; });
    bool count2 = std::all_of(data.begin(), data.end(), [](const MapEntry &Mv)
                              { return Mv.second->mCarGearSystem() == GearSystemType::TIPTRONIC; });
    if (count == 1 || count1 == 1 || count2 == 1)
    {
        return true;
    }
    return false;
}

/*
This func returns the Car price based on lowest car speed.
*/
int ReturnCarPrice(Container &data)
{
    if (data.empty())
    {
        throw DataEmpty("Container is Emptyy!!!");
    }
    auto itr = std::min_element(data.begin(), data.end(), [](const MapEntry mv, const MapEntry mv2)
                                { return mv.second->mCarTopSpeed() < mv2.second->mCarTopSpeed(); });

    if (itr != data.end())
    {
        return (*itr).second.get()->mCarPrice();
    }
    else
    {
        throw std::nullopt;
    }
}
/*
This function returns the Container for all matching instances.
*/
std::optional<Container> ReturnAllMatchingInstance(Container &data, CarType c)
{
    if (data.empty())
    {
        throw DataEmpty("Container is Emptyy!!!");
    }
    auto itr = std::find_if(data.begin(), data.end(), [&](const MapEntry &mp)
                            { return mp.second->mCarType() == c; });
    Container result;
    std::copy_if(data.begin(), data.end(), std::inserter(result, result.begin()), [&](const MapEntry &mv)
                 { return mv.second->mCarType() == c; });
    if (result.empty())
    {
        throw std::nullopt;
    }
    return result;
}
/*
This function counts all the instances which have more carprice as the threshold given by the user
*/
int CountofInstancesOverThreshold(Container &data, unsigned int n)
{
    if (data.empty())
    {
        throw DataEmpty("Container is Emptyy!!!");
    }
    std::size_t count = std::count_if(data.begin(), data.end(), [&](const MapEntry &mv)
                                      { return mv.second.get()->mCarPrice() > n; });
    if (count == 0)
    {
        throw std::nullopt;
    }
    return count;
}
/*
This function find the Top RMP bases on the ID
*/
int FindTopRPMbasedOntheId(Container &data, std::string m)
{
    if (data.empty())
    {
        throw DataEmpty("Container is Emptyy!!!");
    }
    auto itr = std::find_if(data.begin(), data.end(), [&](const MapEntry &mv)
                            { return mv.second.get()->mCarBrand() == m; });

    if (itr != data.end())
    {
        return (*itr).second.get()->mCarTopRpm();
    }
    else
    {
        throw std::nullopt;
    }
}
