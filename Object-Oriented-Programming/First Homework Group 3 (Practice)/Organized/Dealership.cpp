#include "pch.h"
#include "Dealership.hpp"

#include <iostream>

void Dealership::resizeStaff()
{
	Employee* temp = new Employee[staffCapacity * 2];

	for (size_t i = 0; i < staffCapacity; ++i)
		temp[i] = staff[i];

	delete[] staff; staff = temp; staffCapacity *= 2;
}

void Dealership::resizeCars()
{
	Car* temp = new Car[carsCapacity * 2];

	for (size_t i = 0; i < carsCapacity; ++i)
		temp[i] = cars[i];

	delete[] cars; cars = temp; carsCapacity *= 2;
}

void Dealership::sellCarMain(char _brand[], char _model[], double _price, char _firstname[], char _lastname[], size_t& limit, size_t& limitStaff)
{
	if (_brand == nullptr || _brand[0] == '\0' || _model == nullptr || _model[0] == '\0' || _price < 250.0 || _firstname == nullptr || _firstname == '\0' || _lastname == nullptr || _lastname == '\0')
		exit(1);

	bool flag = true, person = false;

	Car* temp = new Car[carsCapacity];

	for (size_t i = 0; i < limit; ++i)
	{
		if (eqStr(cars[i].getBrand(), _brand) && eqStr(cars[i].getModel(), _model) && cars[i].getPrice() == _price)
		{
			flag = false;

			std::cout << "\n\nNew sale: ";
			cars[i].print();
		}
		else
		{
			if (i < 1 && !flag)
			{
				std::cout << "\n\nERROR: Dealership must have at least one employee!\n";
				exit(1);
			}
			!flag ? temp[i - 1] = cars[i] : temp[i] = cars[i];
		}
	}

	delete[] cars; cars = temp;

	if (flag)
	{
		std::cout << "\n\nERROR: No such car!\n";
		exit(1);
	}

	size_t j = 0;
	for (; j < limitStaff && !person; ++j)
		if (eqStr(staff[j].getFName(), _firstname) && eqStr(staff[j].getLName(), _lastname))
			person = true;

	if (person == false)
	{
		std::cout << "\n\nERROR: No such employee!\n";
		exit(1);
	}

	std::cout << "Sold by " << _firstname << " " << _lastname << std::endl;

	staff[j - 1].increaseNumberofSoldCars();
}

Dealership::Dealership() : staffCapacity(2), carsCapacity(2)
{
	staff = new Employee[staffCapacity];
	cars = new Car[carsCapacity];
}

void Dealership::addEmployee(const unsigned int& i)
{
	if (i >= staffCapacity)
		resizeStaff();

	staff[i].setup();

	if (i > 0)
	{
		for (size_t j = 0; j < i; ++j)
			if (eqStr(staff[j].getSSN(), staff[i].getSSN()) || eqStr(CEO.getSSN(), staff[i].getSSN()))
			{
				std::cout << "\n\nERROR: Social security number must be unique!\n";
				exit(1);
			}
	}
	else
	{
		if (eqStr(CEO.getSSN(), staff[i].getSSN()))
		{
			std::cout << "\n\nERROR: Social security number must be unique!\n";
			exit(1);
		}
	}

	std::cout << "\n\nNew employee: ";
	staff[i].print();
}

void Dealership::addCar(const unsigned int& i)
{
	if (i >= carsCapacity)
		resizeCars();

	cars[i].setup();

	std::cout << "\n\nNew car: ";
	cars[i].print();
}

void Dealership::setupCEO(size_t& stafflimit, bool changed = 0)
{
	CEO.makeBoss(changed);

	if (changed)
		for (size_t i = 0; i <= stafflimit; i++)
			if (eqStr(CEO.getSSN(), staff[i].getSSN()))
			{
				std::cout << "\n\nERROR: Social security number must be unique!\n";
				exit(1);
			}

	std::cout << "\n\nNew CEO: " << CEO.getFName() << " " << CEO.getLName() << " SSN(" << CEO.getSSN() << ")\n";
}

