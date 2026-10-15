#include<iostream>

class Magic{
    int _id;
    public:

        // A contructor marked as explicit can only be used for explicitely "initializing"
        // object AND NOT FOR TYPE CONVERSION.
        explicit Magic(int id){
            _id = id;
        }
        ~Magic() = default;

        friend std::ostream &operator<<(std::ostream &os, const Magic &rhs) {
            os << "_id: " << rhs._id;
            return os;
        }
};
void Demo(Magic obj){
    std::cout<<obj<<"\n";
}

int main(){
    Magic m1(10);
    Demo(m1);
    // Demo(10);     This will converts the integer value to object  , 
                     //but we used [expicit] keyword , so it gives error.
    return 0 ;
}