#ifndef CHECKING_ACCOUNT_CPP
#define CHECKING_ACCOUNT_CPP

#include "CheckingAccount.h"
#include <iostream>
using namespace std;

CheckingAccount::CheckingAccount(double initBalance, double transactionFee) : Account(initBalance) {
	this->transactionFee = transactionFee;
}

void CheckingAccount::credit(double amount) {
	this->Account::balance += amount - transactionFee;
	cout << "$" << transactionFee << " transaction fee charged." << endl;
}

bool CheckingAccount::debit(double amount) {
	bool hasDebitBalance = this->Account::debit(amount);

	if (hasDebitBalance) {
		this->Account::balance -= transactionFee;
		cout << "$" << transactionFee << " transaction fee charged." << endl;
	}

	return hasDebitBalance;
}

#endif //CHECKING_ACCOUNT_CPP