#include<iostream>
std::pair<int , std::string>original;

auto magic()-> std::pair<int , std::string>&{
    original.first = 27;
    original.second = "Aadi";
    return original;
}

int main(){
    auto [n1 , n2] = magic();
    return 0 ;
}