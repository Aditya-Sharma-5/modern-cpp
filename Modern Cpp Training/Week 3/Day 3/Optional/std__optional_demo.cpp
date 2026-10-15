/*
    Based on input data and a mileage threshold , identify all cars that have mileage above the 
    given threshold 

    Return all such vehicles in a container

    e.g. : if threshold is 11 , find all vehicles with mileage more than 11 . Push them to a result 
           container , return the result.


    Scenario 1) : Input data container is empty/invalid
                    - throw an exception

    Scenario 2) : Inpur data is valid , threhold is also valid.Atleast one car has milegae above threshold
                - FInd the relevant car objects and store them in result
                - return result

    Scenario 3) : Inpur data is valid , threhold is also valid.NO car has milegae above threshold

                option1) return the empty container (very bad practice)
                option2) throw an exception
*/



// Optional : is like a enum that can have one of the 2 possible state 
                // 1) VALID DATA 
                // 2) nullopt (a special symbol to indicate NO VALID DATA)


#include<iostream>
#include<optional>
#include<list>


// FindOddNUmbers , MAY OR MAY NOT RETURN A LIST OF INTEGERS
std::optional<std::list<int> > FIndOddNUmber(std::list<int>& data){
    // scenario 1) empty input 
    if(data.empty()){
        throw std::runtime_error("Empty Data ");
    }

    std::list<int> result;

    for(int val: data){
        if(val % 2 != 0){
            result.push_back(val);
        }
    }

    // At the end of the loop , check the result for its size
    if(result.empty()){
        // Scenario 3: 
        return std::nullopt;
    }
    return result;
}

int main(){
    std::list<int> l1{1 , 2, 3, 4, 5};
    std::list<int> l2{6 , 2, 4};
    std::optional<std::list<int> >  result = FIndOddNUmber(l2);
     
    //  Now user checks whether optional has nullopt or valid data

    if(result.has_value()){
        std::list<int>valid_data = result.value();
        for(int val:valid_data){
            std::cout<<val<<" ";
        }
        std::cout<<"\n";
    }else{
        std::cerr<<"Function returned null!!";
    }
    return 0 ;
}