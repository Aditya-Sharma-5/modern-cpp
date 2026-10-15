#ifndef INVALIDINPUT_H
#define INVALIDINPUT_H


#include<stdexcept>
class InvalidInput: public std::exception
{
private:
    std::string _msg;
public:
    InvalidInput(const std::string& msg)
    : _msg{msg} {}

    ~InvalidInput() {}

    InvalidInput(const InvalidInput&) = delete;
    InvalidInput(InvalidInput&&) = default;

    InvalidInput& operator=(const InvalidInput&) = delete;
    InvalidInput& operator=(InvalidInput&&) = default;

    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg.c_str();
    };
    std::string msg() const { return _msg; }
};


#endif // INVALIDINPUT_H
