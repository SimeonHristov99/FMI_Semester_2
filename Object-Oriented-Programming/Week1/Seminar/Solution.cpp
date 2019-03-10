#include "pch.h"
#include <iostream>
#include <iomanip>
const int NAME = 28;
const int MAX_PRISONERS = 28;

struct Prisoner
{
	int ID;
	char name[NAME];
	int timeLeft; //in years
};

struct Prison
{
	char name[NAME];
	Prisoner* ptrPrisoners[MAX_PRISONERS];

	void printPrison(Prison& prison, int size);
	void sortptrTable(Prison& prison, int size);
};

void Prison::printPrison(Prison& prison, int size)
{
	std::cout << "Prison: " << prison.name << std::endl;
	std::cout << "Prisoner ID" << std::setw(15) << "Prisoner Name" << std::setw(15) << "Time Left" << std::endl;

	
	for (int j = 0; j < size; ++j)
	{
		std::cout << prison.ptrPrisoners[j]->ID << std::setw(15) << prison.ptrPrisoners[j]->name << std::setw(15) << prison.ptrPrisoners[j]->timeLeft << std::endl;
	}
	
}

void Prison::sortptrTable(Prison& prison, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		int minTime = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (prison.ptrPrisoners[j]->timeLeft < prison.ptrPrisoners[minTime]->timeLeft)
			{
				minTime = j;
			}
		}
		Prisoner* temp = prison.ptrPrisoners[minTime];
		prison.ptrPrisoners[minTime] = prison.ptrPrisoners[i];
		prison.ptrPrisoners[i] = temp;
	}
}

int main()
{
	Prisoner prisonersArr[MAX_PRISONERS];
	Prison prison;
	size_t size = 0;
	char proceed = 'x';

	std::cout << "Enter name of prison: ";
	std::cin.getline(prison.name, NAME);
	std::cout << std::endl;

	do
	{
		std::cout << "Prisoner " << size + 1 << ":\n" << std::setw(15);
		std::cout << "ID: ";
		std::cin >> prisonersArr[size].ID;
		std::cin.ignore();
		std::cout << std::setw(17);
		std::cout << "Name: ";
		std::cin.getline(prisonersArr[size].name, NAME);
		//std::cout << " ";
		//std::cin.ignore();
		std::cout << std::setw(25) << "Time to serv";
		//std::cin.ignore(); 
		std::cout <<"e: ";
		std::cin >> prisonersArr[size].timeLeft;

		std::cout << "Create new prisoner? (Y/N) ";
		std::cin >> proceed;
		++size;
	} while (proceed == 'Y' || proceed == 'y');

	for (size_t i = 0; i < size; ++i)
	{
		prison.ptrPrisoners[i] = &prisonersArr[i];
	}

	prison.printPrison(prison, size);
	std::cout << std::endl;

	std::cout << "Sorted:\n" << std::endl;
	prison.sortptrTable(prison, size);

	prison.printPrison(prison, size);
	std::cout << std::endl;

	return 0;
}