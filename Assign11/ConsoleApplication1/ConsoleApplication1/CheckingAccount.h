#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account {
protected:
	double transactionFee;
public:
	CheckingAccount(const double, const double);
	void credit(const double);
	bool debit(const double);

	friend std::ostream& operator<< (std::ostream&, const CheckingAccount);
	friend CheckingAccount operator+ (const double, const CheckingAccount);
	CheckingAccount& operator+= (const double);
	CheckingAccount& operator-= (const double);
	CheckingAccount operator+ (const double) const;
	CheckingAccount operator- (const double) const;
	CheckingAccount& operator= (const CheckingAccount);
};

#endif //CHECKING_ACCOUNT_H