#ifndef ACCOUNT_CPP
#define ACCOUNT_CPP

#include "Account.h"
#include <iostream>
using namespace std;

Account::Account(double initBalance) {
	this->balance = initBalance;
	if (this->balance < 0) {
		this->balance = 0;
		cout << "Initial balance was invalid." << endl;
	}
}

bool Account::debit(double amount) {
	if (this->balance - amount < 0) {
		cout << "Debit amount exceeds balance." << endl;
		return false;
	}
	
	this->balance -= amount;
	return true;
}

void Account::credit(double amount) {
	this->balance += amount;
}

double Account::getBalance() const {
	return balance;
}

#endif //ACCOUNT_CPP