#include "Operations.h"
#include "EmptyContainerFutureException.h"
#include "NumberFutureException.h"
#include "IdNotFoundFutureException.h"

std::shared_ptr<Operations> Operations::_object{nullptr};

std::shared_ptr<Operations> Operations::createInstance()
{
    if (_object)
    {
        return _object;
    }
    else
    {
        _object.reset(new Operations());
        return _object;
    }
}

void Operations::CreateCabObjects()
{
    // Entry 1
    Driver d1("D-101", DriverRating::ONESTAR);
    _drivers.push_back(d1);
    _cab_data.push_back(std::make_shared<CabRide>("C-101", RideType::LOCAL, PaymentMode::CASH, 108.56f, "kurla", "London", _drivers[0]));

    // Entry 2
    Driver d2("D-102", DriverRating::TWOSTAR);
    _drivers.push_back(d2);
    _cab_data.push_back(std::make_shared<CabRide>(102, RideType::OUTSTATION, PaymentMode::CARD, 5673.56f, "vijyWada", "Kurla", _drivers[1]));

    // Entry 3
    Driver d3("D-103", DriverRating::THREESTAR);
    _drivers.push_back(d3);
    _cab_data.push_back(std::make_shared<CabRide>(103, RideType::RENT, PaymentMode::UPI, 534.56f, "tor", "lance", _drivers[2]));

    // Entry 4
    Driver d4("D-104", DriverRating::ONESTAR);
    _drivers.push_back(d4);
    _cab_data.push_back(std::make_shared<CabRide>("C-104", RideType::RENT, PaymentMode::CARD, 634.56f, "murla", "itawa", _drivers[3]));

    // Entry 5
    Driver d5("D-105", DriverRating::TWOSTAR);
    _drivers.push_back(d5);
    _cab_data.push_back(std::make_shared<CabRide>("C-105", RideType::OUTSTATION, PaymentMode::WALLET, 856.56f, "vikas", "delhi", _drivers[4]));
}

PaymentMode Operations::PaymentModeByID(std::variant<std::string, int> id)
{
    if (_cab_data.empty())
    {
        throw EmptyContainerFutureException(std::future_errc::no_state, "Container is Empty!");
    }
    
    auto itr = std::find_if(
        _cab_data.begin(),
        _cab_data.end(),
        [&](const std::shared_ptr<CabRide> &c)
        {
            return c->id() == id;
        });
    return (*itr)->paymentMode();

    throw IdNotFoundFutureException(std::future_errc::no_state, "Id Not Found!");
}

std::array<RideType, 2> Operations::MaximumMinimumRideType()
{
    if (_cab_data.empty())
    {
        throw EmptyContainerFutureException(std::future_errc::no_state, "Container is Empty!");
    }

    if (_cab_data.size() < 2)
    {
        throw NumberFutureException(std::future_errc::no_state, "Size is not in the Required Range");
    }
    auto max = std::max_element(
        _cab_data.begin(),
        _cab_data.end(),
        [](const std::shared_ptr<CabRide> &c1, const std::shared_ptr<CabRide> &c2)
        {
            return c1->fare() < c2->fare();
        });
    auto min = std::max_element(
        _cab_data.begin(),
        _cab_data.end(),
        [](const std::shared_ptr<CabRide> &c1, const std::shared_ptr<CabRide> &c2)
        {
            return c1->fare() > c2->fare();
        });
    std::array<RideType, 2> result;
    result[0] = (*min)->rideType();
    result[1] = (*max)->rideType();

    return result;
}

std::vector<std::string> Operations::FirstNPickupLocations(int N)
{

    if (_cab_data.empty())
    {
        throw EmptyContainerFutureException(std::future_errc::no_state, "Container is Empty!");
    }

    if (N < 0 || N >= _cab_data.size())
    {
        throw NumberFutureException(std::future_errc::no_state, "N is invalid argument !");
    }
    std::vector<std::string> result;
    for (int i = 0; i < N; i++)
    {
        result.push_back(_cab_data[i]->pickupLocation());
    }
    return result;
}

void Operations::TakeInput()
{
    if (_cab_data.empty())
    {
        throw EmptyContainerFutureException(std::future_errc::no_state, "Container is Empty!");
    }
    std::lock_guard<std::mutex> lg(mt);
    std::cout << "Enter the Value of N to Find Last N Diver instances : ";
    std::cin >> _N;
    flag = true;
}
void Operations::Notify()
{
    cv.notify_one();
}

std::vector<Driver> Operations::NDriverInstance()
{
    if (_cab_data.empty())
    {
        throw EmptyContainerFutureException(std::future_errc::no_state, "Container is Empty!");
    }

    std::unique_lock<std::mutex> ul(mt);
    cv.wait(ul, [&]()
            { return flag; });
    if (_N < 0 || _N >= _cab_data.size())
    {
        throw NumberFutureException(std::future_errc::no_state, "N is invalid argument !");
    }
    std::vector<Driver> result(_N);
    auto itr=_drivers.begin()+(_drivers.size()-_N);
    std::copy(itr,_drivers.end(),result.begin());

    return result;
}

/*
        0       1       2      3        4 

    data.begin()                            data.end()
*/
