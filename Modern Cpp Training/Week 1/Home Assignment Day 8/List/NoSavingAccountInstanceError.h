#ifndef NOSAVINGACCOUNTINSTANCEERROR_H
#define NOSAVINGACCOUNTINSTANCEERROR_H

#include<exception>
#include<iostream>

class NoSavingAccountInstanceError: public std::exception
{
private:
    std::string _msg;
public:
    NoSavingAccountInstanceError(const std::string& msg)
    : _msg{msg} {}

    ~NoSavingAccountInstanceError() {}

    NoSavingAccountInstanceError(const NoSavingAccountInstanceError&) = delete;
    NoSavingAccountInstanceError(NoSavingAccountInstanceError&&) = default;

    NoSavingAccountInstanceError& operator=(const NoSavingAccountInstanceError&) = delete;
    NoSavingAccountInstanceError& operator=(NoSavingAccountInstanceError&&) = default;
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg.c_str();
    };

    std::string msg() const { return _msg; }


    // FUnction to convert string into a character
};

#endif // NOSAVINGACCOUNTINSTANCEERROR_H
