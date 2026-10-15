/* 
    lvalues are named variables which occupy memory (can be addressed)
    rvalues are temporary which do not have a name and memory , location neither
*/


/*
    Magic accepts one integer by value 
    Magic(10) ; rvalue will be accepted . 10 will be stored in the stack ,memory of Magic1
                10 will got memory into magic1 
    Magic(num) ; lvalue will be accepted . rvalue will be assigned and provided storage in Magic1 memory
                here 2 memory allocation is done


*/
void Magic1(int val){

}

/*
    Scenario 2 ) I want to accept only lvalue . I want to work on reference semantics but data 
                 has to be modifiable inside the function

*/
void Magic2(int& val);


/*
    Scenario 3) I want to accept only rvalue . I want to work on reference semantics but data 
                 has to be modifiable inside the function

*/
void Magic3(int&& val);


/*
        I want to use rvalue and lvalue both types.
        Tf type is movable than use rvalue semantics , if not use copy semantics 
        In any case , do not allow modification of received parameter
*/
void Magic4(const int& val);