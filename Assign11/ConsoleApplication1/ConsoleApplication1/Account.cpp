#ifndef ACCOUNT_CPP
#define ACCOUNT_CPP

#include "Account.h"
#include <iostream>
using namespace std;

Account::Account(const double initBalance) {
	this->balance = initBalance;
	if (this->balance < 0) {
		this->balance = 0;
		cout << "Initial balance was invalid." << endl;
	}
}

bool Account::debit(const double amount) {
	if (this->balance - amount < 0) {
		cout << "Debit amount exceeds balance." << endl;
		return false;
	}
	
	this->balance -= amount;
	return true;
}

void Account::credit(const double amount) {
	this->balance += amount;
}

double Account::getBalance() const {
	return balance;
}

ostream& operator<< (ostream& os, const Account account) {
	os << account.balance;
	return os;
}

Account operator+ (const double amount, const Account other) {
	Account account = other;
	account.credit(amount);
	return account;
}

Account& Account::operator+= (const double amount) {
	this->credit(amount);
	return *this;
}

Account& Account::operator-= (const double amount) {
	this->debit(amount);
	return *this;
}

Account Account::operator+ (const double amount) const {
	Account account = *this;
	account.credit(amount);
	return account;
}

Account Account::operator- (const double amount) const {
	Account account = *this;
	account.debit(amount);
	return account;
}

Account& Account::operator= (const Account other) {
	this->balance = other.balance;
	return *this;
}

#endif //ACCOUNT_CPP