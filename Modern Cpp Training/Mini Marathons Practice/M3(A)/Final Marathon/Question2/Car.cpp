#include "Car.h"

Car::Car(std::string m_car_reg_num, float m_price, RefWrapper m_car_engine) : _m_car_reg_num{m_car_reg_num}, _m_price{m_price}, _m_car_engine{m_car_engine}
{
}
std::ostream &operator<<(std::ostream &os, const Car &rhs)
{
    os << "_m_car_reg_num: " << rhs._m_car_reg_num
       << " _m_price: " << rhs._m_price
       << " _m_car_engine: " << rhs._m_car_engine.get();
    return os;
}
