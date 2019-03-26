#include "pch.h"
#include "Car.hpp"

#include <iostream>

void Car::copy(const char _brand[], const char _model[])
{
	if (_brand == nullptr || _brand[0] == '\0' || _model == nullptr || _model[0] == '\0')
		exit(1);

	brand = new char[getSizeStr(_brand)];
	copyStr(brand, _brand);

	model = new char[getSizeStr(_model)];
	copyStr(model, _model);
}

void Car::del()
{
	delete[] brand; brand = nullptr;
	delete[] model; model = nullptr;
}

Car::Car() : brand(nullptr), model(nullptr), yearMade(1900), price(250), mileage(0) {}

Car::Car(char _brand[], char _model[], unsigned short int _yearMade, double _price, double _mileage) : yearMade(_yearMade), price(_price), mileage(_mileage)
{
	copy(_brand, _model);
}

Car::Car(const Car& other) : yearMade(other.yearMade), price(other.price), mileage(other.mileage)
{
	copyStr(brand, other.brand);
	copyStr(model, other.model);
}

Car& Car::operator=(const Car& other)
{
	if (this != &other)
	{
		del();
		copy(other.brand, other.model);
		this->mileage = other.mileage;
		this->price = other.price;
		this->yearMade = other.yearMade;
	}

	return *this;
}

Car::~Car() { del(); }

void Car::print() const
{
	std::cout << brand << " " << model << " made in " << yearMade << " with mileage " << mileage << "km." << std::endl;
}

void Car::setup()
{
	char buffer1[1000], buffer2[1000];

	std::cout << "\nBe careful - any mistake here will restart the information input process!\n";

	do
	{
		std::cout << "    Brand: "; std::cin >> buffer1;
		std::cout << "    Model: "; std::cin >> buffer2;
		std::cout << "    Year of production [1900 - 2019]: "; std::cin >> yearMade;
		std::cout << "    Price (must but greater than or equal to 250): "; std::cin >> price;
		std::cout << "    Mileage: "; std::cin >> mileage;
	} while (buffer1 == nullptr || buffer1[0] == '\0' || buffer2 == nullptr || buffer2[0] == '\0' || yearMade < 1900 || yearMade > 2019 || price < 250.0 || mileage < 0.0);

	copy(buffer1, buffer2);
}

const char* Car::getBrand() const
{
	return brand;
}

const char* Car::getModel() const
{
	return model;
}

unsigned short int Car::getYearMade() const
{
	return yearMade;
}

double Car::getPrice() const
{
	return price;
}

double Car::getMileage() const
{
	return mileage;
}