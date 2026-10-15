#include "CarUnit.h"

CarUnit::CarUnit(std::string id, std::string model_name, float price, CarType carType)
: _id{id} , _model_name{model_name}, _price{price} , _carType{carType}
{
}
std::ostream &operator<<(std::ostream &os, const CarUnit &rhs) {
    os << "_id: " << rhs._id<<"\n"
       << " _model_name: " << rhs._model_name<<"\n"
       << " _price: " << rhs._price<<"\n"
       << " _carType: " <<static_cast<int>( rhs._carType)<<"\n";
    return os;
}
