#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<iostream>
#include<vector>
#include"Car.h"
#include<memory>

using Container = std::vector<Car*>;

// using Container = std::shared_ptr<Car>;

void createObject(Container& data);

void showData(const Container& data);

int findEngineHorsepower(const Container& data , std::string carId);

Container aboveEngineTorque(const Container& data );

Container matchCarType(const Container& data , CarType type );

float averageEngineHorsepower(const Container& data);

std::string findCarId(const Container& data);

float combinedPrice(const Container& data);

void deleteObject(Container& data);


#endif // FUNCTIONALITIES_H
