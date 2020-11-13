#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
protected:
	double balance;
public:
	Account(double);
	bool debit(double);
	void credit(double);
	double getBalance() const;
};

#endif //ACCOUNT_H