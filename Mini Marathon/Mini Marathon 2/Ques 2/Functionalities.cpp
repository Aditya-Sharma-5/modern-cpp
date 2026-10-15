#include "Functionalities.h"

void CreateObject(DataContainer &data)
{
    data[0] = Product("1A" , ProductType::PERFUME , 550.0f , "Wild Stone" , ProductOrigin::DOMESTIC);
    data[1] = Product("1B" , ProductType::APPLIANCE, 11000.0f , "Bajaj" , ProductOrigin::IMPORTED);
    data[2] = Product("1C" , ProductType::APPLIANCE, 5500.0f , "TOOFAN" , ProductOrigin::DOMESTIC);
    data[3] = Product("1D" , ProductType::PERFUME, 1100.0f , "ITAR" , ProductOrigin::IMPORTED);
    data[4] = Product("1E" , ProductType::FMCG, 2000.0f , "TATA" , ProductOrigin::DOMESTIC);
}


void Operation(const DataContainer& data, FnContainer &fns)
{   
    //Exception if data is empty
    if(data.empty()){
        throw EmptyContainerError("Empty Container!!!");
    }

    for(int i = 0 ; i<4; i++){
       fns[i](data);
  }
}


float FN_A(const DataContainer &data)
{
    //Exception if data is empty
    if(data.empty()){
        throw EmptyContainerError("Empty Container!!!");
    }

    float averagePrice = 0;
    float count = 0;

    for(Product obj : data)
    {
        if(obj.productType() == ProductType::PERFUME)
        {
            averagePrice += obj.productPrice();
            count++;
        }
    }

    std::cout<<(averagePrice/count)<<"\n";

    return averagePrice;
}


float FN_B(const DataContainer &data)
{

    //Exception if data is empty
    if(data.empty()){
        throw EmptyContainerError("Empty Container!!!");
    }

    int maintain_index = 0;
    float minimumProductPrice = data[0].productPrice();
    for(int i = 0 ; i<5 ; i++){
        if(data[i].productPrice()< minimumProductPrice){
            minimumProductPrice = data[i].productPrice();
            maintain_index = i;
        }
    }
    std::cout<<data[maintain_index].productTaxAmount()<<"\n";
    return data[maintain_index].productTaxAmount();
}


float FN_C(const DataContainer &data)
{

    //Exception if data is empty
    if(data.empty()){
        throw EmptyContainerError("Empty Container!!!");
    }

    float minimumProductPrice = data[0].productPrice();
    for(int i = 0 ; i<5 ; i++){
        if(data[i].productPrice()< minimumProductPrice){
            minimumProductPrice = data[i].productPrice();
        }
    }
    std::cout<<minimumProductPrice<<"\n";
    return minimumProductPrice;
}


float FN_D(const DataContainer &data)
{

    //Exception if data is empty
    if(data.empty()){
        throw EmptyContainerError("Empty Container!!!");
    }

    std::cout<<data[4].productPrice()<<"\n";
    return data[4].productPrice();
}


void DisplayDiscount(const DataContainer &data, std::function<float(Product &obj)>fn)
{

    //Exception if data is empty
    if(data.empty()){
        throw EmptyContainerError("Empty Container!!!");
    }

    for(Product obj : data){
        std::cout<<fn(obj)<<"\n";
    }

}



void show(const DataContainer &data)
{
    for(Product p: data){
        std::cout<<p<<"\n";
    }
}
