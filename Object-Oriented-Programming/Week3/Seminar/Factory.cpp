#include "pch.h"
#include <iostream>

#include "Factory.hpp"

void Factory::resize()
{
	MAX_CAPACITY *= 3 + 1;
	Employee* temp = new Employee[MAX_CAPACITY];

	for (size_t i = 0; i < USED_CAPACITY; ++i)
		temp[i] = staff[i];

	delete[] staff;
	staff = temp;
}

void Factory::copy(const Factory& other)
{
	USED_CAPACITY = other.USED_CAPACITY;
	MAX_CAPACITY = (USED_CAPACITY * 3 + 1) / 2;

	name = new char[getSizeStr(other.name)];
	copyStr(name, other.name);

	staff = new Employee[MAX_CAPACITY];

	for (size_t i = 0; i < USED_CAPACITY; i++)
		staff[i] = other.staff[i];
}

void Factory::del()
{
	delete[] name; name = nullptr;
	delete[] staff; staff = nullptr; USED_CAPACITY = MAX_CAPACITY = 0; 
}

Factory::Factory(const char* _name = "") : USED_CAPACITY(0), MAX_CAPACITY(2)
{ 
	name = new char[getSizeStr(_name)];
	copyStr(name, _name);

	staff = new Employee[MAX_CAPACITY];
}

Factory::Factory(const char* _name, Employee* _staff, size_t _usedCapacity) : MAX_CAPACITY((_usedCapacity * 3 + 1) / 2), USED_CAPACITY(_usedCapacity)
{
	name = new char[getSizeStr(_name)];
	copyStr(name, _name);

	staff = new Employee[MAX_CAPACITY];
	
	for (size_t i = 0; i < USED_CAPACITY; ++i) // USED_CAPACITY := MAX_SIZE of the created array
		staff[i] = _staff[i];
}

Factory::Factory(const Factory& other)
{
	copy(other);
}

Factory& Factory::operator=(const Factory& other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}

	return *this;
}

Factory::~Factory() { del(); }

void Factory::changeName(const char* _name)
{
	if (!_name)
		_name = "";

	copyStr(name, _name);
}

inline const char* Factory::getName() const { return name; }

void Factory::sortSalary()
{
	Employee** staffAdresses = new Employee*[USED_CAPACITY - 1];

	for (size_t i = 0; i < USED_CAPACITY; i++)
		staffAdresses[i] = &staff[i];

	for (size_t i = 0; i < USED_CAPACITY; i++)
		staffAdresses[i]->print();

	for (size_t i = 0; i < USED_CAPACITY - 1; i++)
	{
		size_t minSalaryIndex = i;
		for (size_t j = i + 1; j < USED_CAPACITY; j++)
			if (staffAdresses[j]->getSalary() < staffAdresses[minSalaryIndex]->getSalary())
				minSalaryIndex = j;

		Employee* temp = staffAdresses[minSalaryIndex];
		staffAdresses[minSalaryIndex] = staffAdresses[i];
		staffAdresses[i] = temp;
	}

	std::cout << "\n   Employees sorted by salary:\n\n";

	for (size_t i = 0; i < USED_CAPACITY; i++)
		staffAdresses[i]->print();
}

void Factory::addEmployee()
{
	if (USED_CAPACITY == MAX_CAPACITY)
		resize();

	staff[USED_CAPACITY].setup();

	++USED_CAPACITY;
}

void Factory::removeEmployee(const char* _name)
{
	for (size_t i = 0; i < USED_CAPACITY; i++)
	{
		if (eqStr(staff[i].getName(), _name))
		{
			if (i != USED_CAPACITY - 1) // We should swap all but the last employee.
			{
				Employee temp = staff[USED_CAPACITY - 1];
				staff[USED_CAPACITY - 1] = staff[i];
				staff[i] = temp;
			}

			--USED_CAPACITY;
			return;
		}
	}

	std::cout << "\n\nERROR: Found no employee whose name is " << _name << "!\n";
}

void Factory::print() const
{
	std::cout << "\n\nFactory: " << name << std::endl;
	std::cout << "Staff:\n" << std::endl;
	for (size_t i = 0; i < USED_CAPACITY; i++)
	{
		staff[i].print();
	}
}