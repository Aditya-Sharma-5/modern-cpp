#ifndef INSTANCENOTFOUND_H
#define INSTANCENOTFOUND_H

#include <iostream>

class InstanceNotFound : public std::exception
{
private:
    std::string _msg;

public:
    InstanceNotFound() = default; // Default constructor
    InstanceNotFound(std::string msg) : _msg{msg} {}
    InstanceNotFound(const InstanceNotFound &) = default;           // Copy constructor
    InstanceNotFound &operator=(const InstanceNotFound &) = delete; // Copy assignment operator
    InstanceNotFound(InstanceNotFound &&) = delete;                 // Move constructor
    InstanceNotFound &operator=(InstanceNotFound &&) = delete;      // Move assignment operator
    ~InstanceNotFound() = default;                                    // Destructor
    std::string what()
    {
        return _msg;
    }
};

#endif // INSTANCENOTFOUND_H
