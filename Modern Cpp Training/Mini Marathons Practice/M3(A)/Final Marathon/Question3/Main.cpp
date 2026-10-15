#include "Functionalities.h"

#include <iostream>

int main()
{

    Container data;
    CreateData(data);
    std::cout << "*******************Check All the Instance have same Gear box or not******************" << std::endl;
    if (CheckAllGearBox(data) == 1)
    {
        std::cout << "All the Insatnces in the map have the same GearBox" << std::endl;
    }
    else
    {
        std::cout << "All the Insatnces in the map doesn't have the same GearBox" << std::endl;
    }
    std::cout << "*******************************************************************************************************" << std::endl;
    std::optional<Container> ans = ReturnAllMatchingInstance(data, CarType::HATCHBACK);
    Container ReturingContainer;
    if (ans.has_value())
    {
        ReturingContainer = ans.value();
    }

    for (auto &[k, v] : ReturingContainer)
    {
        std::cout << k << *v << std::endl;
    }
    std::cout << "***********************************************************************************************************" << std::endl;

    std::cout << "The CarPrice based on the lowest Car speed will be " << ReturnCarPrice(data) << std::endl;

    std::cout << "***********************************************************************************************************" << std::endl;

    std::cout << "The count of instances where CarPrice is higher than the paramter will be " << CountofInstancesOverThreshold(data, 100) << std::endl;

    std::cout << "***********************************************************************************************************" << std::endl;

    std::cout << "The Top RVM model based on ID provided will be " << FindTopRPMbasedOntheId(data, "101") << std::endl;
    return 0;
}