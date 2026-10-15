#include"Functionalities.h"

int main(){
    Container _data ; 
    ThreadContainer _th;

    CreateObject(_data);

    CreateThread(_th , _data);
    JoinThread(_th);
}