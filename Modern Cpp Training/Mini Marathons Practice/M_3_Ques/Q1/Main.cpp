#include "functionalities.h"

int main()
{
    IntegerContainer data{1, 2, 3, 4, 5};
    StringContainer st_data{"C++", "Coding", "Demo"};
    auto fn = [](int num)
    { return num % 9 == 0; };
    try
    {
        auto fun1 = std::async(&First3ElementsSum, std::ref(data));

        auto fun2 = std::async(&MinimumOfLast3Elements, std::ref(data));

        auto fun3 = std::async(&PrimeNumbersInContainer, std::ref(data));

        auto fun4 = std::async(&EvenNumberContainer, std::ref(data), fn);

        auto fun5 = std::async(&MaxLengthString, std::ref(st_data));

        auto fun6 = std::async(&ConsonantsContainer, std::ref(st_data));

        std::optional<int> sum = fun1.get();
        std::optional<int> mini = fun2.get();
        std::optional<IntegerContainer> primenum = fun3.get();
        std::optional<IntegerContainer> evens = fun4.get();
        std::optional<std::string> maxst = fun5.get();
        std::optional<CharContainer> consonants = fun6.get();

        if (sum.has_value())
        {
            std::cout << "Sum : " << sum.value() << std::endl;
        }
        else
        {
            std::cout << "No sum\n";
        }
        if (mini.has_value())
        {
            std::cout << "Minimum element : " << mini.value() << std::endl;
        }
        else
        {
            std::cout << "No minimum\n";
        }
        if (primenum.has_value())
        {
            std::cout << "Prime Numbers : ";
            Display(primenum.value());
        }
        else
        {
            std::cout << "No prime numbers\n";
        }
        if (evens.has_value())
        {
            std::cout << "Predicate values : ";
            Display(evens.value());
        }
        else
        {
            std::cout << "No even numbers\n";
        }
        if (maxst.has_value())
        {
            std::cout << "Max Length string : " << maxst.value() << std::endl;
        }
        else
        {
            std::cout << "No string\n";
        }
        if (consonants.has_value())
        {
            std::cout << "Consonants : ";
            for (char &sti : consonants.value())
            {
                std::cout << sti << "   ";
            }
            std::cout << "\n";
        }
        else
        {
            std::cout << "No consonants\n";
        }
    }
    catch (ExceptionMessage &ex)
    {
        std::cout << ex.what() << std::endl;
    }
}