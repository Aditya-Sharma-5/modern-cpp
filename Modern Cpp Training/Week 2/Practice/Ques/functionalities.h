#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<iostream>
#include<functional>
#include<vector>

using StringContainer = std::vector<std::string>;

using FnType = std::function<void(StringContainer&)>;
using FnContainer = std::vector<FnType>;

void adaptor(StringContainer& data , FnContainer& );

extern FnType AllVowelsInWholeVector(StringContainer& data);

#endif // FUNCTIONALITIES_H
