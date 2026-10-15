#ifndef INSTANCENOTFOUND_H
#define INSTANCENOTFOUND_H

#include <iostream>

class InvalidIndex : public std::exception
{
private:
    std::string _msg;
    
public:
    InvalidIndex() = default; // Default constructor
    InvalidIndex(std::string msg):_msg{msg}{}
    InvalidIndex(const InvalidIndex&) = default; // Copy constructor
    InvalidIndex& operator=(const InvalidIndex&) = delete; // Copy assignment operator
    InvalidIndex(InvalidIndex&&) = delete; // Move constructor
    InvalidIndex& operator=(InvalidIndex&&) = delete; // Move assignment operator
    ~InvalidIndex() = default; // Destructor

    std::string what(){
        return _msg;
    }
};


#endif // INSTANCENOTFOUND_H
