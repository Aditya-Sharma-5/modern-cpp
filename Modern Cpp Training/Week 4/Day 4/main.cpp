#include"Functionalities.h"

int main(){
    DataContainer _data;
    CreatObject(_data);

    try
    {
        std::size_t match_count = CountMatchingTypes(_data , ProjectType::LONG_TERM);
        std::cout<<"The Count of Matching Types : "<<match_count<<"\n\n";
    }
    catch(const EmptyContainerError& obj){
        std::cerr<<obj.what()<<"\n";
    }


    try{
        float budget = FindProjectBudgetById(_data ,"2A");
        std::cout<<"The Project Budget : "<<budget <<"\n\n" ; 
    }
    catch(const EmptyContainerError& obj){
        std::cerr<<obj.what()<<"\n";
    }
    catch(const NoConditionFound& obj){
        std::cerr<<obj.what()<<"\n";
    }

    try{
        CheckCondition(_data);
        std::cout<<"\n\n";
    }
    catch(const EmptyContainerError& obj){
        std::cerr<<obj.what()<<"\n";
    }


    try{
        DataContainer  matching_data = ReturnMatchingInstance(_data , [](const Sptr& ptr){return ptr.get()->projectBudget() >110000;});
        std::cout<<"Instances that satisfied the Predicate function : \n";
        for(Sptr ptr : matching_data){
            std::cout<<*ptr<<"\n";
        }
        std::cout<<"\n\n";
    }
    catch(const EmptyContainerError& obj){
        std::cerr<<obj.what()<<"\n";
    }
    catch(const NoConditionFound& obj){
        std::cerr<<obj.what()<<"\n";
    }


    try
    {
        DataContainer firstN = ReturnFIrstNInstance(_data , 2);
        std::cout<<"The First N Instances are : \n";
        for(Sptr ptr : firstN){
            std::cout<<*ptr<<"\n";
        }
        std::cout<<"\n\n";
    }
    catch(const EmptyContainerError& obj){
        std::cerr<<obj.what()<<"\n";
    }
    catch(const InvalidInput& obj){
        std::cerr<<obj.what()<<"\n";
    }


    try
    {
        DataContainer lastN = ReturnLastNInstance(_data , 2);
        std::cout<<"The Last N Instances are : \n";
        for(Sptr ptr : lastN){
            std::cout<<*ptr<<"\n";
        }
        std::cout<<"\n\n";
    }
    catch(const EmptyContainerError& obj){
        std::cerr<<obj.what()<<"\n";
    }
    catch(const InvalidInput& obj){
        std::cerr<<obj.what()<<"\n";
    }



    try{
        float avg_project_budget = FIndAverageProjectBudget(_data);
        std::cout<<"The AVerage Project Budget : "<<avg_project_budget<<"\n\n";
    }
    catch(const EmptyContainerError& obj){
        std::cerr<<obj.what()<<"\n";
    }


    try{
        float TotalExpectedRevenue = FindTotalExpectedRevenueForGivenRange(_data , 2 , 4);
        std::cout<<"The Totall Expected Revenue are : "<<TotalExpectedRevenue<<"\n\n";
    }
    catch(const EmptyContainerError& obj){
        std::cerr<<obj.what()<<"\n";
    }
    catch(const InvalidInput& obj){
        std::cerr<<obj.what()<<"\n";
    }


    try{
        TDSAmountContainer TdsContainer = FIndTDSAmounts(_data);
        for(float tds : TdsContainer){
            std::cout<<"The TDS Amount of Instances : "<<tds<< "\n";
        }
    }
    catch(const EmptyContainerError& obj){
        std::cerr<<obj.what()<<"\n";
    }
}