#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "DataEmptyException.h"
#include "InvalidIndex.h"
#include "InstanceNotFound.h"
#include "ICeCar.h"
#include "EvCar.h"
#include <variant>
#include <memory>

using EVptr = std::shared_ptr<EvCar>;
using ICeptr = std::shared_ptr<ICeCar>;

using Vtype = std::variant<EVptr, ICeptr>;
using Container = std::vector<Vtype>;

void CreateObjects(Container &data);
Container ReturnMatchingInstances(Container &data);
void DisplayRegistrationFees(Container &data);
float ReturnAvgforPriceOftheEVCar(const Container &data);
int ReturnCountofEvCarWithSimilarEngineType(const Container &data, EPowerType ET);
std::string ReturnBrandNameBasedOntheidPassed(const Container &data, std::string id);
bool AllInstanceHavingPriceOver60000(const Container &data);
BatterType ReturnUnique(Container &data);
//void DisplayInstances(Container &data);
#endif // FUNCTIONALITIES_H
