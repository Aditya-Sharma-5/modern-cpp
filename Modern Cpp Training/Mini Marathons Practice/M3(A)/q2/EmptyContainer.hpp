#ifndef EmptyContainer_HPP
#define EmptyContainer_HPP

#include <future>
#include <cstring>

class EmptyContainer : public std::future_error
{
private:
    char* m_msg;
public:
    EmptyContainer(std::future_errc error_type, const char* msg) : std::future_error{error_type} {
        m_msg = new char[strlen(msg) + 1];
        std::strcpy(m_msg, msg);
    }

    EmptyContainer(const EmptyContainer&) = delete;
    EmptyContainer(EmptyContainer&&) noexcept = default;
    EmptyContainer& operator=(const EmptyContainer&) = delete;
    EmptyContainer&& operator=(EmptyContainer&&) = delete;

    ~EmptyContainer() {
        delete[] m_msg;
    }

    const char* what() const noexcept override {
        return m_msg;
    }
};

#endif // EmptyContainer_HPP