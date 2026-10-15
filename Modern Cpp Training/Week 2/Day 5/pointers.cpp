/* 
    ROW
    COLOMNS
    ROW * COLUMNS 
    input --> 
            2 
            3
            11
            12
            13
            14
            15
            16

        [ 11  12  13 ]
        [ 14  15  16 ]
*/
#include<iostream>

int main(){

    int row , col;
    std::cin>>row>>col;

    int size = row*col;

    
    int** arr = new int*[row];

    for(int i = 0;i<row;i++){
        arr[i] = new int[col];
    }

    for(int i = 0; i<row;i++){
        for(int j = 0;j<col;j++){
            int val ;
            std::cin>>val;
            arr[i][j] = val;
        }
    }

    std::cout<<"\nPrinting the array\n";

    for(int i = 0; i<row;i++){
        for(int j = 0;j<col;j++){
            std::cout<<arr[i][j]<<" ";
        }
        std::cout<<"\n";
    }

    for(int i = 0;i<row;i++){
        delete[] arr[i];
    }
    delete [] arr;

    return 0 ;
}