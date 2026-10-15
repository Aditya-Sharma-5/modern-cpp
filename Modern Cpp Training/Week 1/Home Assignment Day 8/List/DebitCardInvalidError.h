#ifndef DEBITCARDINVALIDERROR_H
#define DEBITCARDINVALIDERROR_H

#include<exception>
#include<iostream>

class DebitCardInvalidError: public std::exception
{
private:
    std::string _msg;
public:
    DebitCardInvalidError(const std::string& msg)
    : _msg{msg} {}

    ~DebitCardInvalidError() {}

    DebitCardInvalidError(const DebitCardInvalidError&) = delete;
    DebitCardInvalidError(DebitCardInvalidError&&) = default;

    DebitCardInvalidError& operator=(const DebitCardInvalidError&) = delete;
    DebitCardInvalidError& operator=(DebitCardInvalidError&&) = default;
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg.c_str();
    };

    std::string msg() const { return _msg; }


    // FUnction to convert string into a character
};

#endif // DEBITCARDINVALIDERROR_H
