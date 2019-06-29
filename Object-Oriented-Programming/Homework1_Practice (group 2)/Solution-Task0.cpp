#include "pch.h"
#include <iostream>

struct Point
{
	int x, y;
};

struct Rectangle
{
	Point A;
	Point B, C, D;
	size_t height, width;

	void calculateOtherPoints();
};

void Rectangle::calculateOtherPoints()
{
	D.y = A.y - height;
	D.x = A.x;
	C.y = D.y;
	C.x = D.x + width;
	B.y = A.y;
	B.x = A.x + width;
}

double getIntersectionArea(Rectangle& r1, Rectangle& r2)
{
	if (!(r2.A.x < r1.B.x && r2.A.y > r1.C.y && r2.D.x > r1.D.x && r2.D.y < r1.A.y))
	{
		std::cout << "\n\n    The rectangles do not intersect!\n\n";
		return 0;
	}

	Point answerA, answerC;

	answerA.x = r1.A.x > r2.A.x ? r1.A.x : r2.A.x;
	answerA.y = r1.A.y < r2.A.y ? r1.A.y : r2.A.y;
	answerC.x = r1.C.x < r2.C.x ? r1.C.x : r2.C.x;
	answerC.y = r1.C.y > r2.C.y ? r1.C.y : r2.C.y;

	return (answerC.x - answerA.x)*(answerA.y - answerC.y);
}

int main()
{
	Rectangle rectangle1, rectangle2;

	std::cout << "Rectangle 1\n";
	std::cout << "    Enter x coordinate of A: ";
	std::cin >> rectangle1.A.x;
	std::cout << "    Enter y coordinate of A: ";
	std::cin >> rectangle1.A.y;

	do
	{
		std::cout << "    Enter height: ";
		std::cin >> rectangle1.height;
	} while (rectangle1.height == 0);

	do
	{
		std::cout << "    Enter width: ";
		std::cin >> rectangle1.width;
	} while (rectangle1.width == 0);

	std::cout << "\n\nRectangle 2\n";
	std::cout << "    Enter x coordinate of A: ";
	std::cin >> rectangle2.A.x;
	std::cout << "    Enter y coordinate of A: ";
	std::cin >> rectangle2.A.y;

	do
	{
		std::cout << "    Enter height: ";
		std::cin >> rectangle2.height;
	} while (rectangle2.height == 0);

	do
	{
		std::cout << "    Enter width: ";
		std::cin >> rectangle2.width;
	} while (rectangle2.width == 0);

	rectangle1.calculateOtherPoints();
	rectangle2.calculateOtherPoints();

	std::cout << "\nIntersection area of rectangles: " << getIntersectionArea(rectangle1, rectangle2) << std::endl;

	return 0;
}