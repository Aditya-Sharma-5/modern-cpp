#ifndef NOCONDITIONFOUND_H
#define NOCONDITIONFOUND_H


#include<stdexcept>
class NoConditionFound: public std::exception
{
private:
    std::string _msg;
public:
    NoConditionFound(const std::string& msg)
    : _msg{msg} {}

    ~NoConditionFound() {}

    NoConditionFound(const NoConditionFound&) = delete;
    NoConditionFound(NoConditionFound&&) = default;

    NoConditionFound& operator=(const NoConditionFound&) = delete;
    NoConditionFound& operator=(NoConditionFound&&) = default;
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg.c_str();
    };

    std::string msg() const { return _msg; }

};


#endif // NOCONDITIONFOUND_H
