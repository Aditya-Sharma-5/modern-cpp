#ifndef IDNOTFOUNDERROR_H
#define IDNOTFOUNDERROR_H



#include<stdexcept>

class IdNotFoundError: public std::exception
{
private:
    std::string _msg;
public:
    IdNotFoundError(const std::string& msg)
    : _msg{msg} {}

    ~IdNotFoundError() {}

    IdNotFoundError(const IdNotFoundError&) = delete;
    IdNotFoundError(IdNotFoundError&&) = default;

    IdNotFoundError& operator=(const IdNotFoundError&) = delete;
    IdNotFoundError& operator=(IdNotFoundError&&) = default;
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg.c_str();
    };

    std::string msg() const { return _msg; }


    // FUnction to convert string into a character
};

#endif // IDNOTFOUNDERROR_H
