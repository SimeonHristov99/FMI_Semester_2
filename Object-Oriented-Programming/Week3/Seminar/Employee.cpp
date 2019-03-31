#include "pch.h"
#include <iostream>
#include "Employee.hpp"

void Employee::del()
{
	salary = 0;
	delete[] name; name = nullptr;
	delete[] position; position = nullptr;
}

void Employee::copy(const char _name[], const char _position[])
{
	name = new char[getSizeStr(_name)]; copyStr(name, _name);
	position = new char[getSizeStr(_position)]; copyStr(position, _position);
}

Employee::Employee() : name(nullptr), position(nullptr), salary(0) {}

Employee::Employee(const char* _name, const char* _position, double _salary) : salary(_salary)
{
	if (_name == nullptr || _position == nullptr)
		std::cout << "\n\n\tERROR: Incorrect name or position detected! Program may behave unexpectedly after this message!\n";

	copy(_name, _position);
}

Employee::Employee(const Employee& other) : salary(other.salary)
{
	copy(other.name, other.position);
}

Employee& Employee::operator=(const Employee& other)
{
	if (this != &other)
	{
		del();
		copy(other.name, other.position);
	}

	salary = other.salary;

	return *this;
}

Employee::~Employee() { del(); }

void Employee::setup()
{
	std::cout << "\nAny mistake here will restart the input process!\n";

	char buffer0[1000], buffer1[1000];

	do
	{
		std::cout << "\nEnter family name: "; std::cin >> buffer0;
		std::cout << "Enter position: "; std::cin >> buffer1;
		std::cout << "Salary: "; std::cin >> salary;
	} while (buffer0 == nullptr || buffer0[0] == '\0' || buffer1 == nullptr || buffer1[0] == '\0' || salary < 0); // 0 is available for volunteers

	copy(buffer0, buffer1);
}

void Employee::changeName(const char* _name)
{
	delete[] name;
	
	name = new char[getSizeStr(_name)]; copyStr(name, _name);
}

void Employee::changePosition()
{
	delete[] position;
	char buffer[1000];
	do
	{
		std::cout << "\nEnter new position: "; std::cin >> buffer;
	} while (buffer == nullptr || buffer[0] == '\0');

	position = new char[getSizeStr(buffer)]; copyStr(position, buffer);
}

void Employee::changeSalary()
{
	do
	{
		std::cout << "\nEnter new salary: "; std::cin >> salary;
	} while (salary < 0);
}

void Employee::print() const
{
	std::cout << name << "\t" << position << "\t" << salary << std::endl;
}

const char* Employee::getName() const { return name; }

const char* Employee::getPosition() const { return position; }

double Employee::getSalary() const { return salary; }