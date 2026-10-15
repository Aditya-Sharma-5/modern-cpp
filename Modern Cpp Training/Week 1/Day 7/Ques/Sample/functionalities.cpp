#include "functionalities.h"

/*
    Note : Validation is not valid in this statement 
    [ c101 | City   | SEDAN     | 140000.0f  ]
    [ c102 | WagonR | HATCHBACK | 60000.0f   ]
    [ c103 | Dzire  | SEDAN     | 900000.0f  ]
    [ c104 | seltos | SUV       | 2200000.0f ]
*/


void createObject(DataContainer &data)
{

    // Data at index 0 should now be assigned a new temporary object

    // This gives error as move is deleted
    // data[0] = CarUnit("101" , "City" , 1400000.0f , CarType::SEDAN);


    // This gives error as copy is deleted 
    // CarUnit c1("101" , "City" , 1400000.0f , CarType::SEDAN);
    // data[0] = c1;

    // So we default the move assignment operator 
    data[0] = CarUnit("101" , "City" , 1400000.0f , CarType::SEDAN);
    data[1] = CarUnit("102" , "WagonR",600000.0f , CarType::HATCHBACK);
    data[2] = CarUnit("103" , "Dzire" , 900000.0f , CarType::SEDAN);
    data[3] = CarUnit("104" , "Seltos" , 2400000.0f , CarType::SUV);

}



/*
    Scenario 1) : N is valid , data is valid.
    Scenario 2) : N is invalid (N<=0 , N>size)
    Scenario 3) : N is valid    IdNotFoundError(const std::string& msg)
    : _msg{msg} {}

    ~IdNotFoundError() {}

    IdNotFoundError(const IdNotFoundError&) = delete;
    IdNotFoundError(IdNotFoundError&&) = default;

    IdNotFoundError& operator=(const IdNotFoundError&) = delete;
    IdNotFoundError& operator=(IdNotFoundError&&) = default;
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg.c_str();
    };

    std::string msg() const { return _msg; }


    // FUnction to convert string into a character
}; , data is invalid   ===> this is not apply for array 


    To make a custom exception :
        1) : CHoose a context specific Name 
        2) : Create a class with the new name . This must be a derived class from either 
                std::exception(synchornous code/regular execution)
                            or
                std::future_error(async code)
        3) : Create an exception object based on string or char* input parameters
        4) : Overwrite the what() method to complete the code
*/
CarUnit *FetchNInstances(const DataContainer &data, unsigned int N)
{
    if(N <=0 || N > data.size()){
        throw InvalidError("N is invalid , cannot perform operations");
    }

    CarUnit* result = new CarUnit[N];  // array got default initialized 
    //result has N default objects

    unsigned int i = 0;
    for(const CarUnit& c : data){
        result[i++] = c;
        if(i == N){
            break;
        }
    }

    return result;
}


/*
    Scenario 1) : Id is found 
    Scenario 2) : Searching fails as ID is not found 
*/
CarType FindCarTypeById(const DataContainer &data, const std::string &id)
{
    for(const CarUnit& c : data){
        if(c.id() == id){
            return c.carType();
        }
    }
    throw IdNotFoundError("Id not found !!");
}


// Scenario 1) : Average gets calculated
float AveragePrice(const DataContainer &data)
{
    float total{0.0f};
    for(const CarUnit& c:data){
        total += c.price();
    }
    return total/data.size();
}


// 
std::string MaxCarModelName(const DataContainer &data)
{
    float current_max = data[0].price();
    std::string max_model_name = data[0].modelName();


    for(const CarUnit& c : data){
        if(current_max<c.price()){
            current_max = c.price();
            max_model_name = c.modelName();
        }
    }
    return max_model_name;
}
