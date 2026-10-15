#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP

#include "Car.hpp"
#include<list>
#include<future>
#include<functional>
#include<optional>
#include "EmptyContainer.hpp"
#include "ChasisNotFound.hpp"

using Container = std::list<Car>;
using fncreate = std::function<void(Container&)>;
using fnprice = std::function<Container(const Container&, float)>;
using fncat = std::function<std::optional<Container>(const Container&, Category)>;
using fnchasis = std::function<Car(const Container&, std::string)>;
using fnsize = std::function<std::list<float>(const Container&)>;
using fnpres = std::function<bool(const Container&)>;

extern fncreate CreateObject;
extern fnprice ByPrice;
extern fnchasis ByChasis;
extern fncat AntiGivenCategory;
extern fnsize rimsize;
extern fnpres CheckPres;

#endif // FUNCTIONALITIES_HPP
