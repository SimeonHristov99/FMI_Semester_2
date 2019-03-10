#include "pch.h"
#include <iostream>
#include <iomanip>
#include "Solution2 - get cpp only.h"
const unsigned short int MAX_SIZE_FIRST_NAME = 16;
const unsigned short int MAX_DOCTORS = 10;
const unsigned short int MAX_SPACE = 25;
const unsigned short int MAX_SPACE2 = 15;
const unsigned short int MAX_SPACE3 = 35;

struct Doctor
{
	char name[MAX_SIZE_FIRST_NAME];
	int experience;
};


void sortExperience(Doctor* docs[], unsigned short int& size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		int minExperience = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (docs[j]->experience < docs[minExperience]->experience)
			{
				minExperience = j;
			}
		}
		Doctor* temp = docs[i];
		docs[i] = docs[minExperience];
		docs[minExperience] = temp;
	}
}

int main()
{
	unsigned short size = 0;

	char proceed = 'x';

	Doctor allDocs[MAX_DOCTORS];

	do
	{
		std::cout << "Doctor " << size + 1 << std::endl << std::setw(MAX_SPACE2);
		std::cout << "First name: ";
		std::cin >> allDocs[size].name;
		std::cout << "" << std::setw(MAX_SPACE2);
		std::cout << "Experience: ";
		std::cin >> allDocs[size].experience;

		std::cout << " " << std::setw(MAX_SPACE3) << "Enter another doctor? (Y/N) ";
		std::cin >> proceed;

		++size;
		std::cout << std::endl;
	} while (proceed == 'y' || proceed == 'Y');



	Doctor* ptrDocs[MAX_DOCTORS];
	for (size_t i = 0; i < size; i++)
	{
		ptrDocs[i] = &allDocs[i];
	}

	sortExperience(ptrDocs, size);

	std::cout << "Doctor" << std::setw(MAX_SPACE) << "Experience" << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		std::cout << ptrDocs[i]->name << std::setw(MAX_SPACE) << ptrDocs[i]->experience << std::endl;
	}
	std::cout << std::endl;

	return 0;
}