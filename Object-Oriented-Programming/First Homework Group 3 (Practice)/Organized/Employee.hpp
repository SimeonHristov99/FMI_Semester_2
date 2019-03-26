#pragma once

#include "HelperFunctions.hpp"

class Employee
{
private:
	bool owner;
	char* firstname;
	char* lastname;
	char* SSN;
	unsigned short int experience;
	unsigned short int numberofSoldCars;

	void copy(const char _name[], const char _lastname[], const char _SSN[]);
	void del();

public:
	Employee();
	Employee(char [], char [], char [], unsigned short int, unsigned short int, bool _owner);
	Employee(const Employee& other);
	Employee& operator=(const Employee& other);
	~Employee();

	void print() const;
	void setup();
	void increaseNumberofSoldCars();
	void makeBoss(bool changed = false);

	const char* getFName() const;
	const char* getLName() const;
	const char* getSSN() const;
	unsigned short int getExperience() const;
	unsigned short int getNumberofSoldCars() const;	
};