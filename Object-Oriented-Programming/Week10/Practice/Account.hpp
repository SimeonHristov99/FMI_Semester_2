#pragma once
#include <ostream>

class Account
{
public:
	Account(const unsigned& _accountNumber = 0, const char* _accountOwner = nullptr, const double& _accountBalance = 0);
	Account(const Account&);
	Account& operator=(const Account&);
	~Account();

	void credit(const double&);
	void debit(const double&);
	double getBalance() const;

	friend std::ostream& operator<<(std::ostream& out, const Account& data);

protected:
	unsigned m_accountNumber;
	char* m_accountOwner;

private:
	double m_accountBalance;

	void copy(const Account&);
	void del();
};