#include "Functionalities.h"

void CreateObjects(Container &data)
{

    data.push_back(std::make_shared<EvCar>("234", "Maruti", 9000, EPowerType::ELECTRIC, BatterType::LI_ON));
    data.push_back(std::make_shared<EvCar>("234", "TaTa", 60000, EPowerType::HYBRID, BatterType::NICAD));
    data.push_back(std::make_shared<EvCar>("234", "TaTa", 60000, EPowerType::HYBRID, BatterType::NICAD));
    data.push_back(std::make_shared<ICeCar>("567", "Audi", 89999, EngineType::DIESEL));
    data.push_back(std::make_shared<ICeCar>("567", "BMW", 91999, EngineType::PETROL));
}

void DisplayRegistrationFees(Container &data)
{
    if (data.empty())
    {
        throw DataEmptyException("Container is empty!!!!");
    }
    for (Vtype &v : data)
    {
        if (std::holds_alternative<EVptr>(v))
        {
            std::cout << " The Registration fees will be in EVCLASS for per instance - ";
            std::cout << std::get<0>(v)->CalculateRegistrationCharges() << std::endl;
        }
    }
}

float ReturnAvgforPriceOftheEVCar(const Container &data)
{
    if (data.empty())
    {
        throw DataEmptyException("Container is empty!!!!");
    }
    float sum = 0;
    float count = 0;
    for (Vtype v : data)
    {
        if (std::holds_alternative<EVptr>(v))
        {

            sum += std::get<0>(v)->price();
            count++;
        }
    }
    if (count == 0)
    {
        throw InstanceNotFound("Instance which you are looking for is not available!!!");
    }
    return sum / count;
}

int ReturnCountofEvCarWithSimilarEngineType(const Container &data, EPowerType ET)
{

    if (data.empty())
    {
        throw DataEmptyException("Container is empty!!!!");
    }
    int count = 0;
    for (Vtype v : data)
    {
        if (std::holds_alternative<EVptr>(v))
        {
            if (std::get<0>(v)->ePowerType() == ET)
            {
                count++;
            }
        }
    }
    if (count == 0)
    {
        throw InstanceNotFound("Instance which you are looking for is not available!!!");
    }
    return count;
}
Container ReturnMatchingInstances(Container &data)
{
    if (data.empty())
    {
        throw DataEmptyException("Container is empty!!!!");
    }
    Container result;
    for (Vtype v : data)
    {
        if (std::holds_alternative<EVptr>(v))
        {
            if (std::get<0>(v)->price() > 60000)
            {
                result.push_back(v);
                // Answer = std::get<0>(v)->brandName();
            }
        }
        if (std::holds_alternative<ICeptr>(v))
        {
            if (std::get<1>(v)->price() > 60000)
            {
                result.push_back(v);
            }
        }
    }
    if (result.empty())
    {
        throw DataEmptyException("Container is empty!!!!");
    }
    return result;
}
std::string ReturnBrandNameBasedOntheidPassed(const Container &data, std::string id)
{
    if (data.empty())
    {
        throw DataEmptyException("Container is empty!!!!");
    }
    std::string Answer;
    for (Vtype v : data)
    {

        std::visit([&](auto &&val)
                   {
            if (val->id() == id)
            {
                Answer= val->brandName();
            } },
                   v);
    }
    if (Answer.empty())
    {
        throw DataEmptyException("String is empty!!!!");
    }

    return Answer;
}

bool AllInstanceHavingPriceOver60000(const Container &data)
{
    if (data.empty())
    {
        throw DataEmptyException("Container is empty!!!!");
    }
    bool flag = false;
    for (Vtype v : data)
    {
        std::visit([&](auto &&val)
                   {
            if(val->price()>60000)
            
               flag=true; },
                   v);
    }
    return flag;
}

BatterType ReturnUnique(Container &data)
{
    if (data.empty())
    {
        throw DataEmptyException("Container is empty!!!!");
    }
    int count = 0;
    int count1 = 0;
    int count2 = 0;
    BatterType Answer;
    for (Vtype v : data)
    {
        if (std::holds_alternative<EVptr>(v))
        {
            if (std::get<0>(v)->batteryType() == BatterType::LI_ON)
            {
                count++;
            }
            if (std::get<0>(v)->batteryType() == BatterType::NICAD)
            {
                count1++;
            }

            if (count == 1)
            {
                Answer = BatterType::LI_ON;
            }
            else
            {
                Answer = BatterType::NICAD;
            }
        }
    }
    if (count == 0 || count1 == 0)
    {
        throw InstanceNotFound("Instance which you are looking for is not here!!!");
    }
    return Answer;
}
