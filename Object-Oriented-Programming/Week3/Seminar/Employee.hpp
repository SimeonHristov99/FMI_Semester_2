#pragma once

#include "HelperFunctions.hpp"

class Employee
{
private:
	char* name;
	char* position;
	double salary;

	void del();
	void copy(const char _name[], const char _position[]);

public:
	Employee();
	Employee(const char* _name, const char* _position, double _salary);
	Employee(const Employee& other);
	Employee& operator=(const Employee& other);
	~Employee();

	void setup();
	void changeName(const char* _name);
	void changePosition();
	void changeSalary();

	const char* getName() const;
	const char* getPosition() const;
	double getSalary() const;
	void print() const;
};