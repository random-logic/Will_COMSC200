#ifndef SAVINGS_ACCOUNT_CPP
#define SAVINGS_ACCOUNT_CPP

#include "SavingsAccount.h"
using namespace std;

SavingsAccount::SavingsAccount(const double initBalance, const double interest) : Account(initBalance) {
	this->interest = interest;
}

double SavingsAccount::calculateInterest() {
	return this->interest * this->Account::balance;
}

ostream& operator<< (ostream& os, const SavingsAccount account) {
	os << account.balance;
	return os;
}

SavingsAccount operator+ (const double amount, const SavingsAccount other) {
	SavingsAccount account = other;
	account.credit(amount);
	return account;
}

SavingsAccount& SavingsAccount::operator+= (const double amount) {
	this->credit(amount);
	return *this;
}

SavingsAccount& SavingsAccount::operator-= (const double amount) {
	this->debit(amount);
	return *this;
}

SavingsAccount SavingsAccount::operator+ (const double amount) const {
	SavingsAccount account = *this;
	account.credit(amount);
	return account;
}

SavingsAccount SavingsAccount::operator- (const double amount) const {
	SavingsAccount account = *this;
	account.debit(amount);
	return account;
}

SavingsAccount& SavingsAccount::operator= (const SavingsAccount other) {
	this->balance = other.balance;
	return *this;
}

#endif //SAVINGS_ACCOUNT_CPP