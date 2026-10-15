#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Brand.h"
#include <memory>
#include <list>
#include <vector>
#include <mutex>
#include <iostream>
#include <future>

using BrandPtr = std::shared_ptr<Brand>;
using CarRef = std::reference_wrapper<Car>;
using CarList = std::vector<Car>;
using CarArray = std::vector<CarRef>;
using CarVec = std::vector<std::array<CarRef,3>>;
using BrandArray = std::vector<BrandPtr>;

void CreateObjects(BrandArray &b_data, CarList &c_data, CarVec &cars);

bool AllSeatCountAbove4(BrandArray &data);

std::vector<float> BrandRegisterCost(BrandArray &data);

void MaxPriceChassis(BrandArray &data);

std::vector<std::reference_wrapper<Car>> CarsAboveThresholdPrice(BrandArray &data, std::future<float> &price);

std::vector<std::reference_wrapper<Car>> CarsOfGivenType(BrandArray &data, BrandType type);
#endif // FUNCTIONALITIES_H
