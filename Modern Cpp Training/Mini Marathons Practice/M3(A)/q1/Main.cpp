// #include "Functionalities.hpp"
#include "DataHandler.hpp"

int main(int argc, char const *argv[])
{
    DataHandler obj({1,2,3,4,5});

    try
    {
        //this filter the data of with specific lamda function --> its running on async
        std::future<void> filter = std::async(&DataHandler::FilterData, &obj, [](int num)->bool{
    return num%4 == 0;
});
        filter.get();

        //this function display the sum of even --> its running on async thread
        std::future<void> even = std::async(&DataHandler::SumOfEven, &obj);
        even.get();

        //this function find the cube of given vector args --> running in async
        std::future<void> cube = std::async(&DataHandler::Cube, &obj, std::vector<int> {1,2,3,4,5});
        cube.get();


        //this function find the square and store it in result container --> running in thread
        std::thread t(&DataHandler::ComputeSquare, &obj,std::vector<int> {1,2,3,4,5});
         //this function display the result container --> running in thread
        std::thread t1(&DataHandler::DisplayResult, &obj);
        if(t.joinable()){
            t.join();
            
        }
        obj.setFlag(true);
        obj.cv.notify_one();
        
        t1.join();        
    }
    catch(const std::future_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    return 0;
}
