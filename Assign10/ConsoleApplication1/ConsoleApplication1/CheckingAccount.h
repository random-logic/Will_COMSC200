#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account {
private:
	double transactionFee;
public:
	CheckingAccount(double, double);
	void credit(double);
	bool debit(double);
};

#endif //CHECKING_ACCOUNT_H