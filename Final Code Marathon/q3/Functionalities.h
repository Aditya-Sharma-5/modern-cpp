#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"ICEngine.h"
#include"EVEngine.h"
#include<list>
#include<variant>
#include<memory>
#include<optional>
#include<algorithm>
#include<numeric>
#include<thread>
#include<mutex>
#include<future>

using Iptr = std::shared_ptr<ICEngine>;
using Eptr = std::shared_ptr<EVEngine>;

using Vr = std::variant<Iptr , Eptr> ;

using DataContainer = std::list<Vr>;

//This function is used to create the objects on heap 
void CreateObject(DataContainer& data);

//this function returns the count of EV Engine  
std::optional<int> countOfEvEngine(const DataContainer& data , BatteryType type);

//This function return true or false based on the condition
std::optional<bool> IsAllInstancesOfICEngineAbove500HP(const DataContainer& data);


// This function returns the average engine maintainence cost 
std::optional<float> AverageAnnualEngineMaintenanceCost(const DataContainer& data);

std::optional<float>  EVEngineTorqueOfGivenID(const DataContainer& data , std::string id);



#endif // FUNCTIONALITIES_H
