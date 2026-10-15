#ifndef Oversized_HPP
#define Oversized_HPP

#include <future>
#include <cstring>

class Oversized : public std::future_error
{
private:
    char* m_msg;
public:
    Oversized(std::future_errc error_type, const char* msg) : std::future_error{error_type} {
        m_msg = new char[strlen(msg) + 1];
        std::strcpy(m_msg, msg);
    }

    Oversized(const Oversized&) = delete;
    Oversized(Oversized&&) noexcept = default;
    Oversized& operator=(const Oversized&) = delete;
    Oversized&& operator=(Oversized&&) = delete;

    ~Oversized() {
        delete[] m_msg;
    }

    const char* what() const noexcept override {
        return m_msg;
    }
};

#endif // Oversized_HPP