#ifndef DATAHANDLER_HPP
#define DATAHANDLER_HPP

#include<iostream>
#include<vector>
#include<functional>
#include<mutex>
#include<future>
#include "EmptyContainer.hpp"
#include<condition_variable>

class DataHandler
{
private:
    /* data */
    std::vector<int> _data;
    std::vector<int> _result;
    std::mutex mt;
    
    bool flag {false};
public:
    std::condition_variable cv;
    DataHandler(/* args */) = delete;
    DataHandler(const DataHandler&) = delete;
    DataHandler(DataHandler&&) = delete;
    DataHandler& operator=(const DataHandler&) = delete;
    DataHandler& operator=(DataHandler&&) = delete;

    DataHandler(std::vector<int> data);

    void FilterData(const std::function<bool(int)>& fn);

    void SumOfEven();

    void ComputeSquare(const std::vector<int>& data);

    void DisplayResult();

    void Cube(const std::vector<int> & data);

    ~DataHandler() {}

    std::vector<int> data() const { return _data; }

    std::vector<int> result() const { return _result; }

    // std::condition_variable getCv() const { return cv; }

    bool getFlag() const { return flag; }
    void setFlag(bool flag_) { flag = flag_; }
    

    friend std::ostream &operator<<(std::ostream &os, const DataHandler &rhs);
};

#endif // DATAHANDLER_HPP
