#include "pch.h"
#include <iostream>

class RationalNumber
{
private:
	double numerator;
	double denominator;

	void add(const RationalNumber& n1, const RationalNumber& n2)
	{
		make(n1.numerator*n2.denominator + n2.numerator*n1.denominator, n1.denominator*n2.denominator);
	}

public:
	void make(const double& a, const double& b)
	{
		numerator = a;
		denominator = b;
	}

	RationalNumber calculate(size_t n, RationalNumber& answer, const RationalNumber& one)
	{
		if (n == 0)
			return one;

		RationalNumber n2;
		n2.make(1, n);

		answer.add(answer, n2);

		return calculate(n - 1, answer, one);
	}

	void printRationalNumber() const
	{
		std::cout << numerator << "/" << denominator;
	}	
};

int main()
{
	RationalNumber endOfRecursion;
	endOfRecursion.make(1, 1);

	RationalNumber answer;
	answer.make(0, 1);

	size_t n = 0;

	do
	{
		std::cout << "Enter n (1 + 1/2 + .. + 1/n): ";
		std::cin >> n;
	} while (!(n > 0));

	answer.calculate(n, answer, endOfRecursion);

	std::cout << "\n    Answer: ";
	answer.printRationalNumber();
	std::cout << std::endl;

	return 0;
}