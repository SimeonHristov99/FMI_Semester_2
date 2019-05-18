#pragma once
#include "Account.hpp"
#include <ostream>

class Checking: public Account
{
public:
	Checking(const unsigned& _accountNumber = 0, const char* _accountOwner = nullptr, const double& _accountBalance = 0, const double& _fee = 0);
	void credit(const unsigned&);
	void debit(const unsigned&);

	friend std::ostream& operator<<(std::ostream& out, const Checking& data);

private:
	double m_fee;
};