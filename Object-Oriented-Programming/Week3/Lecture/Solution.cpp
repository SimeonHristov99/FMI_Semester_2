#include "pch.h"
#include <iostream>

class RationalNumber
{
private:
	double numerator; // Written as double only because of the 'ispower10(getD())' case
	int denominator;
public:
	RationalNumber() : numerator(0), denominator(1) {};
	RationalNumber(int a, int b) : denominator(b), numerator(a) {};
	RationalNumber(const RationalNumber& other) : denominator(other.denominator), numerator(other.numerator) {};

	const bool isZero() const { return numerator == 0; }

	const int getN() const { return numerator; }
	const int getD() const { return denominator; }

	void printRN() const
	{
		if (isZero() || denominator == 1) // It would be better without isZero() but then it would become obsolete
			std::cout << numerator;

		else { std::cout << numerator << "/" << denominator; }
	}

	void inputRN();
	void add(RationalNumber& n1, RationalNumber& n2);
	void subtract(RationalNumber& n1, RationalNumber& n2);
	void multiply(RationalNumber& n1, RationalNumber& n2);
	void divide(RationalNumber& n1, RationalNumber& n2);

	void beautify(char& operation);
};

void RationalNumber::inputRN()
{
	std::cout << "    Enter numerator: ";
	std::cin >> numerator;

	do
	{
		std::cout << "    Enter denominator (cannot be zero): ";
		std::cin >> denominator;
	} while (denominator == 0);
}

void RationalNumber::add(RationalNumber& n1, RationalNumber& n2)
{
	numerator = n1.numerator* n2.denominator + n1.denominator * n2.numerator;
	denominator = n1.denominator * n2.denominator;
}

void RationalNumber::subtract(RationalNumber& n1, RationalNumber& n2)
{
	numerator = n1.numerator* n2.denominator - n1.denominator * n2.numerator;
	denominator = n1.denominator * n2.denominator;
}

void RationalNumber::multiply(RationalNumber& n1, RationalNumber& n2)
{
	numerator = n1.numerator * n2.numerator;
	denominator = n1.denominator * n2.denominator;
}

void RationalNumber::divide(RationalNumber& n1, RationalNumber& n2)
{
	numerator = n1.numerator * n2.denominator;
	denominator = n1.denominator * n2.numerator;
}

size_t gcd(size_t a, size_t b)
{
	if (a % b == 0) return b;

	return gcd(b, a % b);
}

size_t absolute(const int a)
{
	return a < 0 ? (-1) * a : a;
}

bool ispower10(const size_t a)
{
	if (a < 10)
	{
		return a == 1;
	}

	return ispower10(a / 10);
}


void RationalNumber::beautify(char& operation)
{
	if (numerator < 0 && denominator < 0)
	{
		numerator = absolute(getN());
		denominator = absolute(getD());
	}

	if (ispower10(getD()))
	{
		numerator /= denominator;
		denominator = 1;
	}

	else
	{
		size_t gcdenominator = gcd(absolute(getN() < getD() ? getD() : getN()), absolute(getD() < getN() ? getD() : getN()));

		if (gcdenominator > 1)
		{

			if (denominator < 0)
			{
				denominator = (absolute(getD()) / gcdenominator) * (-1);
			}
			else denominator = (absolute(getD()) / gcdenominator);
		}

		if (denominator < 0 && numerator > 0 && (operation != '+' || operation != '-'))
		{
			denominator *= (-1);
			numerator *= (-1);
		}
	}
}


int main()
{
	RationalNumber number1, number2;
	RationalNumber number3 = number2;
	char operation = 'x';

	std::cout << "Number 1:\n";
	number1.inputRN();
	std::cout << "\nNumber 2:\n";
	number2.inputRN();

	std::cout << "\n\n    Your two numbers are ";
	number1.printRN();
	std::cout << " and ";
	number2.printRN();
	std::cout << ".";

	do
	{
		std::cout << "\n\nChoose an operator (+), (-), (*), (/): ";
		std::cin >> operation;

		switch (operation)
		{
		case '+':
		{
			number3.add(number1, number2);
			break;
		}
		case '-':
		{
			number3.subtract(number1, number2);
			break;
		}
		case '*':
		{
			number3.multiply(number1, number2);
			break;
		}
		case '/':
		{
			number3.divide(number1, number2);
			break;
		}
		default:
		{
			std::cout << "\n\nError! No such option!\n\n";
		}
		}

		std::cout << "\n\n    Result: ";
		number3.beautify(operation);
		number3.printRN();

		std::cout << "\n\nAnother operator? (Y/N) ";
		std::cin >> operation;
	} while (operation == 'Y' || operation == 'y');



	std::cout << std::endl;

	return 0;
}