#ifndef CHEQUEBOOK_H
#define CHEQUEBOOK_H
#include<iostream>
#include<array>

class ChequeBook
{
private:
    static size_t cheque_number ;
    int cheque_leaves;


public:
    ChequeBook() = delete;
    ~ChequeBook()  = default;

    ChequeBook(const ChequeBook&) = delete;
    ChequeBook(ChequeBook&&) = delete;

    ChequeBook& operator=(const ChequeBook&) = delete;
    ChequeBook& operator=(ChequeBook&&) = delete;

    ChequeBook(int leave);

    void DisplayDetails();




};


#endif // CHEQUEBOOK_H
