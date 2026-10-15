#ifndef INVALIDVALUEERROR_H
#define INVALIDVALUEERROR_H


#include<stdexcept>

class InvalidValueError: public std::exception
{
private:
    std::string _msg;
public:
    InvalidValueError(const std::string& msg)
    : _msg{msg} {}

    ~InvalidValueError() {}

    InvalidValueError(const InvalidValueError&) = delete;
    InvalidValueError(InvalidValueError&&) = default;

    InvalidValueError& operator=(const InvalidValueError&) = delete;
    InvalidValueError& operator=(InvalidValueError&&) = default;
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg.c_str();
    };

    std::string msg() const { return _msg; }


    // FUnction to convert string into a character
};

#endif // INVALIDVALUEERROR_H
