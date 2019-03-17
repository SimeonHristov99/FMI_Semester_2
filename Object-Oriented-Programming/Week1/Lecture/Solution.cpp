/* Да се напише програма, която:

а) въвежда факултетните номера, имената и оценките по 5 предмета на студентите от една група;

б) извежда в табличен вид въведените данни;

в) сортира данните в низходящ ред по среден успех;

г) извежда сортираните данни, като за всеки студент извежда и средния му успех.

*/

#include "pch.h"

#include <iostream>

#include <iomanip>

const int MAX_STUDENTS = 28;

const int MAX_SIZE_NAME = 28;

const int SUBJECTS = 5;

const int INPUT_SPACE = 15;

const int WIDTH_TABLE = 25;



class Student

{

public:

	void setFN()

	{

		std::cin >> facultyNumber;

	}



	const size_t getFN() const

	{

		return facultyNumber;

	}



	void setName()

	{

		std::cin.ignore();

		std::cin.getline(name, MAX_SIZE_NAME);

	}



	const char* getName() const

	{

		return name;

	}



	void setGrades()

	{

		for (size_t i = 0; i < SUBJECTS; ++i)

		{

			std::cout << " " << std::setw(INPUT_SPACE) << "Enter grade " << i + 1 << ": ";

			std::cin >> grades[i];

		}

	}



	void getGrades()

	{

		for (size_t i = 0; i < SUBJECTS; ++i)

		{

			std::cout << grades[i] << " ";

		}

	}



	void printTable()

	{

		std::cout << "Faculty Number" << std::setw(WIDTH_TABLE) << "Student" << std::setw(WIDTH_TABLE) << "Grades";

	}



	double average()

	{

		double sum = 0;

		for (int i = 0; i < SUBJECTS; ++i)

		{

			sum += grades[i];

		}

		return sum / 5;

	}



private:

	size_t facultyNumber;

	char name[MAX_SIZE_NAME];

	size_t grades[SUBJECTS];

};



int main()

{
	char proceed = 'x';
	Student students[MAX_STUDENTS];

	size_t size = 0;

	do
	{
		do

		{

			std::cout << "How many students? ";

			std::cin >> size;

		} while (size <= 0);



		std::cout << std::endl;



		for (size_t i = 0; i < size; ++i)

		{

			std::cout << "Student " << i + 1 << ":" << std::endl;

			std::cout << " " << std::setw(INPUT_SPACE) << "Enter faculty number: ";

			students[i].setFN(); //<-- why tho

			std::cout << " " << std::setw(INPUT_SPACE) << "Enter student's name: ";

			students[i].setName();

			students[i].setGrades();

			std::cout << std::endl;

		}



		std::cout << "Your table:" << std::endl;

		students->printTable();

		std::cout << std::endl;



		for (size_t i = 0; i < size; ++i)

		{

			std::cout << students[i].getFN();

			std::cout << std::setw(35);

			std::cout << students[i].getName();

			std::cout << std::setw(WIDTH_TABLE);

			students[i].getGrades();

			std::cout << std::endl;

		}



		std::cout << "Sorted table:" << std::endl;

		students->printTable();

		std::cout << std::setw(WIDTH_TABLE) << "Average";

		std::cout << std::endl;



		for (size_t i = 0; i < size; ++i)

		{

			std::cout << students[i].getFN();

			std::cout << std::setw(35);

			std::cout << students[i].getName();

			std::cout << std::setw(WIDTH_TABLE);

			students[i].getGrades();

			std::cout << std::setw(WIDTH_TABLE);

			std::cout << std::setprecision(2) << std::fixed << students[i].average();

			std::cout << std::endl;

		}

		std::cout << "Again? (Y/N) ";
		std::cin >> proceed;
	} while (proceed == 'Y' || proceed == 'y');

	return 0;
}