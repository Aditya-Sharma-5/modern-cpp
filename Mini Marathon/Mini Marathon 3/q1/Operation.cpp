#include "Operation.h"

std::shared_ptr<Operation> Operation::m_instance{nullptr};

void Operation::SumOfOdd()
{
    // Checking for the empty container
    if(m_integer_vector.empty())
    {
        std::lock_guard<std::mutex>lk(m_mt);
        std::cerr<<"Empty Data Container !!!!\n";
    }
    else
    {
        int total = 0;
        for(int i : m_integer_vector){
            if(i%2 == 1){
                total += i;
            }
        }
        std::lock_guard<std::mutex>lk(m_mt);
        std::cout<<"The Total of Odd Numbers : "<<total<<"\n";
    }
}


void Operation::FilterPrimeNumbers()
{
    // Checking for the empty container
    if(m_integer_vector.empty())
    {
        std::lock_guard<std::mutex>lk(m_mt);
        std::cerr<<"Empty Data Container !!!!\n";
    }
    else{
        for(int i : m_integer_vector)
        {
            if(i == 1 || i== 2)
            {
                std::lock_guard<std::mutex>lk(m_mt);
                std::cout<<i<<" ";
            }
            else
            {
                bool flag = false;
                for(int j = 2 ; j<i ; j++)
                {
                    if(i%j == 0)
                    {
                        flag = true ; 
                        break;
                    }
                }
                if(flag == false)
                {
                    std::lock_guard<std::mutex>lk(m_mt);
                    std::cout<<i<<" ";
                }
            }
        }
    }
}

void Operation::FindLargestString()
{
    // Checking for the empty container
    if(m_string_container.empty())
    {
        std::lock_guard<std::mutex>lk(m_mt);
        std::cerr<<"Empty Data Container !!!!\n";
    }

    else
    {
        int maximum_length = m_string_container[0].length();
        std::string ans = m_string_container[0];

        for(std::string s : m_string_container)
        {
            if(s.length()> maximum_length)
            {
                ans = s;
                maximum_length = s.length();
            }
        }

        std::lock_guard<std::mutex>lk(m_mt);
        std::cout<<"String with maximum Length : "<<ans<<"\n";

    }
}

void Operation::OnceOccuringNumbers()
{
    // Checking for the empty container
    if(m_integer_vector.empty())
    {
        std::lock_guard<std::mutex>lk(m_mt);
        std::cerr<<"Empty Data Container !!!!\n";
    }

    else
    {
        std::vector<int> check;

        for(int val : m_integer_vector)
        {
            int count = 0;
            for(int i = 0;i<m_integer_vector.size(); i++){
                if(val == m_integer_vector[i]){
                    count++;
                }
            }
            if(count == 1){
                check.push_back(val);
            }
        }
        //Print the values present in check vector

        std::lock_guard<std::mutex>lk(m_mt);
        std::cout<<"The Once Occuring Items : \n";
        for(int val : check)
        {
            std::cout<<val<<" ";
        }
        std::cout<<"\n\n";
    }
}

void Operation::DisplayFirstVowel()
{
    // Checking for the empty container
    if(m_string_container.empty())
    {
        std::lock_guard<std::mutex>lk(m_mt);
        std::cerr<<"Empty Data Container !!!!\n";
    }

    else
    {
        for(std::string str : m_string_container)
        {
            for(int i = 0 ; i<str.length(); i++)
            {
                if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O'|| str[i] == 'U' )
                {
                    std::lock_guard<std::mutex>lk(m_mt);
                    std::cout<<str[i]<<"\n";
                    break;
                }
            }
        }
    }
}

void Operation::MapThreads()
{
    m_thread_vector.emplace_back(std::thread(&Operation::DisplayFirstVowel , this));
    m_thread_vector.emplace_back(std::thread(&Operation::SumOfOdd , this));
    m_thread_vector.emplace_back(std::thread(&Operation::FilterPrimeNumbers , this));
    m_thread_vector.emplace_back(std::thread(&Operation::FindLargestString , this));
    m_thread_vector.emplace_back(std::thread(&Operation::OnceOccuringNumbers , this));
}

void Operation::JoinThreads()
{
    if(m_thread_vector.empty())
    {
        std::lock_guard<std::mutex>lk(m_mt);
        std::cerr<<"Empty Container!!!\n";
    }

    else
    {
        for(std::thread& th : m_thread_vector)
        {
            if(th.joinable()){
                th.join();
            }
        }
    }
}

std::shared_ptr<Operation> Operation::getInstance(IntegerContainer data1 , StringContainer data2)
{
    // If the object is already created 
    if(m_instance)
    {
        return m_instance;
    }
    //If not , then create the object
    else
    {
        m_instance.reset(new Operation(data1 , data2));
        return m_instance;
    }
}
