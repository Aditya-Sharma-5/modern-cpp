/*
    RESOURCES!!!!!!!!
        --> In a program whatever you need to acess from the system , is a resource

        --> memory , os level files [file handles!!] , network connections(ports) , database connection
        ls -lR /proc

*/

#include<iostream>


void Allocate(int* ptr){
    ptr = new int(); //4bytes
}
int main(){

    int* ptr = new int();  //4 bytes

    Allocate(ptr);

    delete ptr;
}