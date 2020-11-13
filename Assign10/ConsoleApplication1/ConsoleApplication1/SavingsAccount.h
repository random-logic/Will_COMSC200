#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
private:
	double interest;

public:
	SavingsAccount(double, double);
	double calculateInterest();
};

#endif //SAVINGS_ACCOUNT_H