void Dealership::sortEmployee(bool option, size_t& limit)
{
	Employee** sorted = new Employee*[limit];

	for (size_t i = 0; i < limit; ++i)
		sorted[i] = &staff[i];

	for (size_t i = 0; i < limit - 1; ++i)
	{
		size_t minIndex = i;

		for (size_t j = i + 1; j < limit; ++j)
		{
			if (option == 0)
			{
				if (sorted[j]->getExperience() < sorted[minIndex]->getExperience())
					minIndex = j;
			}
			else
			{
				if (sorted[j]->getNumberofSoldCars() < sorted[minIndex]->getNumberofSoldCars())
					minIndex = j;
			}
		}
		Employee* temp = sorted[i];
		sorted[i] = sorted[minIndex];
		sorted[minIndex] = temp;
	}

	std::cout << (option == 0 ? "\nEmployees by experience:\n" : "\nEmployees by number of sales:\n");

	for (size_t k = 0; k < limit; ++k)
		sorted[k]->print();

	delete[] sorted; sorted = nullptr;
}

void Dealership::sortCars(bool option, size_t limit)
{

	Car** sorted = new Car*[limit];

	for (size_t i = 0; i < limit; ++i)
		sorted[i] = &cars[i];

	for (size_t i = 0; i < limit - 1; ++i)
	{
		size_t minIndex = i;
		for (size_t j = i + 1; j < limit; ++j)
		{
			if (option == 0)
			{
				if (sorted[j]->getPrice() < sorted[minIndex]->getPrice())
					minIndex = j;
			}
			else
			{
				if (sorted[j]->getMileage() < sorted[minIndex]->getMileage())
					minIndex = j;
			}

		}
		Car* temp = sorted[i];
		sorted[i] = sorted[minIndex];
		sorted[minIndex] = temp;
	}

	std::cout << (option == 0 ? "\nEmployees by price:\n" : "\nEmployees by number of mileage:\n");

	for (size_t k = 0; k < limit; ++k)
		sorted[k]->print();

	delete[] sorted; sorted = nullptr;
}

void Dealership::fireEmployee(size_t& limit)
{
	char _SSN[11] = "";
	bool flag = true; // true = keep searching

	do
	{
		std::cout << "\nEnter the social security number of the employee you wish to lay off: ";
		std::cin >> _SSN;
	} while (getSizeStr(_SSN) != 11);

	Employee* temp = new Employee[staffCapacity];

	for (size_t i = 0; i < limit; ++i)
	{
		if (eqStr(staff[i].getSSN(), _SSN))
		{
			std::cout << "\nFired ";
			staff[i].print();

			flag = false;
		}
		else
		{
			if (i < 1 && !flag)
			{
				std::cout << "\n\nERROR: Dealership must have at least one employee!\n";
				exit(1);
			}
			!flag ? temp[i - 1] = staff[i] : temp[i] = staff[i];
		}
	}

	delete[] staff; staff = temp;

	if (flag == true)
	{
		std::cout << "\n\nERROR: No such employee!\n"; exit(1);
	}
}

void Dealership::sellCar(size_t& limit, size_t& limitStaff)
{
	if (limit == 0)
	{
		std::cout << "\n\nERROR: Dealership cannot function without cars!\n";
		exit(1);
	}

	double price;
	char buffer1[1000], buffer2[1000], buffer3[1000], buffer4[1000];

	do
	{
		std::cout << "\n    Car brand: "; std::cin >> buffer1;
		std::cout << "    Car model: "; std::cin >> buffer2;
		std::cout << "    Car price: "; std::cin >> price;
		std::cout << "    First name of employee who sold it: "; std::cin >> buffer3;
		std::cout << "    Their second name: "; std::cin >> buffer4;
	} while (buffer1 == nullptr || buffer1[0] == '\0' || buffer2 == nullptr || buffer2[0] == '\0' || buffer3 == nullptr || buffer3[0] == '\0' || buffer4 == nullptr || buffer4[0] == '\0' || price < 250);

	sellCarMain(buffer1, buffer2, price, buffer3, buffer4, limit, limitStaff);
}