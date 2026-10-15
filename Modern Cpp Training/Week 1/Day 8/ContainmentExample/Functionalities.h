#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include"Vehicle.h"


/*
    function  must create n instance on the heap and store pointers to instances in a c-style array
    Input parameters: pointers to pointer to vehicle,unsinged int
    Expected output: object must get  create on the heap ,their pointers should be stores in the array
    return type : void
*/
void CreateObject(Vehicle** arr, unsigned int N);
 
 
/*
    input parameter none
    expected output: makes object on the heap and return pointers to the newly allocated object
    return type: Vehicles
*/
Vehicle* MakeObjectsWithInputData();



/*
    return true if all vehicle have vehicle_type matching with vehicletype value passed by user.
    Input parameter array of vehicle pointers
    expexted output :a boolen based on condition
    return type: bool
*/
bool IsTypeMatchingForAllVehicles(Vehicle** arr,unsigned int size, VehicleType type);
 


/*
    return true if all vehicle have same vehicle_issue_year matching with vehicletype value passed by user.
    Input parameter array of vehicle pointers
    expexted output :a boolen based on condition
    return type: bool
*/
bool IsPermitIssueYearSameForAllVehicle(Vehicle** arr , unsigned int size);



/*
    count instances with matching vehicletype
    input para: array of vehicle pointers,vehicletype
    expexted output: a boolen based on condition is true for all object or not
    return type unsigned long
*/
std::size_t CountMatchingInstances(Vehicle** arr,unsigned int size, VehicleType vtype);
 


/*
    return last n values from the input data container(last n pointers)
    input parameter: array of vehicle pointers
*/
Vehicle **LastNObjectPointer(Vehicle** arr,unsigned int size,   unsigned int N);

#endif // FUNCTIONALITIES_H
