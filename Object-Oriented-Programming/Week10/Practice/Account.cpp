#include "pch.h"
#include "Account.hpp"
#include <iostream>

void Account::copy(const Account& other)
{
	if (!other.m_accountOwner)
	{
		std::cout << "\n\n\t\tERROR: account copy() detected a nullptr!\n\n";
		return;
	}

	size_t len = strlen(other.m_accountOwner) + 1;
	m_accountOwner = new char[len];
	for (size_t i = 0; i <= len; i++)
	{
		m_accountOwner[i] = other.m_accountOwner[i];
	}

	m_accountNumber = other.m_accountNumber;
	m_accountBalance = other.m_accountBalance;
}

void Account::del()
{
	delete[] m_accountOwner;
}

Account::Account(const unsigned& _accountNumber, const char* _accountOwner, const double& _accountBalance)
{
	if (!_accountOwner)
	{
		_accountOwner = "N/A";
	}

	size_t len = strlen(_accountOwner) + 1;
	m_accountOwner = new char[len];
	for (size_t i = 0; i < len; i++)
	{
		m_accountOwner[i] = _accountOwner[i];
	}

	m_accountNumber = _accountNumber;
	m_accountBalance = _accountBalance;

}

Account::Account(const Account& other)
{
	copy(other);
}

Account& Account::operator=(const Account& other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}

	return *this;
}

Account::~Account()
{
	del();
}

void Account::credit(const double& addMe)
{
	m_accountBalance += addMe;
}

void Account::debit(const double& removeMe)
{
	m_accountBalance -= removeMe;
}

double Account::getBalance() const
{
	return m_accountBalance;
}

std::ostream& operator<<(std::ostream& out, const Account& data)
{
	return out << data.m_accountNumber << " " << data.m_accountOwner << " " << data.m_accountBalance;
}