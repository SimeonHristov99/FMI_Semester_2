#include "pch.h"
#include <iostream>
const size_t MAX_SIZE = 100;

size_t getSizeStr(char str[])
{
	if (str[0] == '\0')
		return 1; //intentional

	return 1 + getSizeStr(str + 1);
}

bool eqStr(const char str0[], const char str1[])
{
	if (str0[0] == '\0' && str1[0] == '\0')
		return true;

	if (str0[0] != str1[0])
		return false;

	return eqStr(str0 + 1, str1 + 1);
}

class BankAccount
{
private:
	char* name;
	char* accountNumb;
	double balance;

	void del()
	{
		delete[] name; name = nullptr;
		delete[] accountNumb; accountNumb = nullptr;
		balance = 0.0;
	}

	void copyStr(char to[], char from[])
	{
		if (from[0] == '\0')
		{
			to[0] = '\0';
			return;
		}

		to[0] = from[0];

		return copyStr(to + 1, from + 1);
	}

public:
	BankAccount() : name(nullptr), accountNumb(nullptr), balance(0.0) {}

	BankAccount(char _name[], char _accountNumb[], double _balance) : balance(_balance)
	{
		name = new char[getSizeStr(_name)];
		accountNumb = new char[getSizeStr(_accountNumb)];

		copyStr(name, _name);
		copyStr(accountNumb, _accountNumb);
	}

	BankAccount(const BankAccount& other) : balance(other.balance)
	{
		name = new char[getSizeStr(other.name)];
		accountNumb = new char[getSizeStr(other.accountNumb)];
	}

	BankAccount operator=(const BankAccount& other)
	{
		if (this != &other)
		{
			del();
			this->name = new char[getSizeStr(other.name)];
			this->accountNumb = new char[getSizeStr(other.accountNumb)];
			copyStr(name, other.name);
			copyStr(accountNumb, other.accountNumb);
			this->balance = other.balance;
		}

		return *this;
	}

	BankAccount& operator+=(const BankAccount& other)
	{
		*this = other;

		return *this;
	}

	~BankAccount() { del(); }

	void deposit(double add)
	{
		balance += add;
	}

	void withdraw(double remove)
	{
		balance -= remove;
	}

	const char* getAccountNumber() const
	{
		return accountNumb;
	}

	void print() const
	{
		std::cout << name << "\t" << accountNumb << "\t" << balance << std::endl;
	}
};

class Bank
{
private:
	BankAccount accounts[MAX_SIZE];
	size_t size;

public:
	Bank() : accounts(), size(0) {}

	Bank(const Bank& other) : size(other.size)
	{
		for (size_t i = 0; i < size; ++i)
		{
			accounts[i] = other.accounts[i];
		}
	}

	Bank& operator=(const Bank& other)
	{
		if (this != &other)
		{
			size = other.size;

			for (size_t i = 0; i < size; ++i)
			{
				accounts[i] = other.accounts[i];
			}
		}

		return *this;
	}

	~Bank() {};

	void addAccount(const BankAccount& addMe)
	{
		accounts[size] += addMe;
		++size;
	}

	void deleteAccount(char* removeMe)
	{
		bool flag = true; // true = keep searching

		for (size_t i = 0; i < size && flag; ++i)
		{
			if (eqStr(accounts[i].getAccountNumber(), removeMe))
			{
				BankAccount temp = accounts[i];
				accounts[i] = accounts[size];
				accounts[size] = temp;

				flag = false;
				--size;
			}
		}

		if (flag == true)
		{
			std::cout << "\n\n\tERROR: No such account! Program may behave unexpectedly after this error!\n";
		}
	}

	void makeDeposit(char ID[], double money)
	{
		bool flag = true; // true = keep searching

		for (size_t i = 0; i < size && flag; ++i)
		{
			if (eqStr(accounts[i].getAccountNumber(), ID))
			{
				accounts[i].deposit(money);
				flag = false;
			}
		}

		if (flag == true)
		{
			std::cout << "\n\n\tERROR: No such account! Program may behave unexpectedly after this error!\n";
		}
	}

	void withDraw(char ID[], double money)
	{
		bool flag = true; // true = keep searching

		for (size_t i = 0; i < size && flag; ++i)
		{
			if (eqStr(accounts[i].getAccountNumber(), ID))
			{
				accounts[i].withdraw(money);
				flag = false;
			}
		}

		if (flag == true)
		{
			std::cout << "\n\n\tERROR: No such account! Program may behave unexpectedly after this error!\n";
		}
	}

	void print()
	{
		for (size_t i = 0; i < size; ++i)
		{
			accounts[i].print();
		}
	}

};

int main()
{
    std::cout << "Hello World!\n";

	char name1[100] = "Simeon";
	char acNUm[100] = "BG 145236";

	char name2[100] = "Pe6o";
	char acNum[100] = "BG 000No money";

	BankAccount acc1(name1, acNUm, 100.0);

	BankAccount acc2(name2, acNum, 0.0);

	Bank KTB;

	KTB.addAccount(acc1);
	KTB.addAccount(acc2);

	KTB.makeDeposit(acNum, 100);

	KTB.withDraw(acNUm, 50);

	KTB.print();

	KTB.deleteAccount(acNUm);

	KTB.print();

	return 0;
}