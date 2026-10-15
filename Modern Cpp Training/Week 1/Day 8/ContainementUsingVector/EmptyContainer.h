#ifndef IDNOTFOUNDERROR_H
#define IDNOTFOUNDERROR_H
#include<stdexcept>

class EmptyContainer: public std::exception
{
private:
    std::string _msg;
public:
    EmptyContainer(const std::string& msg)
    : _msg{msg} {}

    ~EmptyContainer() {}

    EmptyContainer(const EmptyContainer&) = delete;
    EmptyContainer(EmptyContainer&&) = default;

    EmptyContainer& operator=(const EmptyContainer&) = delete;
    EmptyContainer& operator=(EmptyContainer&&) = default;
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg.c_str();
    };

    std::string msg() const { return _msg; }


    // FUnction to convert string into a character
};




#endif // IDNOTFOUNDERROR_H
