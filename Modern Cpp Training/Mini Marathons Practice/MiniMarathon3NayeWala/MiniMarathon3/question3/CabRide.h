#ifndef CABRIDE_H
#define CABRIDE_H
#include <iostream>
#include <variant>
#include "RideType.h"
#include "PaymentMode.h"
#include <functional>
#include "Driver.h"
#include<ostream>
class CabRide
{
private:
    std::variant<std::string, int> _id;
    RideType _ride_type{RideType::RENT};
    PaymentMode _payment_mode{PaymentMode::CASH};
    float _fare{0.0f};
    std::string _drop_location{""};
    std::string _pickup_location{""};
    std::reference_wrapper<Driver> _cab_driver;

public:
    CabRide() = default;
    CabRide(const CabRide &) = delete;
    CabRide(CabRide &&) = delete;
    CabRide &operator=(const CabRide &) = delete;
    CabRide &operator=(CabRide &&) = delete;
    ~CabRide() = default;

    CabRide(std::variant<std::string,int> id, RideType rtype, PaymentMode pmode, float fare, std::string drop, std::string pickup, std::reference_wrapper<Driver> driver);

    std::variant<std::string, int> id() const { return _id; }
    void setId(const std::variant<std::string, int> &id) { _id = id; }

    RideType rideType() const { return _ride_type; }
    void setRideType(const RideType &ride_type) { _ride_type = ride_type; }

    PaymentMode paymentMode() const { return _payment_mode; }
    void setPaymentMode(const PaymentMode &payment_mode) { _payment_mode = payment_mode; }

    std::string dropLocation() const { return _drop_location; }
    void setDropLocation(const std::string &drop_location) { _drop_location = drop_location; }

    float fare() const { return _fare; }
    void setFare(float fare) { _fare = fare; }

    std::string pickupLocation() const { return _pickup_location; }
    void setPickupLocation(const std::string &pickup_location) { _pickup_location = pickup_location; }

    std::reference_wrapper<Driver> cabDriver() const { return _cab_driver; }
    void setCabDriver(const std::reference_wrapper<Driver> &cab_driver) { _cab_driver = cab_driver; }

    friend std::ostream &operator<<(std::ostream &os, const CabRide &rhs);
};

#endif // CABRIDE_H
