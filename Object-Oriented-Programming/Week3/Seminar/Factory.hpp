#pragma once

#include "HelperFunctions.hpp"
#include "Employee.hpp"

class Factory
{
	char* name;
	Employee* staff;
	size_t MAX_CAPACITY;
	size_t USED_CAPACITY;

	void copy(const Factory& other);
	void resize();
	void del();

public:
	// Cannonical Representation
	Factory(const char*);
	Factory(const char*, Employee*, size_t staffSize);
	Factory(const Factory& other);
	Factory& operator=(const Factory& other);
	~Factory();

	// Mutators and Selectors
	void changeName(const char*);
	const char* getName() const;

	// Sort employees by salary (and print)
	void sortSalary();
	// Add employee to the end of the array
	void addEmployee();
	// Remove employee by name
	void removeEmployee(const char*);

	// Print the name and then every employee in order
	void print() const;
};