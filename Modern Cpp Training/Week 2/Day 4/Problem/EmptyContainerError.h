#ifndef EMPTYCONTAINERERROR_H
#define EMPTYCONTAINERERROR_H


#include<stdexcept>

class EmptyContainerError: public std::exception
{
private:
    std::string _msg;
public:
    EmptyContainerError(const std::string& msg)
    : _msg{msg} {}

    ~EmptyContainerError() {}

    EmptyContainerError(const EmptyContainerError&) = delete;
    EmptyContainerError(EmptyContainerError&&) = default;

    EmptyContainerError& operator=(const EmptyContainerError&) = delete;
    EmptyContainerError& operator=(EmptyContainerError&&) = default;
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg.c_str();
    };

    std::string msg() const { return _msg; }


    // FUnction to convert string into a character
};



#endif // EMPTYCONTAINERERROR_H
