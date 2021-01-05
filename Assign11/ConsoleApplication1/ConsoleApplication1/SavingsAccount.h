#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
protected:
	double interest;

public:
	SavingsAccount(const double, const double);
	double calculateInterest();

	friend std::ostream& operator<< (std::ostream&, const SavingsAccount);
	friend SavingsAccount operator+ (const double, const SavingsAccount);
	SavingsAccount& operator+= (const double);
	SavingsAccount& operator-= (const double);
	SavingsAccount operator+ (const double) const;
	SavingsAccount operator- (const double) const;
	SavingsAccount& operator= (const SavingsAccount);
};

#endif //SAVINGS_ACCOUNT_H