#include "pch.h"
#include "Savings.hpp"
#include <iostream>

Savings::Savings(const unsigned& _accountNumber, const char* _accountOwner, const double& _accountBalance, const double& _interestRate)
	: Account(_accountNumber, _accountOwner, _accountBalance),
	m_interestRate{_interestRate} {}

double Savings::calculateInterest() const
{
	return m_interestRate * getBalance();
}

std::ostream& operator<<(std::ostream& out, const Savings& data)
{
	return out << data.m_accountNumber << " " << data.m_accountOwner << " " << data.getBalance() << " " << data.calculateInterest();
}