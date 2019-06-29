#include "pch.h"
#include "HelperFunctions.hpp"
#include "Employee.hpp"
#include "Car.hpp"
#include "Dealership.hpp"

#include <iostream>

int main()
{
	size_t employeeNumber = 0;
	size_t carNumber = 0;
	Dealership myDealership;

	std::cout << "        WELCOME TO YOUR DEALERSHIP\n";

	std::cout << "\nAn organization cannot function without an employer so let us set them up.\n";
	myDealership.setupCEO(employeeNumber, 0);

	std::cout << "\nOk, great! Similarly, we have to know who will sell the cars - enter in your first employee.\n";
	myDealership.addEmployee(employeeNumber);
	++employeeNumber;

	std::cout << "\nPerfect! Your dealership can start working now, just add one car.\n";
	myDealership.addCar(carNumber);
	++carNumber;

	std::cout << "Awesome! You are all set and done!\n";

	while (true)
	{
		switch (actionMenu())
		{
		case '1': {myDealership.setupCEO(employeeNumber, 1); break; }
		case '2': {myDealership.addEmployee(employeeNumber); ++employeeNumber; break; }
		case '3': {myDealership.fireEmployee(employeeNumber); --employeeNumber; break; }
		case '4': {myDealership.addCar(carNumber); ++carNumber; break; }
		case '5': {myDealership.sellCar(carNumber, employeeNumber); --carNumber; break; }
		case '6': {myDealership.sortEmployee(0, employeeNumber); break; }
		case '7': {myDealership.sortEmployee(1, employeeNumber); break; }
		case '8': {myDealership.sortCars(0, carNumber); break; }
		case '9': {myDealership.sortCars(1, carNumber); break; }
		default: return 0;
		}
	}

	return 0;
}