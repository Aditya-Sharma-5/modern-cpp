#ifndef INVALIDINPUT_H
#define INVALIDINPUT_H

#include<future>
#include<stdexcept>

class InvalidInput: public std::future_error
{
private:
    std::string _msg;
public:
    InvalidInput(const std::string& msg , std::future_errc code)
    :  std::future_error{code} , _msg{msg}{}

    ~InvalidInput() {}

    InvalidInput(const InvalidInput&) = delete;
    InvalidInput(InvalidInput&&) = default;

    InvalidInput& operator=(const InvalidInput&) = delete;
    InvalidInput& operator=(InvalidInput&&) = default;
    const char* what() const noexcept
    {
        return _msg.c_str();
    };
};

#endif // INVALIDINPUT_H
