#ifndef EMPTYSTRINGERROR_H
#define EMPTYSTRINGERROR_H


#include<stdexcept>

class EmptyStringError: public std::exception
{
private:
    std::string _msg;
public:
    EmptyStringError(const std::string& msg)
    : _msg{msg} {}

    ~EmptyStringError() {}

    EmptyStringError(const EmptyStringError&) = delete;
    EmptyStringError(EmptyStringError&&) = default;

    EmptyStringError& operator=(const EmptyStringError&) = delete;
    EmptyStringError& operator=(EmptyStringError&&) = default;
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg.c_str();
    };

    std::string msg() const { return _msg; }


    // FUnction to convert string into a character
};

#endif // EMPTYSTRINGERROR_H
