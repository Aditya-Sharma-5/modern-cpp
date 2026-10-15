#include"Functionalities.h"


void Display(const ResultContainer& data){
    for(const int& val : data){
        std::cout<<val<<" ";
    }
}

void Square(const DataContainer &data , ResultContainer& result)
{ 
    /*
        For every element "copied" from data into the variable val;
    */

   unsigned short k = 0;
   for(const int& val : data)
   {    
        // Artificial delay : to mimic or simulate real world situation, where delays happen naturally
        std::this_thread::sleep_for(std::chrono::seconds(1));
        result[k++] = val*val;
   }
}

void Cube(const DataContainer &data , ResultContainer& result)
{ 
    /*
        For every element "copied" from data into the variable val;
    */

   unsigned short k = 5;
   for(const int& val : data)
   {    
        // Artificial delay : to mimic or simulate real world situation, where delays happen naturally
        std::this_thread::sleep_for(std::chrono::seconds(1));
        result[k++] = val*val*val;
   }
}
