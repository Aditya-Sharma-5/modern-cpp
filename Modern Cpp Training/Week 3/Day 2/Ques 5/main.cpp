#include"Operation.h"

int main(){
    Operation* m_obj = Operation::CreateObjects(1100);
    (*m_obj)();   // Acts like a run function
    delete m_obj;
}