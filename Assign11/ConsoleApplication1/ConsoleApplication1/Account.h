#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <ostream>

class Account {
protected:
	double balance;
public:
	Account(const double);
	bool debit(const double);
	void credit(const double);
	double getBalance() const;

	friend std::ostream& operator<< (std::ostream&, const Account);
	friend Account operator+ (const double, const Account);
	Account& operator+= (const double);
	Account& operator-= (const double);
	Account operator+ (const double) const;
	Account operator- (const double) const;
	Account& operator= (const Account);
};

#endif //ACCOUNT_H