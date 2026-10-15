#include "functionalities.h"



void adaptor(StringContainer &data, FnContainer& fns)
{
    for(int i=0; i<fns.size(); i++){
        fns[i](data);
    }
}


FnType AllVowelsInWholeVector(StringContainer &data)
{
    if(data.empty()){
        throw;
    }

    std::string vowelsFound = "aeiouAEIOU";
    for(int i=0;i<data.size();i++){
        std::string str = data[i];

        for(int j=0;j<str.size();j++){
            if(vowelsFound.find(str[j]) != std::string::npos){
                std::cout << str[j] << std::endl;
            }
        }
    }
    return FnType();
}
