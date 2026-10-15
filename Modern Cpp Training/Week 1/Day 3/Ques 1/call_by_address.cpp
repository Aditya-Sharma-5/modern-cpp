#include<iostream>

/*
    Pointer is always 8 bytes in 64Bit
    Pointer is always 4 bytes in 32Bit

*/








void Magic(int* ptr , int size){
    for(int i = 0;i<size;i++){
        std::cout<<ptr[i]<<"\n";
    }
}

int main(){
    int arr[5] = {1 ,2, 3, 5, 6};
    Magic(arr , 5);
    return 0 ;
}