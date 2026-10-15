#include <iostream>
#include "Operations.h"

int main()
{

    std::shared_ptr<Operations> ptr = Operations::createInstance();
    ptr->CreateCabObjects();

    std::future<PaymentMode> t1 = std::async(&Operations::PaymentModeByID, ptr, "C-101");
    std::future<std::array<RideType, 2>> t2 = std::async(&Operations::MaximumMinimumRideType, ptr);
    std::future<std::vector<std::string>> t3 = std::async(&Operations::FirstNPickupLocations, ptr, 2);
    std::future<void> t4 = std::async(&Operations::TakeInput, ptr);
    std::future<std::vector<Driver>> t5 = std::async(&Operations::NDriverInstance, ptr);

    PaymentMode paymentMode;
    std::array<RideType, 2> MaxMinRideType;
    std::vector<std::string> NPickups;
    std::vector<Driver> Drivers;


    try
    {
        paymentMode = t1.get();
        MaxMinRideType = t2.get();
        NPickups = t3.get();
        t4.wait();
        ptr->Notify();
        Drivers = t5.get();

        std::cout << "Payment Mode for given Id is  : ";
        if (paymentMode == PaymentMode::CASH)
        {
            std::cout << "Cash" << std::endl;
        }
        else if (paymentMode == PaymentMode::UPI)
        {
            std::cout << "UPI" << std::endl;
        }
        else if (paymentMode == PaymentMode::CARD)
        {
            std::cout << "CARD" << std::endl;
        }
        else
        {
            std::cout << "Wallet" << std::endl;
        }

        std::cout << "Ride Type Corresponding to Max Min Fare is : ";
        for (RideType r : MaxMinRideType)
        {
            if (r == RideType::RENT)
            {
                std::cout << "Rental"
                          << " ";
            }
            else if (r == RideType::OUTSTATION)
            {
                std::cout << "Outstation"
                          << " ";
            }
            else
            {
                std::cout << "Local"
                          << " ";
            }
        }
        std::cout << std::endl;

        std::cout << "First N PickUp Location are : ";
        for (std::string s : NPickups)
        {
            std::cout << s << " ";
        }
        std::cout << "\n";

        std::cout << "Details of Drivers are: " << std::endl;
        for (Driver r : Drivers)
        {
            std::cout << r << std::endl;
        }
    }
    catch (std::future_error &fe)
    {
        if (fe.code() == std::future_errc::no_state)
        {
            std::cout << fe.what() << std::endl;
        }
    }

    return 0;
}