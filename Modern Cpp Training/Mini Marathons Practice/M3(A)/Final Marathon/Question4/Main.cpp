#include "Functionalities.h"
#include <iostream>

int main()
{

    Container data;
    CreateObjects(data);
    try
    {
        DisplayRegistrationFees(data);
        std::cout << "**************************************************************************************************" << std::endl;

        std::cout << "The Average Price for all the EV Vehicle will be " << ReturnAvgforPriceOftheEVCar(data) << std::endl;

        std::cout << "**************************************************************************************************" << std::endl;

        std::cout << "The Count of the Instances having matching EngineType will be -> " << ReturnCountofEvCarWithSimilarEngineType(data, EPowerType::ELECTRIC) << std::endl;
        std::cout << "**************************************************************************************************" << std::endl;

        std::cout << "The Brand Name Based on the Id provided - >" << ReturnBrandNameBasedOntheidPassed(data, "234") << std::endl;
        std::cout << "**************************************************************************************************" << std::endl;

        if (AllInstanceHavingPriceOver60000(data) == 1)
        {
            std::cout << "All instances of the Variant of EV and ICe Car are having their price above the threholdd " << std::endl;
        }
        else
        {
            std::cout << "All instances of Variant of EV and ICe Car are not having their price above the threholdd " << std::endl;
        }
        std::cout << "**************************************************************************************************" << std::endl;
        std::cout << "The Battery Type which is Unique will be--> ";
        BatterType ans = ReturnUnique(data);
        if (ans == BatterType::LI_ON)
        {
            std::cout << "LI_ON";
        }
        else
        {
            std::cout << "NICAD";
        }
        Container Result = ReturnMatchingInstances(data);
    }
    catch (DataEmptyException &ex)
    {
        std::cerr << ex.what();
    }
    catch (InstanceNotFound &ex)
    {
        std::cerr << ex.what();
    }
    catch (InvalidIndex &ex)
    {
        std::cerr << ex.what();
    }

    return 0;
}