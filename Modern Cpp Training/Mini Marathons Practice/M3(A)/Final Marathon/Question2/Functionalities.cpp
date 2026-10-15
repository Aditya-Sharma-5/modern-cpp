#include "Functionalities.h"

/*
This Function creates Data and pushes it into vectorr
*/
void CreateObjects(EngineContainer &Edata, Container &data)
{
    Edata.push_back(Engine("345", 56, 78, EngineType::MPFI));
    Edata.push_back(Engine("785", 61, 87, EngineType::CRDI));
    Edata.push_back(Engine("672", 78, 31, EngineType::TURBOCHARGED));
    Edata.push_back(Engine("722", 32, 78, EngineType::TURBOCHARGED));
    Edata.push_back(Engine("782", 17, 12, EngineType::CRDI));

    auto itr = Edata.begin();
    if (itr != Edata.end())
    {
        data.push_back(std::make_shared<Car>("MH-123", 45, *itr++));
    }
    if (itr != Edata.end())
    {
        data.push_back(std::make_shared<Car>("MH-321", 53, *itr++));
    }
    if (itr != Edata.end())
    {
        data.push_back(std::make_shared<Car>("MH-678", 51, *itr++));
    }
    if (itr != Edata.end())
    {
        data.push_back(std::make_shared<Car>("MH-821", 19, *itr++));
    }
    if (itr != Edata.end())
    {
        data.push_back(std::make_shared<Car>("MH-345", 10, *itr++));
    }
}

/*
This function return the RefContainer till the N instances.
*/
std::optional<RefContainer> ReturnTillN(EngineContainer &data, unsigned int N)
{
    if (data.empty())
    {
        throw DataEmpty("Container is Emptry!!!", std::future_errc::no_state);
    }
    RefContainer result;
    std::copy_n(data.begin(), N, std::inserter(result, result.begin()));

    if (result.empty())
    {
        return std::nullopt;
    }
    return result;
}
/*
This Function Checks all the Engine Torque is above 120 by using stl::all_all.
*/
bool AllEngineTorqueOver120(const Container &data)
{
    if (data.empty())
    {
        throw DataEmpty("Container is Emptry!!!", std::future_errc::no_state);
    }
    bool count = std::all_of(data.begin(), data.end(), [](const CarPtr &C)
                             { return C->mCarEngine().get().mEnggineTorque() > 120; });
    if (count == 1)
    {
        return true;
    }
    return false;
}
/*
This function retuirns the average of the hourse power.
*/
float FindAverageHorsePower(const Container &data)
{
    if (data.empty())
    {
        throw DataEmpty("Container is Emptry!!!", std::future_errc::no_state);
    }
    float Sum = std::accumulate(data.begin(), data.end(), 0.0f, [](float sum_till_point, const CarPtr &cv)
                                { return sum_till_point + cv->mCarEngine().get().mHoursePower(); });
    return Sum / data.size();
}
/*
This function returns the highest torque value;

*/
RefContainer HighestEngineTorque(const Container &data)
{
   

    auto itr = std::max_element(data.begin(), data.end(), [](const CarPtr &c1, const CarPtr &c2)
                                { return c1->mCarEngine().get().mEnggineTorque() < c2->mCarEngine().get().mEnggineTorque(); });
    // std::cout << (**itr) << std::endl;
    RefContainer result;
    result.push_back((*itr).get()->mCarEngine());
    return result;
}

/*
This function returns the Enginetype based on ID
*/
EngineType FindEngineTypeBasedOnID(Container &data, std::string number)
{  
     if (data.empty())
    {
        throw DataEmpty("Container is Emptry!!!", std::future_errc::no_state);
    }
    auto itr = std::find_if(data.begin(), data.end(), [&](CarPtr &cv)
                            { return cv->mCarRegNum() == number; });
    return itr->get()->mCarEngine().get().mEngineType();
}

void Display(Container &data)
{
    for (CarPtr &p : data)
    {
        std::cout << *p << std::endl;
    }
}