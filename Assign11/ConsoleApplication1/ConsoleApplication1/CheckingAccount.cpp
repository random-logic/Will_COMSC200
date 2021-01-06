#ifndef CHECKING_ACCOUNT_CPP
#define CHECKING_ACCOUNT_CPP

#include "CheckingAccount.h"
#include <iostream>
using namespace std;

CheckingAccount::CheckingAccount(const double initBalance, const double transactionFee) : Account(initBalance) {
	this->transactionFee = transactionFee;
}

void CheckingAccount::credit(const double amount) {
	this->Account::balance += amount - transactionFee;
	cout << "$" << transactionFee << " transaction fee charged." << endl;
}

bool CheckingAccount::debit(const double amount) {
	bool hasDebitBalance = this->Account::debit(amount);

	if (hasDebitBalance) {
		this->Account::balance -= transactionFee;
		cout << "$" << transactionFee << " transaction fee charged." << endl;
	}

	return hasDebitBalance;
}

ostream& operator<< (ostream& os, const CheckingAccount account) {
	os << account.balance;
	return os;
}

CheckingAccount operator+ (const double amount, const CheckingAccount other) {
	CheckingAccount account = other;
	account.credit(amount);
	return account;
}

CheckingAccount& CheckingAccount::operator+= (const double amount) {
	this->credit(amount);
	return *this;
}

CheckingAccount& CheckingAccount::operator-= (const double amount) {
	this->debit(amount);
	return *this;
}

CheckingAccount CheckingAccount::operator+ (const double amount) const {
	CheckingAccount account = *this;
	account.credit(amount);
	return account;
}

CheckingAccount CheckingAccount::operator- (const double amount) const {
	CheckingAccount account = *this;
	account.debit(amount);
	return account;
}

CheckingAccount& CheckingAccount::operator= (const CheckingAccount other) {
	this->balance = other.balance;
	return *this;
}

#endif //CHECKING_ACCOUNT_CPP