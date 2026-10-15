#include"/home/kpit/Desktop/Modern Cpp Training /Week 4/Day 4/Project.h"
#include"/home/kpit/Desktop/Modern Cpp Training /Week 4/Day 4/Functionalities.h"
#include<unordered_set>

int main(){
    auto equals_fn = [](const Sptr& p1 , const Sptr& p2){
        return p1.get()->projectId() == p2.get()->projectId();
    };

    auto hash_fn = [](const Sptr & p1){
        return std::hash<std::string>()(p1->projectId());
    };

    std::shared_ptr<Project>p1 = std::make_shared<Project>("1A" , 90000.0f , 12 , ProjectType::LONG_TERM , 125000 , "Aditya" , "Prashant");
    std::shared_ptr<Project>p2 = std::make_shared<Project>("2A" , 85000.0f , 10 , ProjectType::LONG_TERM , 120000 , "Aditya" , "Aryan");
    std::shared_ptr<Project>p3 = std::make_shared<Project>("2A" , 85000.0f , 10 , ProjectType::LONG_TERM , 120000 , "Aditya" , "Aryan");

    std::unordered_set<Sptr , decltype(hash_fn) , decltype(equals_fn)> s({p1 , p2 , p3} , 0 , hash_fn , equals_fn);

    // for(Sptr ptr : s){
    //     std::cout<<*ptr<<"\n";
    // }

}

/*
    a) how to determine the uniqueness/duplicacy
    b) unordered_set is based on a hash table . In hash table , we need to apply hash 
*/