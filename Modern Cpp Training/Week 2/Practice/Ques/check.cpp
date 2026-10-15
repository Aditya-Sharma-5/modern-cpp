#include "check.h"

void Adaptor(const StringContainer &data, FnContainer fns)
{
    if(data.empty()){
        throw;
    }
    for(FnType fn : fns){
        fn(data);
        std::cout<<"\n";
    }
}


FnType FindAllVowels(const StringContainer &data)
{
    if(data.empty()){
        throw;
    }

    std::string compare = "aeiouAEIOU";

    for(std::string str : data)
    {
        // str = "aadi";
        for(int i = 0; i<str.size();i++)
        {
            if(compare.find(str[i]) != std::string::npos  )   // compare.find(a) 
            {
                std::cout<<str[i]<<" ";
            }
        }

        std::cout<<"\n";

    }
    return FnType();
}

FnType DisplayLast3Char(const StringContainer &data)
{
    if(data.empty()){
        throw;
    }

    for(std::string str : data)
    {
        if(str.size() <= 2){
            std::cout<<str;
        }
        else
        {
            for(int i = str.size() -3; i<str.size();i++)
            {
                std::cout<<str[i]<<" ";
            }
        }

        std::cout<<"\n";

    }

    return FnType();
}


FnType FirstNonVowelCharacter(const StringContainer &data)
{
    if(data.empty()){
        throw;
    }

    std::string  vowels = "aeiouAEIOU";

    for(std::string str : data)
    {
        for(int i = 0 ; i<str.size();i++)
        {
            if(vowels.find(str[i]) == std::string::npos)
            {
                std::cout<<str[i]<<"\n";
                break;
            }
        }
    }
    return FnType();
}
