#include "Functionalities.h"
/*
    This Function Create objects of Evcar and pushes it into Vector.
*/
void CreateObjects(Container &data)
{
    data.push_back(std::make_shared<EVCar>("MH-123", 23, PlatformType::IC_BASED, 67.0f, 4, 90));
    data.push_back(std::make_shared<EVCar>("MH-124", 20, PlatformType::PURE_EV, 79.0f, 2, 80));
    data.push_back(std::make_shared<EVCar>("MH-125", 21, PlatformType::IC_BASED, 43.0f, 4, 60));
    data.push_back(std::make_shared<EVCar>("MH-126", 28, PlatformType::IC_BASED, 21.0f, 4, 20));
    data.push_back(std::make_shared<EVCar>("MH-127", 31, PlatformType::PURE_EV, 43.0f, 4, 50));
}
/*
This function display the contents of the class by iterating over it .
*/
void Display(Container &data, int n)
{
    if (data.empty())
    {
        throw DataEmpty("Container is Empty!!!");
    }
    if (n > data.size() || 0 > n)
    {
        throw InvalidIndex("Enter a valid N");
    }
    Container result;
    std::copy_n(data.begin(), n, std::inserter(result, result.begin()));

    for (EvPtr &ptr : result)
    {
        std::cout << *ptr << std::endl;
    }
}

/*
This function iterate over the class and push the N instance given by the user in the list which we want to return.
*/

std::optional<std::list<EvPtr>> ReturnTillN(const Container &data, unsigned int N)
{
    if (data.empty())
    {
        throw DataEmpty("Container is Empty!!!");
    }
    if (N > data.size() || 0 > N)
    {
        throw InvalidIndex("Enter a valid N");
    }
    std::list<EvPtr> result;
    std::copy_n(data.begin(), N, std::inserter(result, result.begin()));
    if (result.empty())
    {
        return std::nullopt;
    }
    return result;
}
/*
This function returns the count of instance in which the chasis lenghth is above 2.7
*/
int CountofInstances(Container &data)
{
    if (data.empty())
    {
        throw DataEmpty("Container is Empty!!!");
    }
    size_t count = std::count_if(data.begin(), data.end(), [](const EvPtr &ev)
                                 { return ev->mChasisLength() > 2.7f; });
    return count;
}

/*
This function helps in finding top speed of the object based on the Id provided.
*/

int FindTopSpeed(const Container &data, std::string id)
{
    if (data.empty())
    {
        throw DataEmpty("Container is Empty!!!");
    }
    auto itr = std::find_if(data.begin(), data.end(), [&](const EvPtr &ev)
                            { return ev->mCarId() == id; });
    return (*itr)->mSeatCount();
}

/*
This function checks the occurence of findpureEv for once.
*/
bool FindPureEv(const Container &data)
{
    if (data.empty())
    {
        throw DataEmpty("Container is Empty!!!");
    }
    bool count = std::any_of(data.begin(), data.end(), [](const EvPtr &ev)
                             { return ev->mPlatform() == PlatformType::PURE_EV; });
    if (count == 1)
    {
        return true;
    }
    return false;
}
/*
Predicate or logic to satisfy the user condition
*/
void Adaptor(Container &data, int N, std::function<void(Container &data, int n)> fn)
{
    if (data.empty())
    {
        throw DataEmpty("Container is Empty!!!");
    }
    if (N > data.size() || 0 > N)
    {
        throw InvalidIndex("Enter a valid N");
    }
    fn(data, N);
}
