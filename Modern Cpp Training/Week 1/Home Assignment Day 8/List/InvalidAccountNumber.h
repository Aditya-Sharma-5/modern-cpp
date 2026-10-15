#ifndef INVALIDACCOUNTNUMBER_H
#define INVALIDACCOUNTNUMBER_H

#include<exception>
#include<iostream>

class InvalidAccountNumber: public std::exception
{
private:
    std::string _msg;
public:
    InvalidAccountNumber(const std::string& msg)
    : _msg{msg} {}

    ~InvalidAccountNumber() {}

    InvalidAccountNumber(const InvalidAccountNumber&) = delete;
    InvalidAccountNumber(InvalidAccountNumber&&) = default;

    InvalidAccountNumber& operator=(const InvalidAccountNumber&) = delete;
    InvalidAccountNumber& operator=(InvalidAccountNumber&&) = default;
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg.c_str();
    };

    std::string msg() const { return _msg; }


    // FUnction to convert string into a character
};

#endif // INVALIDACCOUNTNUMBER_H
