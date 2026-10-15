#include "Car.h"


Car::Car(std::string car_id, std::string car_brand, CarType car_type, Engine *car_engine, float car_price)
: _car_id{car_id} , _car_brand{car_brand} , _car_type{car_type}, _car_engine{car_engine} , _car_price{car_price}
{
}

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_car_id: " << rhs._car_id<<"\n"
       << " _car_brand: " << rhs._car_brand<<"\n"
       << " _car_type: ";

       if(static_cast<int>(rhs._car_type) == 1){
        os<<"SEDAN \n";
       }
       else if(static_cast<int>(rhs._car_type) == 2){
        os<<"SUV \n";
       }
       else if(static_cast<int>(rhs._car_type) == 3){
        os<<"SPORTS \n";
       }
       else if(static_cast<int>(rhs._car_type) == 4){
        os<<"HATCHBACK \n";
       }

    os << " _car_engine: " << *rhs._car_engine<<" \n"
       << " _car_price: " << rhs._car_price<<" \n";
    return os;
}
