#ifndef IDNOTFOUNDERROR_H
#define IDNOTFOUNDERROR_H

/*
    Change 1) Parent Class will not be std::exception . Use std::future_exception instead
    Change 2) Every future exception is assumed to be caused by 1 of the 4 primary reasons.
                a)
*/
#include<future>
#include<stdexcept>

class IdNotFoundError: public std::future_error
{
private:
    std::string _msg;
public:
    IdNotFoundError(const std::string& msg , std::future_errc code)
    :  std::future_error{code} , _msg{msg}{}

    ~IdNotFoundError() {}

    IdNotFoundError(const IdNotFoundError&) = delete;
    IdNotFoundError(IdNotFoundError&&) = default;

    IdNotFoundError& operator=(const IdNotFoundError&) = delete;
    IdNotFoundError& operator=(IdNotFoundError&&) = default;
    const char* what() const noexcept
    {
        return _msg.c_str();
    };



    // Function to convert string into a character
};

#endif // IDNOTFOUNDERROR_H
