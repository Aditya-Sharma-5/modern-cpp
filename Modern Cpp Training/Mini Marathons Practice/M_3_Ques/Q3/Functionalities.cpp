#include "Functionalities.h"

std::mutex mt;

void CreateObjects(BrandArray &b_data, CarList &c_data, CarVec &cars)
{
    c_data.emplace_back(Car(4, 1000.0f, 200.0f, ChassisType::CARBON_FIBER));
    c_data.emplace_back(Car(4, 2000.0f, 400.0f, ChassisType::STEEL));
    c_data.emplace_back(Car(4, 3000.0f, 600.0f, ChassisType::CARBON_FIBER));
    c_data.emplace_back(Car(4, 4000.0f, 700.0f, ChassisType::STEEL));
    c_data.emplace_back(Car(4, 5000.0f, 800.0f, ChassisType::CARBON_FIBER));
    c_data.emplace_back(Car(4, 6000.0f, 900.0f, ChassisType::STEEL));
    c_data.emplace_back(Car(4, 7000.0f, 200.0f, ChassisType::CARBON_FIBER));
    c_data.emplace_back(Car(4, 8000.0f, 300.0f, ChassisType::STEEL));
    c_data.emplace_back(Car(4, 9000.0f, 400.0f, ChassisType::CARBON_FIBER));

    std::cout<<"Created CarList"<<std::endl;

    auto itr = c_data.begin();
    std::vector<CarRef> car1;
    car1.emplace_back(*itr++);
    car1.emplace_back(*itr++);
    car1.emplace_back(*itr++);
    std::vector<CarRef> car2;
    car2.emplace_back(*itr++);
    car2.emplace_back(*itr++);
    car2.emplace_back(*itr++);
    std::vector<CarRef> car3;
    car3.emplace_back(*itr++);
    car3.emplace_back(*itr++);
    car3.emplace_back(*itr++);
    // for (int i = 0; i < 3; i++)
    // {
    //     std::cout<<i+1<<std::endl;
    //     for (int j = 0; i < 3; j++)
    //     {
    //         std::cout<<"a"<<std::endl;
    //         cars[i] = *itr++;
    //     }
    // }
    std::cout<<"Created CarVec"<<std::endl;

    b_data.emplace_back(std::make_shared<Brand>(BrandType::CONSUMER, "B101", car1));
    b_data.emplace_back(std::make_shared<Brand>(BrandType::SPECIAL_CONSUMER, "B102", car2));
    b_data.emplace_back(std::make_shared<Brand>(BrandType::TRANSPORT, "B103", car3));
}

bool AllSeatCountAbove4(BrandArray &data)
{
    for (BrandPtr &itr : data)
    {
        CarArray arr = itr->cars();
        for (int i = 0; i < 3; i++)
        {
            if (arr[i].get().seatCount() < 4)
            {
                return false;
            }
        }
    }
    return true;
}

std::vector<float> BrandRegisterCost(BrandArray &data)
{
    std::vector<float> res;
    for (BrandPtr &itr : data)
    {
        CarArray arr = itr->cars();
        float sum{0.0f};
        for (int i = 0; i < 3; i++)
        {
            sum += (arr[i].get().wheelBase() * arr[i].get().price() * 0.1);
        }
        res.emplace_back(sum);
    }
    return res;
}

void MaxPriceChassis(BrandArray &data)
{
    float mini{100000.0f};
    ChassisType ans;
    for (BrandPtr &itr : data)
    {
        CarArray arr = itr->cars();
        for (int i = 0; i < 3; i++)
        {
            if (arr[i].get().price() < mini)
            {
                mini = arr[i].get().price();
                ans = arr[i].get().chassis();
            }
        }
    }
    std::lock_guard<std::mutex> lt(mt);
    std::cout << "Chassis Type : " << static_cast<int>(ans) << std::endl;
}

std::vector<std::reference_wrapper<Car>> CarsAboveThresholdPrice(BrandArray &data, std::future<float> &price)
{
    std::vector<std::reference_wrapper<Car>> res;
    float thresh = price.get();
    for (BrandPtr &itr : data)
    {
        CarArray arr = itr->cars();
        for (int i = 0; i < 3; i++)
        {
            if (arr[i].get().price() > thresh)
            {
                res.emplace_back(arr[i]);
            }
        }
    }
    return res;
}

std::vector<std::reference_wrapper<Car>> CarsOfGivenType(BrandArray &data, BrandType type)
{
    std::vector<std::reference_wrapper<Car>> res;
    for (BrandPtr &itr : data)
    {
        if (itr->type() == type)
        {
            CarArray arr = itr->cars();
            for (int i = 0; i < 3; i++)
            {
                res.emplace_back(arr[i]);
            }
        }
    }
    return res;
}
