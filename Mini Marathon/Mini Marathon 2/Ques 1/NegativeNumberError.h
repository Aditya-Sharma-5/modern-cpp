#ifndef NEGATIVENUMBERERROR_H
#define NEGATIVENUMBERERROR_H


#include<stdexcept>

class NegativeNumberError: public std::exception
{
private:
    std::string _msg;
public:
    NegativeNumberError(const std::string& msg)
    : _msg{msg} {}

    ~NegativeNumberError() {}

    NegativeNumberError(const NegativeNumberError&) = delete;
    NegativeNumberError(NegativeNumberError&&) = default;

    NegativeNumberError& operator=(const NegativeNumberError&) = delete;
    NegativeNumberError& operator=(NegativeNumberError&&) = default;
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg.c_str();
    };

    std::string msg() const { return _msg; }


    // FUnction to convert string into a character
};

#endif // NEGATIVENUMBERERROR_H
