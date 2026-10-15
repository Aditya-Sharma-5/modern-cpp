#include"Product.h"
#include"EmptyContainerError.h"

#include<functional>
#include<array>

using DataContainer = std::array<Product , 5>;

using FnType = std::function<float(const Product& )>;
using FnContainer = std::array< FnType , 4 >;


/*
    Function is used to create objects on stack in the array container
*/
void CreateObject(DataContainer& data );

/*
    High - Order Function that accepts container of Product's Objects
    and Function Container.
*/
void Operation(const DataContainer& data , FnContainer& fns);




// Function to find and return the average price for all products having ProductType Perfume
extern float FN_A(const DataContainer& data);
// extern float FN_A;


//This function is used to return the product tax amount of the minimum product price
extern float FN_B(const DataContainer& data);


//This function is used to return the minimum product price
extern float FN_C(const DataContainer& data);



//This function is used to return the product price of the last Insatance
extern float FN_D(const DataContainer& data);


void DisplayDiscount(const DataContainer& data , std::function<float(Product& obj)>fn);



void show(const DataContainer& data);
