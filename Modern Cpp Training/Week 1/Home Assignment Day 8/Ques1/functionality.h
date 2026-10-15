#ifndef FUNCTIONALITY_H
#define FUNCTIONALITY_H

#include"SavingAccount.h"
#include"CurrentAccount.h"
#include<vector>

using Container = std::vector<Account*>;

void createObject(Container& data);

void showObject(const Container& data);

bool AllSavingAccountHaveDebitCard(const Container& data);

#endif // FUNCTIONALITY_H
