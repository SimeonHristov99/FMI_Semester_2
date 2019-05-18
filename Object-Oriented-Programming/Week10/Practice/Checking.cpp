#include "pch.h"
#include "Checking.hpp"
#include <iostream>

Checking::Checking(const unsigned& _accountNumber, const char* _accountOwner, const double& _accountBalance, const double& _fee)
	: Account(_accountNumber, _accountOwner, _accountBalance),
	m_fee{_fee} {}

void Checking::credit(const unsigned& addMe)
{
	Account::credit(static_cast<double>(addMe - m_fee));
}

void Checking::debit(const unsigned& removeMe)
{
	Account::debit(static_cast<double>(removeMe + m_fee));
}

std::ostream& operator<<(std::ostream& out, const Checking& data)
{
	return out << data.m_accountNumber << " " << data.m_accountOwner << " -> " << data.getBalance();
}