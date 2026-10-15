#ifndef DATAEMPTY_H
#define DATAEMPTY_H

#include <iostream>
#include <future>

class DataEmpty : public std::future_error
{
private:
    std::string _msg;
    
public:
    DataEmpty() = default; // Default constructor
    DataEmpty(std::string msg,std::future_errc ec):_msg{msg},std::future_error(ec){}
    DataEmpty(const DataEmpty&) = default; // Copy constructor
    DataEmpty& operator=(const DataEmpty&) = delete; // Copy assignment operator
    DataEmpty(DataEmpty&&) = delete; // Move constructor
    DataEmpty& operator=(DataEmpty&&) = delete; // Move assignment operator
    ~DataEmpty() = default; // Destructor

    std::string what(){
        return _msg;
    }
};

#endif // DATAEMPTY_H
