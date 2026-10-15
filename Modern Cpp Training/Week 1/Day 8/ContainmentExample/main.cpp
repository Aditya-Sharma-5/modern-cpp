#include"Functionalities.h"
void deallocate(Vehicle** data , unsigned int n){
    for(unsigned int i = 0; i<n; i++){
        delete data[i];
    }
    delete[] data;
}
int main(){
    unsigned int size = 3;
    Vehicle** arr = new Vehicle*[size];
    CreateObject(arr , size);

    std::cout<<IsTypeMatchingForAllVehicles(arr , size , VehicleType::PRIVATE)<<"\n";
    std::cout<<IsPermitIssueYearSameForAllVehicle(arr , size)<<"\n";
    std::cout<<"\n "<<CountMatchingInstances(arr , size , VehicleType::PRIVATE)<<"\n";
    int cnt = 1;
    Vehicle** result = new Vehicle*[cnt];
    result = LastNObjectPointer(arr , size , 1);

    delete[] result;
    deallocate(arr , size);
    // delete[] arr;
    return 0 ;
}