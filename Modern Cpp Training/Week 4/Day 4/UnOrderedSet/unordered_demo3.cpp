#include"/home/kpit/Desktop/Modern Cpp Training /Week 4/Day 4/Project.h"
#include"/home/kpit/Desktop/Modern Cpp Training /Week 4/Day 4/Functionalities.h"
#include<unordered_set>

int main(){
    auto f1 = [](const Sptr& p1 , const Sptr& p2){
        return p1.get()->projectId() == p2.get()->projectId();
    };

    std::shared_ptr<Project>p1 = (std::make_shared<Project>("1A" , 90000.0f , 12 , ProjectType::LONG_TERM , 125000 , "Aditya" , "Prashant"));
    std::shared_ptr<Project>p2 = std::make_shared<Project>("2A" , 85000.0f , 10 , ProjectType::LONG_TERM , 120000 , "Aditya" , "Aryan");
    std::shared_ptr<Project>p3 = std::make_shared<Project>("2A" , 85000.0f , 10 , ProjectType::LONG_TERM , 120000 , "Aditya" , "Aryan");

    std::unordered_set<int> s1{p1.get()->projectTeamCount() , p2.get()->projectTeamCount() , p3.get()->projectTeamCount() };

    for(int p : s1){
        std::cout<<p<<"\n";
    }

}