#include "pch.h"
#include <iostream>
#include <iomanip>
const int MAX_SIZE_NAME = 16;
const int SUBJECTS = 2;
const int MAX_STUDENTS = 50;

struct Student
{
	unsigned int facultyNumber;
	unsigned char name[MAX_SIZE_NAME];
	unsigned char familyName[MAX_SIZE_NAME];
	double grades[SUBJECTS];
};

class Faculty
{
public:
	void setStudentGrades()
	{
		std::cout << "Student grades:" << std::endl;
		for (int j = 0; j < SUBJECTS; ++j)
		{
			std::cout << "Enter grade " << j << ": ";
			std::cin >> (*students)->grades[j];
		}
	}

	const double* getStudentGrades() const
	{
		return (*students)->grades;
	}

	const unsigned char* getNameStudent() const
	{
		return (*students)->name;
	}

	const unsigned char* getNameFamilyStudent() const
	{
		return (*students)->familyName;
	}

	const unsigned int getFacultyNumber() const
	{
		return (*students)->facultyNumber;
	}

	const char* getFacultyName() const
	{
		return name;
	}

	void setDeanName()
	{
		std::cin.getline(deanName, MAX_SIZE_NAME);
	}

private:
	char name[MAX_SIZE_NAME];
	char deanName[MAX_SIZE_NAME];
	Student* students[MAX_STUDENTS];
};

double calculateAverage(const double grades[], int size, double sum = 0)
{
	if (size <= 0)
	{
		return sum / SUBJECTS;
	}

	return calculateAverage(grades + 1, size - 1, sum + grades[0]);
}

void printStudnet(const Student& student)
{
	std::cout << student.facultyNumber << std::setw(8) << student.name << std::setw(8) << student.familyName << std::setw(8);

	for (int i = 0; i < SUBJECTS; ++i)
	{
		 std::cout << student.grades[i] << " ";
	}

	std::cout << calculateAverage(student.grades, SUBJECTS);
}

void removeStudentsWith2s(Student* ptrArr[], size_t& size)
{
	for (size_t i = 0; i < size; ++i)
		if (ptrArr[i]->grades[0] == 2)
		{
			bool flag = true;

			for (size_t j = 1; j < SUBJECTS && flag; ++j)
				if (ptrArr[i]->grades[j] != 2)
					flag = false;

			if (flag)
			{
				for (size_t k = i; k < size; ++k)
					ptrArr[k] = ptrArr[k + 1];
				--size;
			}
		}
}

int main()
{
	std::cout << "Student Faculty Number" << "        " << "Student Name" << "        " << "Student Family Name" << "        " << "Student Grades\n\n" << std::endl;

	Student s1 = { 71845, "Sam", "Johnson", 6, 2 };
	Student s2 = { 71845, "John", "Peterson", 2, 2 };

	Student stArr[MAX_STUDENTS] = { s1, s2 };
	size_t size = 2;

	for (size_t i = 0; i < size; ++i)
	{
		printStudnet(stArr[i]);
		std::cout << std::endl;
	}

	Student* ptrstArr[MAX_STUDENTS];
	for (size_t i = 0; i < size; ++i)
	{
		ptrstArr[i] = &stArr[i];
	}

	std::cout << "\n\nWith filter:\n\n";

	removeStudentsWith2s(ptrstArr, size);

	for (size_t i = 0; i < size; ++i)
	{
		printStudnet(*ptrstArr[i]);
		std::cout << std::endl;
	}

	std::cout << std::endl;

	return 0;
}