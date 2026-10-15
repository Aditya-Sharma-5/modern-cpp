/* 
    1 million employees 
    [   101|102|103| 104 ...........]

    4 Million bytes of memory is required 

    OBJECTIVE : I want to create a new data container through which all employees id are still 
                accessible but the original data container is no longer required .
        Approch 1 : Copy and Delete ---> not optimized . 
                    a) The copy process is tedious!!!

        Approch 2 : Move Semantics  ==> Just change the memory address . 
            Ownership Transfer.
            The good part is that , we not move the data ---> no os permission need for more memory 

*/

#include<iostream>

void NewOwner(int* newPtr){
    
}
int main(){
    int* ptr = new int[25];

    NewOwner(ptr);
}