#ifndef UNMATCHCONDITIONERROR_H
#define UNMATCHCONDITIONERROR_H


#include<future>
#include<stdexcept>

class UnmatchConditionError: public std::future_error
{
private:
    std::string _msg;
public:

    UnmatchConditionError(const std::string& msg , std::future_errc code)
    :  std::future_error{code} , _msg{msg}{}

    ~UnmatchConditionError() {}

    UnmatchConditionError(const UnmatchConditionError&) = delete;
    UnmatchConditionError(UnmatchConditionError&&) = default;

    UnmatchConditionError& operator=(const UnmatchConditionError&) = delete;
    UnmatchConditionError& operator=(UnmatchConditionError&&) = default;

    const char* what() const noexcept
    {
        return _msg.c_str();
    };
};


#endif // UNMATCHCONDITIONERROR_H
