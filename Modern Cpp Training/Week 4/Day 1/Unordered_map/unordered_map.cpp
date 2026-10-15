#include<iostream>
#include<unordered_map>
#include"Employee.h"

/*
    Hint : TO add a new entry into the unordered map , we must make a pair of key 
*/

int main(){

    // By Raw pointers
    std::unordered_map<std::string ,Employee*>data{
        {"101" , new Employee(101 , "Aadi" , 22)}
    } ;
    data.emplace("102" , new Employee(102 , "aryan" , 22));
}

/*
    never call pair constructor manually 
    Hash is made up of pair 

*/

/*
    UNORDER MAP 

    PAIR    [ KEY  | VALUE ]
    {} whatever we write inside curly brackets , it has to be copied , no move is possible 

    initializer list :  list items copied into pair ---> pair inserted into map . 

    Copy constructor of pair is deleted .


    Variable x of type T has to bind with 
    a) lvalue but copied 
        --> T x
    a (ii)) lvalue but reference 
        --> T& x 


    Whenever you loop over the map , use the key as constant


    WHY THE ERROR ?? 
    1) Each entry in the hashtable is a pair 
            key , value

    2) Once inserted into the hashtable , the key is immutable because modifying the key means 
       rehashing which means recreating the table [i.e key is immutable/const]

    3)  -Wall means all warning will be pointed out including implicit conversion !!
        -Werror when used with -Wall will convert warning into errors!!

        
*/