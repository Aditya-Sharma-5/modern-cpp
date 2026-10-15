#ifndef ICECAR_H
#define ICECAR_H

#include <iostream>
#include "EngineType.h"
class ICeCar
{
private:
    std::string _id;
    std::string _brand_name;
    float _price;
    EngineType _engine_type;

public:
    ICeCar() = default; // Default constructor
    ICeCar(std::string id, std::string brand_name, float price, EngineType engine_type);
    ICeCar(const ICeCar &) = default;           // Copy constructor
    ICeCar &operator=(const ICeCar &) = delete; // Copy assignment operator
    ICeCar(ICeCar &&) = delete;                 // Move constructor
    ICeCar &operator=(ICeCar &&) = delete;      // Move assignment operator
    ~ICeCar() = default;                        // Destructor

    std::string id() const { return _id; }

    std::string brandName() const { return _brand_name; }

    float price() const { return _price; }

    EngineType engineType() const { return _engine_type; }

    friend std::ostream &operator<<(std::ostream &os, const ICeCar &rhs);
    float CalculateRegistrationCharges();
};

#endif // ICECAR_H
