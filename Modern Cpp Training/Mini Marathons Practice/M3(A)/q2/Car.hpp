#ifndef CAR_HPP
#define CAR_HPP

#include<iostream>
#include "RimSize.hpp"
#include "Category.hpp"

class Car
{
private:
    /* data */
    std::string _brand_name;
    std::string _chasis_number;
    Category _category ;
    float _price;
    RimSize _rim_size;
    int _tyre_pressure; // in range 30-40

public:
    // Car(/* args */) = delete;
    // // Car(const Car&) = delete;
    // Car(Car&&) = delete;
    // Car& operator=(const Car&) = delete;
    // Car& operator=(Car&&) = delete;

    Car(std::string name, std::string number, Category cat, float price, RimSize size, int press);

    ~Car() {}

    std::string brandName() const { return _brand_name; }
    void setBrandName(const std::string &brand_name) { _brand_name = brand_name; }

    std::string chasisNumber() const { return _chasis_number; }
    void setChasisNumber(const std::string &chasis_number) { _chasis_number = chasis_number; }

    Category category() const { return _category; }
    void setCategory(const Category &category) { _category = category; }

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    RimSize rimSize() const { return _rim_size; }
    void setRimSize(const RimSize &rim_size) { _rim_size = rim_size; }

    int tyrePressure() const { return _tyre_pressure; }
    void setTyrePressure(int tyre_pressure) { _tyre_pressure = tyre_pressure; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif // CAR_HPP
