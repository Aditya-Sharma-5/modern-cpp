#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <functional>
#include <vector>
#include <future>
#include <optional>
#include "ExceptionMessage.h"

using IntegerContainer = std::vector<int>;
using StringContainer = std::vector<std::string>;
using CharContainer =std::vector<char>;
/*
    function that returns sum of first 3 elements in container
*/
std::optional<int> First3ElementsSum(const IntegerContainer &data);

/*
    function that returns minimum of last 3 elements in container
*/
std::optional<int> MinimumOfLast3Elements(const IntegerContainer &data);

/*
    function that returns container of prime numbers in the given container
*/
std::optional<IntegerContainer> PrimeNumbersInContainer(const IntegerContainer &data);

/*
    function that return container of even number in the given container by taking 2 input of vector
    of integers & a lambda function
*/
std::optional<IntegerContainer> EvenNumberContainer(const IntegerContainer &data, std::function<bool(int)> fn);

/*
    function that returns string with maximum length amongst given vector of string
*/
std::optional<std::string> MaxLengthString(StringContainer &data);

/*
    function that returns container of consanants in amongst given string vector
*/
std::optional<CharContainer> ConsonantsContainer(StringContainer &data);

/*
    function to display elements of given container
*/
void Display(const IntegerContainer&data);

#endif // FUNCTIONALITIES_H
