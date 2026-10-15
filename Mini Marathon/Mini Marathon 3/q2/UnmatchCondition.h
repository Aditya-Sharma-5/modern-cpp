#ifndef UNMATCHCONDITION_H
#define UNMATCHCONDITION_H

#include<future>
#include<stdexcept>

class UnmatchCondition: public std::future_error
{
private:
    std::string _msg;
public:
    UnmatchCondition(const std::string& msg , std::future_errc code)
    :  std::future_error{code} , _msg{msg}{}

    ~UnmatchCondition() {}

    UnmatchCondition(const UnmatchCondition&) = delete;
    UnmatchCondition(UnmatchCondition&&) = default;

    UnmatchCondition& operator=(const UnmatchCondition&) = delete;
    UnmatchCondition& operator=(UnmatchCondition&&) = default;
    const char* what() const noexcept
    {
        return _msg.c_str();
    };
};


#endif // UNMATCHCONDITION_H
