#ifndef DATAEMPTYEXCEPTION_H
#define DATAEMPTYEXCEPTION_H

#include <iostream>

class DataEmptyException : public std::exception
{
private:
    std::string _msg;

public:
    DataEmptyException() = default; // Default constructor
    DataEmptyException(std::string msg) : _msg{msg} {}
    DataEmptyException(const DataEmptyException &) = default;           // Copy constructor
    DataEmptyException &operator=(const DataEmptyException &) = delete; // Copy assignment operator
    DataEmptyException(DataEmptyException &&) = delete;                 // Move constructor
    DataEmptyException &operator=(DataEmptyException &&) = delete;      // Move assignment operator
    ~DataEmptyException() = default;                                    // Destructor
    std::string what()
    {
        return _msg;
    }
};

#endif // DATAEMPTYEXCEPTION_H
