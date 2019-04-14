#include "pch.h"
#include "AllNavies.hpp"
#include <iostream>

int main()
{
	Ship s1("James", 1900, 5, "bb");
	Ship s2("Bob", 1562, 0, "bc");
	Ship s3("Sam", 2005, 0, "bc");
	Ship s4("Colby", 2008, 4, "bb");
	Ship s5("Elon", 1999, 10, "bb");
	Ship s6("Bill", 1679, 0, "bc");

	Ship s7("Pesho", 2000, 20, "bb");

	Ship s8("Sam", 1744, 2, "bb");

	Ship sArr[6] = { s1, s2, s3, s4, s5, s6 };

	std::cout << "Testing default contructor\n";

	Navy n1;

	n1.print();

	std::cout << "\n\nTesting parametric constructor\n";

	Navy n2(sArr, "America", 6);

	n2.print();

	std::cout << "\n\nTesting resize and operators +, =\n";

	n1 = n2 + s7;

	n1.print();

	std::cout << "\n\nTesting resize and operators +, +=, =\n";

	Navy n11;

	n11 = n11 + s1;
	n11 = n11 + s2;
	n11 = n11 + s3;
	n11 += s4;
	n11 += s5;

	n11.print();

	n11 += s8;

	n11.print();

	std::cout << "\n\nTesting copy constructor\n";

	Navy n3 = n1;

	n3.print();

	std::cout << "\n\nTesting resize and operators -, -=, =\n";

	n3 = n3 - s1;
	n3 = n3 - s2;
	n3 = n3 - s3;
	n3 -= s4;
	n3 -= s5;

	n3.print();

	std::cout << "\n\nTesting operator[]\n\n";

	Ship* temp = n3["Bill"];

	std::cout << *temp << "\n";

	std::cout << "\n\nTesting operator<\n\n";

	std::cout << std::boolalpha
		<< (n1 < n3) << " " << (n1 < n11) << " " << (n2 < n3) << " " << (n3 < n11) << "\n\n";




	Navy all[] = { n1, n2, n11, n3 };

	std::cout << "Testing default contructor\n";
	
	AllNavies world1;

	world1.print();

	std::cout << "Testing parametric contructor\n";

	AllNavies world2(all, 4);

	world2.print();

	/*
	std::cout << "Testing copy contructor\n";

	AllNavies world3 = world2;

	world3.print();

	std::cout << "Testing operator=\n";

	world1 = world2;

	world1.print();
	*/

	std::cout << "\n\nTesting operator+=\n";

	world1 += n3;

	world1.print();

	std::cout << "\n\nTesting the sort function\n";

	world2.sort();

	world2.print();


	return 0;
}