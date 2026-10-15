#include "Functionalities.h"

void CreatObject(DataContainer &data)
{
    data.emplace_back(std::make_shared<Project>("1A" , 90000.0f , 12 , ProjectType::LONG_TERM , 125000 , "Aditya" , "Prashant"));
    data.emplace_back(std::make_shared<Project>("2A" , 85000.0f , 10 , ProjectType::LONG_TERM , 120000 , "Aditya" , "Aryan"));
    data.emplace_back(std::make_shared<Project>("3A" , 70000.0f , 8 , ProjectType::SHORT_TERM , 100000 , "Aditya" , "Vipin"));
    data.emplace_back(std::make_shared<Project>("4A" , 87000.0f , 9 , ProjectType::SHORT_TERM , 110000 , "Aditya" , "Kamran"));
    data.emplace_back(std::make_shared<Project>("5A" , 115000.0f , 14 , ProjectType::LONG_TERM ,135000 , "Aditya" , "Abhyanand"));
}

std::size_t CountMatchingTypes(const DataContainer &data, ProjectType type)
{
    if(data.empty()){
        throw EmptyContainerError("Invalid Data Container \n");
    }
    
    return std::count_if(
        data.begin(),
        data.end(),
        [&](const Sptr& ptr){return ptr.get()->projectType()==type;}
    );
}


float FindProjectBudgetById(const DataContainer &data, std::string id)
{
    if(data.empty()){
        throw EmptyContainerError("Invalid Data Container \n");
    }
    auto itr = data.end();
    auto result_itr = std::find_if(
        data.begin() , 
        itr,
        [&](const Sptr& ptr){return ptr->projectId() == id;}
    );
    if(result_itr == itr){
        throw NoConditionFound("No Condition MAtch \n");
    }
    return (*result_itr).get()->projectBudget();
}


void CheckCondition(const DataContainer &data)
{
    if(data.empty()){
        throw EmptyContainerError("Invalid Data Container \n");
    }

    std::cout<<"All of : "<<std::boolalpha<< std::all_of(
        data.begin(),
        data.end(),
        [](const Sptr& ptr){return ptr.get()->projectExpectedRevenue()>110000;}
    )<<"\n";

    std::cout<<"Any of : "<<std::boolalpha<< std::any_of(
        data.begin(),
        data.end(),
        [](const Sptr& ptr){return ptr.get()->projectExpectedRevenue()>110000;}
    )<<"\n";

    std::cout<<"None of : "<<std::boolalpha<< std::none_of(
        data.begin(),
        data.end(),
        [](const Sptr& ptr){return ptr.get()->projectExpectedRevenue()>110000;}
    )<<"\n";
}

DataContainer ReturnMatchingInstance(const DataContainer &data, Predicate fn)
{
    if(data.empty()){
        throw EmptyContainerError("Invalid Data Container \n");
    }
    DataContainer result ; 

    std::copy_if(
        data.begin(),
        data.end(),
        std::inserter(result , result.begin()),
        fn
    );

    if(result.empty()){
        throw NoConditionFound("No Condition Match \n");
    }
    return result;
}

DataContainer ReturnFIrstNInstance(const DataContainer &data, unsigned int N)
{
    if(data.empty()){
        throw EmptyContainerError("Invalid Data Container \n");
    }

    if(N>data.size() && N<=0){
        throw InvalidInput("Invalid N ");
    }
    DataContainer result ; 

    std::copy_n(
        data.begin(),
        N,
        std::inserter(result , result.begin())
    );

    return result;
}

DataContainer ReturnLastNInstance(const DataContainer &data, unsigned int N)
{
    if(data.empty()){
        throw EmptyContainerError("Invalid Data Container \n");
    }


    if(N>data.size() && N<=0){
        throw InvalidInput("Invalid N ");
    }
    DataContainer result ; 

    auto itr = data.begin();
    std::advance(itr , data.size() - N );

    std::copy_n(
        // data.rbegin(),   // only works in list 
        itr,                  // Otherwise only 
        N,
        std::inserter(result , result.begin())
    );

    return result;
}

float FIndAverageProjectBudget(const DataContainer &data)
{
    if(data.empty()){
        throw EmptyContainerError("Invalid Data Container \n");
    }

    float result = std::accumulate(
        data.begin(),
        data.end(),
        0.0f ,
        [](float answer_upto_this , const Sptr& ptr){ return answer_upto_this + ptr.get()->projectBudget();}
    );
    return result/data.size();
}

float FindTotalExpectedRevenueForGivenRange(const DataContainer &data, unsigned int start_idx, unsigned int end_idx)
{
    if(data.empty()){
        throw EmptyContainerError("Invalid Data Container \n");
    }

    if(start_idx<1 && start_idx>data.size() && end_idx>data.size() && end_idx<1){
        throw InvalidInput("Invalid Index Provided\n");
    }

    auto itr1 = data.begin();
    auto itr2 = data.begin();
    if(start_idx != 1 )
    {
        std::advance(
            itr1 , 
            start_idx -1
        );
    }
    std::advance(
        itr2 , 
        end_idx
    );

    if(start_idx == end_idx){
        return (*itr1).get()->projectExpectedRevenue();
    }

    float result = std::accumulate(
        itr1 , 
        itr2 , 
        0.0f,
        [](float answer_upto_this , const Sptr& ptr){ return answer_upto_this + ptr.get()->projectExpectedRevenue();}
    );

    return result;
}

TDSAmountContainer FIndTDSAmounts(const DataContainer &data)
{
    if(data.empty()){
        throw EmptyContainerError("Invalid Data Container \n");
    }
    TDSAmountContainer result;
 
    std::transform(
        data.begin(),
        data.end(),
        std::inserter(result, result.begin()),
        [](const Sptr& ptr) {
            return ptr->projectTeamCount() * ptr->projectBudget() * 0.1f;
        }
    );
 
    return result;
}
