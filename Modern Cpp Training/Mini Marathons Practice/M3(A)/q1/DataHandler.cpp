#include "DataHandler.hpp"

DataHandler::DataHandler(std::vector<int> data)
:_data(data)
{}

void DataHandler::FilterData(const std::function<bool(int)> &fn)
{
    std::lock_guard<std::mutex> lg(mt);
    std::cout << "Filtering Data from The Given Lambda : \n";
    for(int it : _data){
        if(fn(it)){
            std::cout << it << " ";
        }
    }
    std::cout << "\n";
}

std::ostream &operator<<(std::ostream &os, const DataHandler &rhs) {
    os << "_data: \n" ;
    for(int it : rhs._data){
        os << it << ", ";
    }
    os << "\n _result: \n";
    for(int it : rhs._result){
        os << it << ", ";
    }
    os << '\n';
    return os;
}

void DataHandler::SumOfEven()
{
    std::lock_guard<std::mutex> lg(mt);
    int sum = 0;
    for(int it: _data){
        if(it%2 == 0){
            sum += it;
        }
    }
    std::cout << "Sum of all Even is : " << sum << "\n";
}

void DataHandler::ComputeSquare(const std::vector<int> &data)
{
    
    std::lock_guard<std::mutex> lg(mt);
    for(int it : data){
        _result.push_back(it*it);
    }
    // flag = true;
    // cv.notify_all();
}

void DataHandler::DisplayResult()
{
    std::unique_lock<std::mutex> ul(mt);
    cv.wait(ul, [&](){return flag;});
    std::cout << "Display the  _result container : \n";
    
    for(int it : _result){
        std::cout << it << ", ";
    }
    std::cout << "\n";
}

void DataHandler::Cube(const std::vector<int> &data)
{
    if(data.empty()){
        throw EmptyContainer(std::future_errc::no_state, "The Given Container is Empty");
    }
    std::lock_guard<std::mutex> lg(mt);
    std::cout << "Cube of Given Container is : \n";
    for(int it : data){
        std::cout << it * it * it << ", ";
    }
    std::cout << "\n";
}
