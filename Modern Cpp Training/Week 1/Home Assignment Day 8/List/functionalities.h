#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"SavingAccount.h"
#include"CurrentAccount.h"
#include"EmptyContainer.h"
#include"NoSavingAccountInstanceError.h"
#include"InvalidAccountNumber.h"
#include"DebitCardInvalidError.h"
#include<list>

using DataContainer = std::list<Account*>;

void createObject(DataContainer& data);

void showObject(const DataContainer& data);

bool IsAllSavingAccountHaveDebitCard(const DataContainer& data);

std::string AccountHavingMaximumBalance(const DataContainer& data);

DebitCard* FindDebitCard(const DataContainer& data , std::string acc_num);

void deleteObject(DataContainer& data);




#endif // FUNCTIONALITIES_H
