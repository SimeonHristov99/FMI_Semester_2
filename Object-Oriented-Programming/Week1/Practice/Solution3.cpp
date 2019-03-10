#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cmath>
const unsigned short int SIDES = 3;
const unsigned short int MAX_SPACE = 15;

struct Point
{
	short int x;
	short int y;
};

struct Triangle
{
	Point A;
	Point B;
	Point C;

	double findArea(Triangle& triangle);

	double findPerimeter(Triangle& triangle);
};

double Triangle::findArea(Triangle& triangle)
{
	double result = triangle.A.x * (triangle.B.y - triangle.C.y) + triangle.B.x * (triangle.C.y - triangle.A.y) + triangle.C.x * (triangle.A.y - triangle.B.y);
	return result < 0 ? (result*(-1)) / 2 : result / 2; //if result == 0 then a triangle does not exist
}

double Triangle::findPerimeter(Triangle& triangle)
{
	double side1 = sqrt(pow((triangle.B.x - triangle.A.x), 2) + pow((triangle.B.y - triangle.A.y), 2));
	double side2 = sqrt(pow((triangle.C.x - triangle.B.x), 2) + pow((triangle.C.y - triangle.B.y), 2));
	double side3 = sqrt(pow((triangle.C.x - triangle.A.x), 2) + pow((triangle.C.y - triangle.A.y), 2));

	return side1 + side2 + side3;
}

int main()
{
	char proceed = 'x';

	do
	{
		Point A;
		Point B;
		Point C;

		std::cout << "Point A:" << std::endl << std::setw(MAX_SPACE);
		std::cout << "Enter x: ";
		std::cin >> A.x;
		std::cout << "" << std::setw(MAX_SPACE);
		std::cout << "Enter y: ";
		std::cin >> A.y;
		std::cout << std::endl;

		std::cout << "Point B:" << std::endl << std::setw(MAX_SPACE);
		std::cout << "Enter x: ";
		std::cin >> B.x;
		std::cout << "" << std::setw(MAX_SPACE);
		std::cout << "Enter y: ";
		std::cin >> B.y;
		std::cout << std::endl;

		std::cout << "Point C:" << std::endl << std::setw(MAX_SPACE);
		std::cout << "Enter x: ";
		std::cin >> C.x;
		std::cout << "" << std::setw(MAX_SPACE);
		std::cout << "Enter y: ";
		std::cin >> C.y;
		std::cout << std::endl;

		Triangle triange = { A, B, C };

		std::cout << "Area = " << triange.findArea(triange) << std::endl;
		std::cout << "Perimeter = " << std::setprecision(2) << std::fixed << triange.findPerimeter(triange) << std::endl;
		std::cout << std::endl;

		std::cout << "Again? (Y/N) ";
		std::cin >> proceed;
		std::cout << std::endl;
	} while (proceed == 'Y' || proceed == 'y');

	return 0;
}