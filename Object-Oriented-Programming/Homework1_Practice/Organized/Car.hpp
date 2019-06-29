#pragma once

#include "HelperFunctions.hpp"

class Car
{
private:
	char* brand;
	char* model;
	unsigned short int yearMade;
	double price;
	double mileage;

	void copy(const char _brand[], const char _model[]);
	void del();

public:
	Car();
	Car(char _brand[], char _model[], unsigned short int _yearMade, double _price, double _mileage);
	Car(const Car& other);
	Car& operator=(const Car& other);
	~Car();

	void print() const;
	void setup();

	const char* getBrand() const;
	const char* getModel() const;
	unsigned short int getYearMade() const;
	double getPrice() const;
	double getMileage() const;
};