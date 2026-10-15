#include"Functionalities.h"

int main(){

    Container _data ; 

    createObject(_data);

    try{
        DisplayResultOfCalculateBonus(_data , 2);
    }
    catch(const EmptyContainerError& ex){
        std::cerr<<ex.what()<<"\n";
    }
    catch(const InvalidValueError& ex){
        std::cerr<<ex.what()<<"\n";
    }


    try{
        DisplayDetailsOfLowestSalary(_data);
    }
    catch(const EmptyContainerError& ex){
        std::cerr<<ex.what()<<"\n";
    }


    try{
        DisplayResultOfCalculateBonus(_data , 2);
    }
    catch(const EmptyContainerError& ex){
        std::cerr<<ex.what()<<"\n";
    }
    catch(const InvalidValueError& ex){
        std::cerr<<ex.what()<<"\n";
    }


    try{
        std::vector<std::string> result =  DisplayLocationOfMatchedEmployee(_data , Grade::A);
        for(std::string s:result){
            std::cout<<s<<" ";
        }
        std::cout<<"\n";
    }
    catch(const EmptyContainerError& ex){
        std::cerr<<ex.what()<<"\n";
    }
    catch(const InvalidValueError& ex){
        std::cerr<<ex.what()<<"\n";
    }


    try{
        std::cout<<"The Project Name of given Employee Id : "<<ProjectNameWhoseIdIsMatched(_data , "3A")<<"\n";
    }
    catch(const EmptyContainerError& ex){
        std::cerr<<ex.what()<<"\n";
    }
    catch(const InvalidValueError& ex){
        std::cerr<<ex.what()<<"\n";
    }


    try{
        DeallocateMemory(_data);
    }
    catch(const EmptyContainerError& ex){
        std::cerr<<ex.what()<<"\n";
    }

    return 0 ;

}