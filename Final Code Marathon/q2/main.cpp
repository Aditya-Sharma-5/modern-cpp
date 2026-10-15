#include "Functionaities.h"

int main()
{
    DataContainer _data;

    CreateObject(_data);

    try
    {
        std::vector<CabFuelType> r1 = ContainerOfFUELType(_data, 2);
        std::cout << "The Cab Fuel Type of N instances : \n";
        for (CabFuelType v : r1)
        {
            std::cout << static_cast<int>(v) << "\n";
        }
        std::cout << "\n\n";
    }
    catch (const EmptyContainerError &obj)
    {
        std::cerr << obj.what() << "\n";
    }

    try
    {
        int r2 = CountOfMatchCABSTATUS(_data, CabStatus::PRIVATELY_OWNED);
        std::cout << "The count of Match Cab Status : " << r2 << "\n";
    }
    catch (const EmptyContainerError &obj)
    {
        std::cerr << obj.what() << "\n";
    }
    catch (const UnmatchConditionError &obj)
    {
        std::cerr << obj.what() << "\n";
    }

    try
    {
        bool r3 = Atleast1CabHaveSeatAbove5(_data);
        std::cout << "At Least 1 Cab Have Seat Above 5 or not : " << std::boolalpha << r3 << "\n";
    }
    catch (const EmptyContainerError &obj)
    {
        std::cerr << obj.what() << "\n";
    }

    try
    {
        std::vector<CabType> r4 = ContainerOfCABTYPE(_data, 2);
        std::cout << "The Cab Type of N instances : \n";
        for (CabType v : r4)
        {
            std::cout << static_cast<int>(v) << "\n";
        }
        std::cout << "\n\n";
    }
    catch (const EmptyContainerError &obj)
    {
        std::cerr << obj.what() << "\n";
    }

    try
    {
        int seatCount = AverageSeatCount(_data);
        std::cout << "The Average Seat Count : " << seatCount << "\n";
    }
    catch (const EmptyContainerError &obj)
    {
        std::cerr << obj.what() << "\n";
    }
    catch (const UnmatchConditionError &obj)
    {
        std::cerr << obj.what() << "\n";
    }

    try
    {
        std::pair<bool, CabFuelType> pair = PairForGivenId(_data, "2A");
        std::cout << pair.first << "   " << static_cast<int>(pair.second) << "\n";
    }
    catch (const EmptyContainerError &obj)
    {
        std::cerr << obj.what() << "\n";
    }
    catch (const InvalidInput &obj)
    {
        std::cerr << obj.what() << "\n";
    }
}