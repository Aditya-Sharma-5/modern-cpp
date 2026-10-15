#ifndef INVALIDERROR_H
#define INVALIDERROR_H
#include<stdexcept>
class InvalidError: public std::exception
{
private:
    std::string _msg;
public:
    InvalidError(const std::string& msg)
    : _msg{msg} {}

    ~InvalidError() {}

    InvalidError(const InvalidError&) = delete;
    InvalidError(InvalidError&&) = default;

    InvalidError& operator=(const InvalidError&) = delete;
    InvalidError& operator=(InvalidError&&) = default;
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg.c_str();
    };

    std::string msg() const { return _msg; }


    // FUnction to convert string into a character
};

#endif // INVALIDERROR_H
