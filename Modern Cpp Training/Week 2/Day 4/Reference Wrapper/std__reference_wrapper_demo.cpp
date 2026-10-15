#include<iostream>
#include<functional>

/*
    1) Modern Cpp likes to store things in boxes[wrappers]
        // Wrapper is a real "objects" . So it can be treated like a "value"
*/
int main(){
    int n1 = 10;
    int &ref = n1; //ref is an alternative name for n1

    // DOES ref exists in RAM ? NO
    // DOES ref occupy memory ? NO
    // IF something does not memory , does not physically exists in memory , can you make container of such 
    //  things ?
}