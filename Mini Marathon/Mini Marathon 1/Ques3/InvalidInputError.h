#ifndef INVALIDINPUTERROR_H
#define INVALIDINPUTERROR_H


#include<stdexcept>

class InvalidInputError: public std::exception
{
private:
    std::string _msg;
public:
    InvalidInputError(const std::string& msg)
    : _msg{msg} {}

    ~InvalidInputError() {}

    InvalidInputError(const InvalidInputError&) = delete;
    InvalidInputError(InvalidInputError&&) = default;

    InvalidInputError& operator=(const InvalidInputError&) = delete;
    InvalidInputError& operator=(InvalidInputError&&) = default;
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg.c_str();
    };

    std::string msg() const { return _msg; }


    // FUnction to convert string into a character
};


#endif // INVALIDINPUTERROR_H
