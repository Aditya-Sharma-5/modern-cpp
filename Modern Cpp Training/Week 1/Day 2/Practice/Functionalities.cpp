#include "Functionalities.h"



void createObject(Container& data)
{
    data.push_back(new Car("1a" , "Maruti" , CarType::SEDAN, new Engine("1ABC" , EngineType::ICT, 180 , 60) , 7200.0));
    data.push_back(new Car("1b" , "Mahindra" , CarType::SUV, new Engine("1XEDEBC" , EngineType::HYBRID, 200 , 87) , 18200.0));
    data.push_back(new Car("1c" , "Ford" , CarType::SPORTS, new Engine("1ABDDDED" , EngineType::ICT, 220 , 110) , 9200.0));
    data.push_back(new Car("1d" , "Tata" , CarType::HATCHBACK, new Engine("1ADEEDBC" , EngineType::HYBRID, 150 , 75) , 8200.0));
    data.push_back(new Car("1e" , "Honda" , CarType::SEDAN, new Engine("1ABCDEFG" , EngineType::ICT, 160 , 76) , 21200.0));
}

void showData(const Container& data)
{
    for(Car* ptr:data){
        std::cout<<*ptr<<" \n";
    }
}

int findEngineHorsepower(const Container& data, std::string carId)
{
    int matched_engineHorsepower = 0;
    for(Car* ptr: data){
        if(ptr->carId() == carId){
            matched_engineHorsepower = ptr->carEngine()->engineHorsepower();
            break;
        }
    }
    return matched_engineHorsepower;
}

Container aboveEngineTorque(const Container& data)
{
    Container _aboveEngineTorque;
    for(Car* ptr : data ){
        if(ptr->carEngine()->engineTorque()>80){
            _aboveEngineTorque.push_back(ptr);
        }
    }
    return _aboveEngineTorque;
}

Container matchCarType(const Container& data, CarType type)
{
    Container _matchedCarType;
    for(Car* ptr : data){
        if(ptr->carType()== type){
            _matchedCarType.push_back(ptr);
        }
    }
    return _matchedCarType;
}

float  averageEngineHorsepower(const Container& data)
{
    float _averageEngineHorsepower = 0.0f;
    int cnt = 0;
    for(Car* ptr : data){
        if(ptr->carEngine()->engineType() == EngineType::ICT && ptr->carPrice()>10000){
            _averageEngineHorsepower += ptr->carEngine()->engineHorsepower();
            cnt += 1;
        }
    }
    
    return (_averageEngineHorsepower/cnt);
}

std::string findCarId(const Container& data)
{
    float mini = data[0]->carPrice();
    std::string id = data[0]->carId();
    for(Car* ptr:data){
        if(ptr->carPrice()<mini){
            mini = ptr->carPrice();
            std::string id = ptr->carId();

        }
    }
    return id;
}

float combinedPrice(const Container& data)
{
    return (data[0])->carPrice() + (data[1])->carPrice();
}

void deleteObject(Container& data)
{
    for(Car* ptr: data){
        delete ptr->carEngine();
        delete ptr;
    }
}
