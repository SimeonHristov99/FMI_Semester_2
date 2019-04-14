#include "pch.h"
#include "Faculty.hpp"
#include <iostream>

int main()
{
	Student s1("IS", 1, 3, 71845, "Simeon", "Hristov");
	Student s2("KN", 2, 6, 84125, "Viktor", "Stamatski");
	Student s3("KN", 5, 6, 82136, "Durven", "Dubov");
	Student s4("IS", 1, 3, 71445, "Hristo", "Simeonov");
	Student s5("KN", 3, 6, 89213, "Sasho", "Peshov");
	Student s6("KN", 4, 6, 81234, "Pesho", "Sashov");

	Student sArr[6] = { s1, s2, s3, s4, s5, s6 };

	Faculty f1("FMI", sArr, 6);

	std::cout << "\n\tPrinting Initial Data\n\n";

	std::cout << "MAJOR" << "\t" << "YEAR" << "\t" << "GROUP" << "\t" << "FN" << "\t" << "NAME\n\n";

	f1.print();

	std::cout << "\n\tSorting Students\n\n";

	f1.sortStudents();

	f1.print();

	std::cout << "\n\tRemoving Sasho Peshov\n";

	f1 -= 89213;

	f1.print();

	std::cout << "\n\tRemoving Viktor\n";

	f1 -= 84125;

	f1.print();

	std::cout << "\n\tAdding Viktor back\n\n";

	f1 += s2;

	f1.print();

	std::cout << "\n\tSorting Again\n\n";

	f1.sortStudents();

	f1.print();

	std::cout << "\n";
	return 0;
}