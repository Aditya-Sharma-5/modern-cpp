#ifndef CHECK_H
#define CHECK_H

#include<vector>
#include<iostream>
#include<functional>

using StringContainer = std::vector<std::string>;

using FnType = std::function<void(const StringContainer&)>;

// void hbdhedb(const STringf)

using FnContainer = std::vector<FnType>;


void Adaptor(const StringContainer& data , FnContainer fns);

extern FnType FindAllVowels(const  StringContainer& data);

extern FnType DisplayLast3Char(const StringContainer& data);

extern FnType FirstNonVowelCharacter(const StringContainer& data);

#endif // CHECK_H
