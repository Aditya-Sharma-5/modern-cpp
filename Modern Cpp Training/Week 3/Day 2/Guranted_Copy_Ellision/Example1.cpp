#include<iostream>

/*
    Copy Ellision means -- not to copy /// ignored copy wherever possible
*/
class Employee
{

private:
    int _id;
    
public:
    Employee() = delete;
    ~Employee() = default;

    Employee(const Employee&) = delete;
    Employee(Employee&&) = default;

    Employee& operator=(const Employee&) = delete;
    Employee& operator=(Employee&&) = delete;

    Employee(int id){
        _id = id;
    }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
        os << "_id: " << rhs._id;
        return os;
    }
};

Employee CreateInstance(){
    return Employee(101);
}

int main(){
    Employee e1 = CreateInstance();
    std::cout<<e1<<"\n";
    return 0 ;
}

// create instance return  a  ----> rvalue by value

/*
    CPP developers , if interested to gain benefits of guranted copy ellision , must follow these rules: 
        -> Do not get in the way of the compiler 
            [Do not manually disable this feature]

        -> Do not write redundant statements in the body of the copy constructor becaue if your 
            programs depends on such statements being executed at a critical point , this may never 
            happen (since compiler will mercilessly , throughlessly , unpolitecally avoid copy ) 
*/