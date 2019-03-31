#include "pch.h"
#include <iostream>

#include "HelperFunctions.hpp"
#include "Employee.hpp"
#include "Factory.hpp"

int main()
{
	// Test Employee
	/*
		Employee p1("Pe6o", "CEO", 1000000);
		Employee p2 = p1;
		Employee p3;
		p3 = p1;
		std::cout << std::fixed;
		p1.print();
		p2.print();
		p3.print();

		p1.changeName("Me6o");
		p2.changeName("Sme6o");

		p1.print();
		p2.print();
		p3.print();
	*/

	// Test Factory
	/*
		Employee p1("Pesho1", "CPO", 1500);
		Employee p2("Pesho", "CEO", 10000);
		Employee p3("Kiro", "CPE", 6215);
		Employee p4("Kiro2", "receptionist", 10);

		Employee staff[4] = { p1, p2, p3, p4 };

		Factory myfact("Sofia University", staff, 4);

		myfact.sortSalary();

		myfact.removeEmployee("Pesho1");

		myfact.print();

		myfact.changeName("FMI");

		myfact.removeEmployee("Kiro2");

		myfact.print();
	*/
	return 0;
}