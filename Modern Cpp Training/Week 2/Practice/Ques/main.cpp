#include"check.h"

int main(){

    FnContainer _fns;

    _fns.push_back(FindAllVowels);
    _fns.push_back(DisplayLast3Char);
    _fns.push_back(FirstNonVowelCharacter);


    StringContainer data_string = {"Python", "C++", "Aditya", "Prashant"};

    // adaptor(data_string, fns);
    Adaptor(data_string , _fns);
    return 0 ;
}