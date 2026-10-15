#ifndef EMPTYCONTAINERERROR_H
#define EMPTYCONTAINERERROR_H

#include<future>
#include<stdexcept>

class EmptyContainerError: public std::future_error
{
private:
    std::string _msg;
public:
    EmptyContainerError(const std::string& msg , std::future_errc code)
    :  std::future_error{code} , _msg{msg}{}

    ~EmptyContainerError() {}

    EmptyContainerError(const EmptyContainerError&) = delete;
    EmptyContainerError(EmptyContainerError&&) = default;

    EmptyContainerError& operator=(const EmptyContainerError&) = delete;
    EmptyContainerError& operator=(EmptyContainerError&&) = default;
    const char* what() const noexcept
    {
        return _msg.c_str();
    };

    // Function to convert string into a character
};

#endif // EMPTYCONTAINERERROR_H
