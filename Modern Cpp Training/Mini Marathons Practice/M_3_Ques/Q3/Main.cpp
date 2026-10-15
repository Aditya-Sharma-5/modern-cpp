#include "Functionalities.h"

int main()
{
    std::promise<float> pr;
    std::future<float> ft = pr.get_future();
    BrandArray data;
    CarList clist;
    CarVec carray;
    CreateObjects(data, clist, carray);
    float price;

    auto fun1 = std::async(&AllSeatCountAbove4, std::ref(data));

    auto fun2 = std::async(&BrandRegisterCost, std::ref(data));

    auto fun3 = std::async(&MaxPriceChassis, std::ref(data));

    auto fun4 = std::async(&CarsAboveThresholdPrice, std::ref(data), std::ref(ft));

    auto fun5 = std::async(&CarsOfGivenType, std::ref(data), BrandType::CONSUMER);

    std::cout << "Enter price : ";
    std::cin >> price;
    pr.set_value(price);

    bool ans1 = AllSeatCountAbove4(data);
    std::vector<float> ans2 = fun2.get();
    std::vector<std::reference_wrapper<Car>> ans4 = fun4.get();
    std::vector<std::reference_wrapper<Car>> ans5 = fun5.get();

    std::cout << "AllSeatCountAbove4 : " << std::boolalpha << ans1 << std::endl;
}