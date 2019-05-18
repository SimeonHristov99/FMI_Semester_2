#include "pch.h"
#include "Savings.hpp"
#include "Checking.hpp"
#include <iostream>

int main()
{
    std::cout << "Testing default constructor Account:\n\n";

	Account a1;

	std::cout << a1;

	std::cout << "\n\nTesting parametric constructor Account:\n\n";

	Account a3(15462, "James", 10);

	std::cout << a3;

	std::cout << "\n\nTesting copy constructor Account:\n\n";

	Account a2 = a1;

	std::cout << a2;

	std::cout << "\n\nTesting operator=\n\n";

	Account a4;

	a4 = a3;

	std::cout << a4;

	std::cout << "\n\nTesting credit and debit and getBalance():\n\n";

	a4.credit(100);
	std::cout << "new a4 is (110): " << a4.getBalance() << std::endl;

	a4.debit(90);
	std::cout << "new a4 is (20): " << a4.getBalance() << std::endl;

	std::cout << "\n\nTesting Savings default constructor:\n\n";

	Savings s2;

	std::cout << s2 << std::endl;

	std::cout << "\n\nTesting Savings parametric constructor:\n\n";

	Savings s1(15162, "John", 100, 3);

	std::cout << s1 << std::endl;

	std::cout << "\n\nTesting Checking parametric constructor and credit():\n\n";

	Checking ch1(22224, "Sam", 200, 1);

	std::cout << "Before: " << ch1 << std::endl;

	ch1.credit(50);

	std::cout << "After: " << ch1 << std::endl;

	ch1.debit(100);

	std::cout << "After debit(100): " << ch1 << std::endl;

	std::cout << "\n\n";
	return 0;
}