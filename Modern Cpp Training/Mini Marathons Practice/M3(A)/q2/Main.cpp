#include "Functionalities.hpp"

int main(int argc, char const *argv[])
{
    
    Container obj;
    CreateObject(obj);

    try
    {
        //give instance whose price is high than given threshold --> running in async
        std::future<Container> a = std::async(ByPrice,std::ref(obj),342343);
        if(Container val = a.get(); !val.empty()){
            for(Car it : val){
                std::cout << it << "\n";
            }
        } 
        else{
            std::cout << "There is No Car instance which has higher price then Given Price\n";
        }

        //give a single instance --> which has same chasis number than the given one --> running in async
        std::future<Car> b = std::async(ByChasis, std::ref(obj), "1234");
        std::cout << b.get() << "\n";

        //given a instances which has diff category than givne --> running in async
        std::future<std::optional<Container>> c = std::async(AntiGivenCategory, std::ref(obj), Category::COMMUTE);
        if(std::optional<Container> noice = c.get();noice.has_value()){
            Container xx = noice.value();
            for(auto it : xx){
                std::cout << it << std::endl;
            }
        }
        else{
            std::cout << "There is No Car which has Different Catergory than Given\n";
        }

        //give a container of avg value --> from diff rimsize --> running in async
        std::future<std::list<float>> e = std::async(rimsize, std::ref(obj));
        std::list<float> val = e.get();
        for(float it : val){
                std::cout << it << "\n";
        }
        
        //give a predicate value --> where given pressure is need to be 30 or about --> running in async
        std::future<bool> d = std::async(CheckPres, std::ref(obj));
        if(d.get()){
            std::cout << "There is NO car which has low pressure than 30\n";
        }
        else{
            std::cout << "There is One or More Car which has low pressure than 30\n";
        }
    }
    catch(const std::future_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}
