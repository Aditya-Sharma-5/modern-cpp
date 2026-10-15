#ifndef INVALIDINPUTERROR_H
#define INVALIDINPUTERROR_H


#include<future>
#include<stdexcept>

class InvalidInputError: public std::future_error
{
private:
    std::string _msg;
public:

    InvalidInputError(const std::string& msg , std::future_errc code)
    :  std::future_error{code} , _msg{msg}{}

    ~InvalidInputError() {}

    InvalidInputError(const InvalidInputError&) = delete;
    InvalidInputError(InvalidInputError&&) = default;

    InvalidInputError& operator=(const InvalidInputError&) = delete;
    InvalidInputError& operator=(InvalidInputError&&) = default;

    const char* what() const noexcept
    {
        return _msg.c_str();
    };
};


#endif // INVALIDINPUTERROR_H
