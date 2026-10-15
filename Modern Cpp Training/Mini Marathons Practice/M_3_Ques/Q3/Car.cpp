#include"Car.h"

Car::Car(int seat, float price, float wheel, ChassisType type)
    : _seat_count{seat}, _price{price}, _wheel_base{wheel}, _chassis{type}
{}
std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_seat_count: " << rhs._seat_count
       << " _price: " << rhs._price
       << " _wheel_base: " << rhs._wheel_base
       << " _chassis: " << static_cast<int>(rhs._chassis);
    return os;
}
