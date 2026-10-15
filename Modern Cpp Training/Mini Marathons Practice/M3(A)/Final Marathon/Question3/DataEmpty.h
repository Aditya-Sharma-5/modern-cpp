#ifndef DATAEMPTY_H
#define DATAEMPTY_H

#include <iostream>
#include <future>

class DataEmpty : public std::exception
{
private:
    std::string _msg;
    
public:
    DataEmpty() = default; // Default constructor
    DataEmpty(std::string msg):_msg{msg}{}
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
