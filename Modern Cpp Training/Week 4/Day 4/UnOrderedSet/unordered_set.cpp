#include<unordered_set>
#include<iostream>
#include<array>



/*
    This is a hash table where only key are present 
    : Elements in the set are constant , you cannot modify them 
*/
int main(){
    // 1 , 2, 3, 4, 5, 6
    std::array<int , 8>data{1 , 5 , 6, 3,2,1,5,6};

    std::unordered_set<int> s1(data.begin() , data.end());

    for(const int val : s1){
        std::cout<<val<<"\n";
    }
    std::cout<<"\n";

    //Initializer List 
    std::unordered_set<int> s2{1,2,3,5,3,2,55,1,4,6};

    for(const int val : s2){
        std::cout<<val<<"\n";
    }
    std::cout<<"\n";


    //copy set 

    std::unordered_set<int>s3(s2);

}