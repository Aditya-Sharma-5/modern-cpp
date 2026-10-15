#ifndef INVALIDIDERROR_H
#define INVALIDIDERROR_H

#include<future>
#include<stdexcept>

class InvalidIdError: public std::future_error
{
private:
    std::string _msg;
public:
    InvalidIdError(const std::string& msg , std::future_errc code)
    :  std::future_error{code} , _msg{msg}{}

    ~InvalidIdError() {}

    InvalidIdError(const InvalidIdError&) = delete;
    InvalidIdError(InvalidIdError&&) = default;

    InvalidIdError& operator=(const InvalidIdError&) = delete;
    InvalidIdError& operator=(InvalidIdError&&) = default;
    const char* what() const noexcept
    {
        return _msg.c_str();
    };

    // Function to convert string into a character
};

#endif // INVALIDIDERROR_H
