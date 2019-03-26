#pragma once
#include "pch.h"
#include <iostream>

size_t getSizeStr(const char str[]) // modified to count the '\0' as well
{
	if (str[0] == '\0')
		return 1;

	return 1 + getSizeStr(str + 1);
}

void copyStr(char to[], const char from[])
{
	if (from[0] == '\0')
	{
		to[0] = '\0';
		return;
	}

	to[0] = from[0];

	return copyStr(to + 1, from + 1);
}

bool eqStr(const char str0[], const char str1[])
{
	if (str0[0] == '\0' && str1[0] == '\0')
		return true;

	if (str0[0] != str1[0])
		return false;

	return eqStr(str0 + 1, str1 + 1);
}

char actionMenu()
{
	char choice = 'x';

	do
	{
		std::cout << "\nWhat would you like to do next? Choose a number from the menu. (if write \"K\" you will close the program)\n";
		std::cout << "\n        MENU        \n\n";
		std::cout << "1. Change CEO.\n2. Add a new employee.\n3. Fire an employee.\n4. Add a new car.\n5. Mark sold car.\n6. Sort employees by experience.\n7. Sort employees by sales.\n8. Sort cars by price.\n9. Sort cars by mileage.\n    Your choice: ";
		std::cin >> choice;
	} while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8' && choice != '9' && choice != 'K');

	return choice;
}