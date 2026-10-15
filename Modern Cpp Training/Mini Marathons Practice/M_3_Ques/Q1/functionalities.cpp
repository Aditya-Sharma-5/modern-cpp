#include "functionalities.h"

std::optional<int> First3ElementsSum(const IntegerContainer &data)
{
    if (data.empty())
    {
        throw ExceptionMessage("EMPTY DATAAA!!");
    }
    if (data.size() < 3)
    {
        throw ExceptionMessage("Less than 3 elements in data");
    }

    int sum{0};
    for (int i = 0; i < 3; i++)
    {
        sum += data[i];
    }
    return sum;
}

std::optional<int> MinimumOfLast3Elements(const IntegerContainer &data)
{
    if (data.empty())
    {
        throw ExceptionMessage("EMPTY DATAAA!!");
    }
    if (data.size() < 3)
    {
        throw ExceptionMessage("Less than 3 elements in data");
    }
    int mini{data[data.size() - 1]};
    for (int i = data.size() - 2; i > data.size() - 4; i--)
    {
        if (data[i] < mini)
        {
            mini = data[i];
        }
    }
    return mini;
}

std::optional<IntegerContainer> PrimeNumbersInContainer(const IntegerContainer &data)
{
    if (data.empty())
    {
        throw ExceptionMessage("EMPTY DATAAA!!");
    }

    IntegerContainer result;
    for (const int &num : data)
    {
        bool prime{true};
        for (int i = 2; i < num; i++)
        {
            if (num % i == 0 || num<=1)
            {
                prime = false;
            }
        }
        if (prime)
        {
            result.emplace_back(num);
        }
    }
    return result;
}

std::optional<IntegerContainer> EvenNumberContainer(const IntegerContainer &data, std::function<bool(int)> fn)
{
    if (data.empty())
    {
        throw ExceptionMessage("EMPTY DATAAA!!");
    }
    IntegerContainer result;
    for (const int &num : data)
    {
        if (fn(num))
        {
            result.emplace_back(num);
        }
    }
    return result;
}

std::optional<std::string> MaxLengthString(StringContainer &data)
{
    if (data.empty())
    {
        throw ExceptionMessage("EMPTY DATAAA!!");
    }
    int len{data[0].size()};
    std::string answer{data[0]};

    for (std::string &st : data)
    {
        if (st.size() > len)
        {
            len = st.length();
            answer = st;
        }
    }
    return answer;
}

std::optional<CharContainer> ConsonantsContainer(StringContainer &data)
{
    if (data.empty())
    {
        throw ExceptionMessage("EMPTY DATAAA!!");
    }

    CharContainer result;

    for (std::string &st : data)
    {
        for (char& sti:st)
        {
            if (!(sti == 'a' || sti == 'e' || sti == 'i' || sti == 'o' || sti == 'u' ||
                  sti == 'A' || sti == 'E' || sti == 'I' || sti == 'O' || sti == 'U'))
            {
                result.emplace_back(sti);
            }
        }
    }
    return result;
}

void Display(const IntegerContainer &data)
{
    if (data.empty())
    {
        throw ExceptionMessage("EMPTY DATAAA!!");
    }

    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << "   ";
    }
    std::cout << "\n";
}
