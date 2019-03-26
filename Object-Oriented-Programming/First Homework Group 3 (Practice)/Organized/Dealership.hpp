#pragma once

#include "HelperFunctions.hpp"
#include "Employee.hpp"
#include "Car.hpp"

class Dealership
{
private:
	Employee CEO;
	Employee* staff;
	Car* cars;
	size_t staffCapacity;
	size_t carsCapacity;

	void resizeStaff();
	void resizeCars();
	void sellCarMain(char _brand[], char _model[], double _price, char _firstname[], char _lastname[], size_t& limit, size_t& limitStaff);

public:
	Dealership();
	void addEmployee(const unsigned int& i);
	void addCar(const unsigned int& i);
	void setupCEO(size_t&, bool changed);
	void sortEmployee(bool option, size_t& limit);
	void sortCars(bool option, size_t limit);
	void fireEmployee(size_t& limit);
	void sellCar(size_t& limit, size_t& limitStaff);
};