#include "Functionalities.h"

void CreateObject(Vehicle **arr, unsigned int N)
{
    for(unsigned int i = 0 ; i<N;i++ ){
        arr[i] = MakeObjectsWithInputData();
    }
}

Vehicle *MakeObjectsWithInputData()
{
    //Vehicle variable
    std::string v_id{""};
    std::string v_name{""};
    int type{1};

    //Permit variable
    std::string p_id{""};
    int16_t p_year{1};
    std::string p_rto {""}; 


    std::cin>>v_id;
    std::cin>>v_name;
    std::cin>>type;

    // std::cout << "vtype : " << type<<std::endl;
    VehicleType v_type{VehicleType::PRIVATE};
    if(type == 1)
        {v_type = VehicleType::PRIVATE;}
    else if(type == 2)
        {v_type = VehicleType::COMMERCIAL;}
    else
        {           //std::cout << "3"<<std::endl;
        v_type = VehicleType::SPECIAL_PURPOSE;}

    std::cin>>p_id;
    std::cin>>p_year;
    std::cin>>p_rto;

    return (new Vehicle(v_id , v_name , v_type , new 
    VehicleRegistrationPermit(p_id,p_year , p_rto)));


}

bool IsTypeMatchingForAllVehicles(Vehicle **arr, unsigned int size, VehicleType type)
{
    for(unsigned int i = 0; i<size;i++ ){
        if(arr[i]->vehicleType() != type){
            return false;
        }
    }
    return true;
}

bool IsPermitIssueYearSameForAllVehicle(Vehicle **arr, unsigned int size)
{
    int16_t check = arr[0]->permit()->permitIssueYear();
    for(unsigned int i = 1; i<size;i++ ){
        if(arr[i]->permit()->permitIssueYear() != check){
            return false;
        }
    }
    return true;
}

std::size_t CountMatchingInstances(Vehicle **arr, unsigned int size, VehicleType vtype)
{
    std::cout<<(int)vtype<<"\n";
    //   std::cout<<"\nhhhhii";
    size_t cnt = 0;
    for(unsigned int i = 0; i<size;i++ ){
        if(arr[i]->vehicleType() == vtype){
            cnt++;
        }
    }
    return cnt;
}

Vehicle **LastNObjectPointer(Vehicle **arr, unsigned int size, unsigned int N)
{
    unsigned int r = 0;
    Vehicle** result = new Vehicle*[N];
    for(unsigned int  i = size-N ;i<N;i++){
        result[r] = arr[i];
        r++;
    }
    return result;
}
