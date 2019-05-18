#pragma once
#include "Account.hpp"
#include <ostream>

class Savings : public Account
{
public:
	Savings(const unsigned& _accountNumber = 0, const char* _accountOwner = nullptr, const double& _accountBalance = 0, const double& _interestRate = 0);
	double calculateInterest() const;

	friend std::ostream& operator<<(std::ostream& out, const Savings& data);

private:
	double m_interestRate;
};