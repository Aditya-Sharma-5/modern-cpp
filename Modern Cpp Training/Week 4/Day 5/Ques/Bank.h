#ifndef BANK_H
#define BANK_H
#include"AccountType.h"
#include"ChequeBook.h"
#include"DebitCard.h"


class Bank
{
private:
    DebitCard* debitcard{nullptr};
    ChequeBook* cheque{nullptr};
    std::string name ; 
    long long ph_number;
    static long long acc_number;
    bool have_debit;
    bool have_cheque;
    AccountType accounttype;


public:

    Bank() = default;
    ~Bank()  = default;

    Bank(const Bank&) = delete;
    Bank(Bank&&) = delete;

    Bank& operator=(const Bank&) = delete;
    Bank& operator=(Bank&&) = delete;

    DebitCard* getDebitcard() const { return debitcard; }
    void setDebitcard(DebitCard* debitcard_) { debitcard = debitcard_; }

    ChequeBook* getCheque() const { return cheque; }
    void setCheque(ChequeBook* cheque_) { cheque = cheque_; }

    std::string getName() const { return name; }
    void setName(const std::string &name_) { name = name_; }

    long long phNumber() const { return ph_number; }
    void setPhNumber(long long phNumber) { ph_number = phNumber; }

    static long long accNumber() { return Bank::acc_number; }
    static void setAccNumber(long long accNumber) { Bank::acc_number = accNumber; }

    AccountType getAccounttype() const { return accounttype; }
    void setAccounttype(const AccountType &accounttype_) { accounttype = accounttype_; }

    bool haveCheque() const { return have_cheque; }
    void setHaveCheque(bool haveCheque) { have_cheque = haveCheque; }

    bool haveDebit() const { return have_debit; }
    void setHaveDebit(bool haveDebit) { have_debit = haveDebit; }

    void getInput();

    void ApplyDebitCard();

    void ApplyChequeBook(int leaves);
};

#endif // BANK_H
