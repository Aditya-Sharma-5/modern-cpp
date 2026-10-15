#include"Functionalities.h"

#include<vector>
int main(){
    DataContainer _data;
    createObjects(_data);
    // showObjects(_data);


    std::cout<<static_cast<int>(FindDepartmentById(_data , "1b"));
    

    deleteObject(_data);



    return 0 ;



}