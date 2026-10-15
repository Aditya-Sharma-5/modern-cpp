#include "Functionalities.h"
#include <iostream>

int main()
{

    Container data;
    CreateObjects(data);
    try
    {
        // Display(data);
        std::cout << "The count of instances where Chasis length is above 2.7 is " << CountofInstances(data) << std::endl;

        std::cout << "**********************************************************************" << std::endl;

        std::cout << "The list of EVCar Instances till N" << std::endl;
        std::optional<std::list<EvPtr>> Answer = ReturnTillN(data, 2);
        std::list<EvPtr> Answer2;
        if (Answer.has_value())
        {
            Answer2 = Answer.value();
        }
        for (auto ptr : Answer2)
        {
            std::cout << *ptr << std::endl;
        }

        std::cout << "**********************************************************************" << std::endl;

        std::cout << "The Top speed for the given id will be " << FindTopSpeed(data, "MH-123") << std::endl;

        std::cout << "**********************************************************************" << std::endl;
        if (FindPureEv(data) == 1)
        {
            std::cout << "Yes One Instance of PureEv is Present there" << std::endl;
        }
        else
        {
            std::cout << "No instance of PureEv is present there" << std::endl;
        }

        std::cout << "********************************************************************************************************" << std::endl;
        Adaptor(data, 2, Display);
    }
    catch (DataEmpty &ex)
    {
        std::cerr << ex.what();
    }
    catch (InvalidIndex &ex)
    {
        std::cerr << ex.what();
    }
    return 0;
}