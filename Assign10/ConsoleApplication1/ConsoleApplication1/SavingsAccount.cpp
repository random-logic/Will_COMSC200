#ifndef SAVINGS_ACCOUNT_CPP
#define SAVINGS_ACCOUNT_CPP

#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(double initBalance, double interest) : Account(initBalance) {
	this->interest = interest;
}

double SavingsAccount::calculateInterest() {
	return this->interest * this->Account::balance;
}

#endif //SAVINGS_ACCOUNT_CPP