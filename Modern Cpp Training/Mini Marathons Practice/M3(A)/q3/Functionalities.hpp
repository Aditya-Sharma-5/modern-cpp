#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP

#include "ICECar.hpp"
#include "EvCar.hpp"
#include<memory>
#include<functional>
#include<variant>
#include<vector>
#include "EmptyContainer.hpp"
#include "Underflow.hpp"
#include "Oversized.hpp"
#include "NotEnough.hpp"

using EvPtr = std::shared_ptr<EvCar>;
using IcePtr = std::shared_ptr<ICECar>;
using Vtype = std::variant<IcePtr,EvPtr>;
using Container = std::vector<Vtype>;

using fncreate = std::function<void(Container&)>;
using fntype = std::function<Container(const Container&, std::string, int)>;
using fnice = std::function<bool(const Container&)>;

extern fncreate CreateObject;
extern fntype Ninstance;
extern fnice IsOne;

#endif // FUNCTIONALITIES_HPP
