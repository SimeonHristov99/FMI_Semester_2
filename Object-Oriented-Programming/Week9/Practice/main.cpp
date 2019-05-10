#include "pch.h"
#include "Org.hpp"
#include "Elf.hpp"
#include <iostream>

int main()
{
	std::cout << "Testing Org's default constructor:\n\n";

	Org o1;

	std::cout << o1 << std::endl;

	std::cout << "\n\nTesting Org's parametric constructor:\n\n";

	Org o2("John", 50, 45, 70, 10);

	std::cout << o2 << std::endl;

	std::cout << "\n\nTesting Org's copy constructor:\n\n";

	Org o3 = o2;

	std::cout << o3 << std::endl;

	std::cout << "\n\nTesting Org's operator=:\n\n";

	Org o4;

	o4 = o3;

	std::cout << o4 << std::endl;

	std::cout << "\n\nTesting Org's operator==(should be false):\n\n";

	std::cout << std::boolalpha << (o1 == o2) << std::endl;

	std::cout << "\n\nTesting Org's operator=!=(should be true and false):\n\n";

	std::cout << std::boolalpha << (o1 != o3) << std::endl;
	std::cout << std::boolalpha << (o2 != o3) << std::endl;

	std::cout << "\n\nTesting Org's operators <=, >= (all should be true):\n\n";
	
	std::cout << std::boolalpha << (o3 <= o4) << std::endl;
	std::cout << std::boolalpha << (o4 >= o2) << std::endl;

	std::cout << "\n\nTesting Org's operator<(only the second should be true):\n\n";
	
	std::cout << std::boolalpha << (o1 < o2) << std::endl;
	std::cout << std::boolalpha << (o1 > o2) << std::endl;
	std::cout << std::boolalpha << (o2 > o4) << std::endl;
	std::cout << std::boolalpha << (o1 <= o2) << std::endl;

	std::cout << "\n--------------------------------------------------------\n";

	std::cout << "\n\n\n\nTesting Elf's default constructor:\n\n";

	Elf e1;

	std::cout << e1 << std::endl;

	std::cout << "\n\nTesting Elf's parametric constructor:\n\n";

	Elf e2("Willy", 50, 45, 70);

	std::cout << e2 << std::endl;

	std::cout << "\n\nTesting Elf's copy constructor:\n\n";

	Elf e3 = e2;

	std::cout << e3 << std::endl;

	std::cout << "\n\nTesting Elf's operator=:\n\n";

	Elf e4;

	e4 = e3;

	std::cout << e4 << std::endl;

	std::cout << "\n\nTesting Elf's operator==(should be false):\n\n";

	std::cout << std::boolalpha << (e1 == e2) << std::endl;

	std::cout << "\n\nTesting Elf's operator=!=(should be true and false):\n\n";

	std::cout << std::boolalpha << (e1 != e3) << std::endl;
	std::cout << std::boolalpha << (e2 != e3) << std::endl;

	std::cout << "\n\nTesting Elf's operators <=, >= (all should be true):\n\n";

	std::cout << std::boolalpha << (e3 <= e4) << std::endl;
	std::cout << std::boolalpha << (e4 >= e2) << std::endl;

	std::cout << "\n\nTesting Elf's operator<(only the second should be true):\n\n";

	std::cout << std::boolalpha << (e1 < e2) << std::endl;
	std::cout << std::boolalpha << (e1 > e2) << std::endl;
	std::cout << std::boolalpha << (e2 > e4) << std::endl;
	std::cout << std::boolalpha << (e1 <= e2) << std::endl;

	std::cout << "\n\nTesting Elf's special function\n\n";

	std::cout << "Before: " << e2 << std::endl;
	e2.effect();
	std::cout << "After: " << e2 << std::endl;

	std::cout << "\n\n";

	return 0;
}