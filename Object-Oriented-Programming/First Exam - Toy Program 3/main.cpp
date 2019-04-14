#include "pch.h"
#include "Bookstore.hpp"
#include <iostream>

int main()
{
	Book b1;

	std::cout << b1 << std::endl;

	Book b2("Lord of the Rings", "James", 2000, 100);

	std::cout << b2 << std::endl;

	Book b3 = b1;

	std::cout << b1 << std::endl;

	Book b4;

	b4 = b2;

	std::cout << b4 << " Price is " << b4.getPrice() << std::endl;

	std::cout << std::boolalpha << (b1 == b2) << " " << (b4 == b2) << std::endl;


	Bookstore bs1;

	bs1.print();

	Book books[4] = { b1, b2, b3, b4 };

	Bookstore bs2("MyBookstore", books, 4);

	bs2.print();

	bs1 = bs1 + b1;
	bs1 = bs1 + b2;
	bs1 += b3;
	bs1 += b4;

	std::cout << "\nTesting +, +=, =\n";
	bs1.print();

	return 0;
}