/*
    MISRA C guidelines! 
*/

/* 
        Rule 1 : const keyword is always applied "first" to the token on the immediate left. If there is no 
                token on the left , apply it to the token on its immediate right.

        Rule 2 : *operator (pointer dereference / pointer symbol ) is a seperate token


        Rule 3 : A constant object can only called the function  marked as const.
*/


int main(){

    const int n1 = 10 ;


    int const n2 = 10;

    int n3 = 11; 
    const int n4 = 34; 


    // ptr is a pointer to a constant integer 
    const int* ptr = &n3 ;
    // *ptr = 1000;     // not allowed because ptr thinks integer value is constant

    ptr = &n4;          // Okay , beacause ptr is not constant , so it can change its value.


    // ptr is a constant poiter to an integer , means ptr cannot be changed , while n3 can change.
    int* const ptr1 = &n3;
    *ptr1 = 44;     // this will work now 
    // ptr1 = &n4 ;  this will gives error.


    // ptr2 is a constant pointer to a constant integer.
    const int* const ptr2 = &n3;
    // *ptr2 = 33;       //This will gives error
    // ptr2 = &n4;       //This will also error 
}
