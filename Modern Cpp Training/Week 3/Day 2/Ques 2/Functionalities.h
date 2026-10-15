#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<iostream>
#include<thread>
using DataContainer = std::array<int, 5>;
using ResultContainer = std::array<int , 10>;

void Square(const DataContainer& data , ResultContainer& result);
void Cube(const DataContainer& data , ResultContainer& result);

void Display(const ResultContainer& data);
#endif // FUNCTIONALITIES_H
