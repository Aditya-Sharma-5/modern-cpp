#include "ChequeBook.h"

size_t ChequeBook::cheque_number{12345};

ChequeBook::ChequeBook(int leave)
: cheque_leaves{leave}
{
    cheque_number += cheque_leaves;
}

void ChequeBook::DisplayDetails()
{
    std::cout<<cheque_number<<"\n";
}
