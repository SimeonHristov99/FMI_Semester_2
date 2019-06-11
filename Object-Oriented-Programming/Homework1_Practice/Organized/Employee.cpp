#include "pch.h"
#include "Employee.hpp"

#include <iostream>

void Employee::copy(const char _name[], const char _lastname[], const char _SSN[])
{
	if (_name == nullptr || _name[0] == '\0' || _lastname == nullptr || _lastname[0] == '\0' || _SSN == nullptr || _SSN[0] == '\0')
	{
		std::cout << "\n\nERROR: Copying employee didn't work!\n"; exit(1);
	}

	firstname = new char[getSizeStr(_name)];
	copyStr(firstname, _name);

	lastname = new char[getSizeStr(_lastname)];
	copyStr(lastname, _lastname);

	SSN = new char[getSizeStr(_SSN)];
	copyStr(SSN, _SSN);
}

void Employee::del()
{
	delete[] firstname; firstname = nullptr;
	delete[] lastname; lastname = nullptr;
	delete[] SSN; SSN = nullptr;
}

Employee::Employee() : firstname(nullptr), lastname(nullptr), owner(false), SSN(nullptr), experience(0), numberofSoldCars(0) {}

Employee::Employee(char _name[], char _lastname[], char _SSN[], unsigned short int _experience, unsigned short int _numberofSoldCars, bool _owner = false)
{
	copy(_name, _lastname, _SSN);
	experience = _experience;
	numberofSoldCars = _numberofSoldCars;
	owner = _owner;
}

Employee::Employee(const Employee& other) : experience(other.experience), numberofSoldCars(other.numberofSoldCars)
{
	copyStr(firstname, other.firstname);
	copyStr(lastname, other.lastname);
	copyStr(SSN, other.SSN);

	if (other.owner == true)
	{
		std::cout << "\n\nERROR: Trying to copy owner!\n\n"; exit(1);
	}

	owner = false;
}

Employee& Employee::operator=(const Employee& other)
{
	if (this != &other)
	{
		del();
		copy(other.firstname, other.lastname, other.SSN);
		this->experience = other.experience;
		this->numberofSoldCars = other.numberofSoldCars;
	}

	return *this;
}

Employee::~Employee() { del(); }

void Employee::increaseNumberofSoldCars()
{
	++numberofSoldCars;
}

void Employee::print() const
{
	std::cout << firstname << " " << lastname << " with " << experience << " years of experience and " << numberofSoldCars << " sales." << std::endl;
}

void Employee::setup()
{
	char buffer1[1000], buffer2[1000], buffer3[1000];

	std::cout << "\nBe careful - any mistake here will restart the information input process!\n";

	do
	{
		std::cout << "    First name: "; std::cin >> buffer1;
		std::cout << "    Family name: "; std::cin >> buffer2;
		std::cout << "    SSN (10-digits): "; std::cin >> buffer3;
		std::cout << "    Experience (in years): "; std::cin >> experience;
		std::cout << "    Number of sold cars: "; std::cin >> numberofSoldCars;
	} while (buffer1 == nullptr || buffer1[0] == '\0' || buffer2 == nullptr || buffer2[0] == '\0' || buffer3 == nullptr || buffer3[0] == '\0' || getSizeStr(buffer3) != 11 || experience < 0 || experience > 80 || numberofSoldCars < 0);

	owner = false;

	copy(buffer1, buffer2, buffer3);
}

void Employee::makeBoss(bool changed)
{
	char buffer1[1000], buffer2[1000], buffer3[1000];

	if (changed)
		del();

	experience = 0;
	numberofSoldCars = 0;
	owner = true;

	std::cout << "\nBe careful - any mistake here will restart the information input process!\n";

	do
	{
		std::cout << "    First name: "; std::cin >> buffer1;
		std::cout << "    Family name: "; std::cin >> buffer2;
		std::cout << "    SSN (10-digits): "; std::cin >> buffer3;
	} while (buffer1 == nullptr || buffer1[0] == '\0' || buffer2 == nullptr || buffer2[0] == '\0' || buffer3 == nullptr || buffer3[0] == '\0' || getSizeStr(buffer3) != 11);

	copy(buffer1, buffer2, buffer3);
}

const char* Employee::getFName() const
{
	return firstname;
}

const char* Employee::getLName() const
{
	return lastname;
}

const char* Employee::getSSN() const
{
	return SSN;
}

unsigned short int Employee::getExperience() const
{
	return experience;
}

unsigned short int Employee::getNumberofSoldCars() const
{
	return numberofSoldCars;
}