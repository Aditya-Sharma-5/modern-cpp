#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<vector>
#include<iostream>
#include<functional>
#include<math.h>
#include"EmptyContainerError.h"
#include"NegativeNumberError.h"
#include"EmptyStringError.h"

using IntContainer = std::vector<int>;
using StringContainer = std::vector<std::string>;

using PredicateInt = std::function<bool(int)>;
using PredicateString = std::function<bool(std::string)>;

using UnaryInt = std::function<int(int)>;
using UnaryFloat = std::function<float(int)>;
using UnaryString = std::function<char(std::string)>;


// Adaptor that accepts A  vector of int and predicate int function
void AdaptorInt(const IntContainer& data , PredicateInt fn);



// Adaptor that accepts A  vector of String and predicate String function
void AdaptorString(const StringContainer& data , PredicateString fn);

//Adaptor that accepts a vecor of int and unary function 
void AdaptorForTransformInt(IntContainer& data , UnaryInt fn);


void AdaptorForTransformIntoFloat(IntContainer& data , UnaryFloat fn);



//Adaptor that accepts a vecor of String and unary function 
void AdaptorForTransformString(StringContainer& data , UnaryString fn);


#endif // FUNCTIONALITIES_H
