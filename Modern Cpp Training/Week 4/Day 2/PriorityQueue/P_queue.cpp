/*
    It is a type of queue 
*/

#include<queue>
#include<vector>
#include<array>
#include<iostream>

int main(){
    std::array<int , 5>data {11 , -1 , 99 , 23 , 37};

    auto comp = [](int n1 , int n2){return n1<n2;};    // Max Heap
    // auto comp = [](int n1 , int n2){return n1>n2;};    // Min Heap

      // decltype gives you the datatype of the function
    std::priority_queue<int , std::vector<int> , decltype(comp)> pq(data.begin() , data.end() , comp);

    std::cout<<"Highest Priority Element : "<<pq.top()<<"\n";

    pq.pop();  // Remove the element at the top 
    pq.push(101); // Add the element 
}
// WHile calling the 