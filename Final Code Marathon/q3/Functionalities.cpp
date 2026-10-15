#include "Functionalities.h"
std::mutex mt;

void CreateObject(DataContainer &data)
{
    data.push_back(std::make_shared<ICEngine>("1A" , 400 , 500 , EngineType::DIESEL , true));
    data.push_back(std::make_shared<ICEngine>("2A" , 550 , 680 , EngineType::PETROL , true));
    data.push_back(std::make_shared<EVEngine>("3A" , 510 , 610 , BatteryType::OTHER , true));
    data.push_back(std::make_shared<EVEngine>("4A" , 590 , 700 , BatteryType::LI_ION , true));
}

std::optional<int> countOfEvEngine(const DataContainer &data, BatteryType type)
{
    //Exception Case
    if(data.empty()){
        std::lock_guard<std::mutex>lk(mt);
        return std::nullopt;
    }

    int result = std::count_if(
        data.begin(), 
        data.end(),
        [&](Vr v){
            bool flag = false;
            if(std::holds_alternative<Eptr>(v)){
                const Eptr ptr = std::get<Eptr>(v);
                if( ptr.get()->engineBatteryPackType()== type){flag = true;}
            }
            return flag;
        }
    );
    if(result){
        std::lock_guard<std::mutex>lk(mt);
        return result;
    }
    std::lock_guard<std::mutex>lk(mt);
    return std::nullopt;
}

std::optional<bool>  IsAllInstancesOfICEngineAbove500HP(const DataContainer &data)
{
    //Exception Case
    if(data.empty()){
        std::lock_guard<std::mutex>lk(mt);
        return std::nullopt;
    }


    std::lock_guard<std::mutex>lk(mt);
    return std::all_of(
        data.begin(), 
        data.end(),
        [&](Vr v){bool flag = false;
            if(std::holds_alternative<Iptr>(v)){
                const Iptr ptr = std::get<Iptr>(v);
                if( ptr.get()->icEngineHorsepower()>500){
                    flag = true;
                }
            }
            return flag;
        });
}

std::optional<float>  AverageAnnualEngineMaintenanceCost(const DataContainer &data)
{
    //Exception Case
    if(data.empty()){
        std::lock_guard<std::mutex>lk(mt);
        return std::nullopt;
    }

    float result = std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [&](float val , Vr v){
            if(std::holds_alternative<Iptr>(v)){
                const Iptr ptr = std::get<Iptr>(v);
                return val += ptr.get()->AnnualEngineMaintenanceCost();
            }
            else{
                const Eptr ptr1 = std::get<Eptr>(v);
                return val += ptr1.get()->AnnualMaintainanceCost();
            }
        }
    );

    std::lock_guard<std::mutex>lk(mt);
    return result;
}

std::optional<float>  EVEngineTorqueOfGivenID(const DataContainer &data , std::string id)
{
    //Exception Case
    if(data.empty()){
        std::lock_guard<std::mutex>lk(mt);
        return std::nullopt;
    }

    auto itr = std::find_if(
        data.begin(), 
        data.end(),
        [&](Vr v){ 
                bool flag = false;
                if(std::holds_alternative<Eptr>(v)){
                const Eptr ptr = std::get<Eptr>(v);
                ptr.get()->evEngineId()== id;
                flag = true;

            } return flag; }
    );
    if(itr == data.end()){
        return std::nullopt;
    }
    const Eptr ptr = std::get<Eptr>(*itr);

    std::lock_guard<std::mutex>lk(mt);
    return ptr.get()->evEngineTorque();
}
