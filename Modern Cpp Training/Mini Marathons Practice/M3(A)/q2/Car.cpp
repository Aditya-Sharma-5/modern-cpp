#include "Car.hpp"

Car::Car(std::string name, std::string number, Category cat, float price, RimSize size, int press)
:_brand_name{name}, _chasis_number{number}, _category{cat}, _price{price}, _rim_size{size}, _tyre_pressure{press}
{}


std::ostream &operator<<(std::ostream &os, const Car &rhs) {

    std::string a {""};
    std::string b {""};

    if(rhs.category() == Category::COMMUTE){
        a = "Commute";
    }
    else if(rhs.category() == Category::TOURIST){
        a = "Tourist";
    }
    else {
        a = "Sport";
    }

    if(rhs.rimSize() == RimSize::INCH_14){
        b = "14 Inch";
    }
    else if(rhs.rimSize() == RimSize::INCH_14){
        b = "15 Inch";
    }
    else if(rhs.rimSize() == RimSize::INCH_14){
        b = "16 Inch";
    }
    else{
        b = "18 Inch";
    }

    os << "_brand_name: " << rhs._brand_name
       << " _chasis_number: " << rhs._chasis_number
       << " _category: " << a
       << " _price: " << rhs._price
       << " _rim_size: " << b
       << " _tyre_pressure: " << rhs._tyre_pressure;
    return os;
}
