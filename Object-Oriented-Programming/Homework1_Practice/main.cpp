#include "pch.h"
#include "Queue.cpp" // Terrible (but if it has to be templated and in defferent files I have no choice :/
#include <iostream>

int main()
{
    std::cout << "Testing default constructor:\n\n";

	Queue<int> q1;

	q1.print();

	std::cout << "\n\nTesting parametric constructor:\n\n";

	int arr[10] = { 9, 87, 6, 4, 2, 3, 10, 1000, 486, 123 };

	Queue<int> q2(arr, 10);

	//q2.print();

	std::cout << "\n\nTesting copy() constructor:\n\n";

	Queue<int> q3 = q2;

	q3.print();

	std::cout << "\n\nTesting pop_front() (removing 9 and 87 from q2):\n\n";

	q2.pop_front();
	q2.pop_front();

	q2.print();

	std::cout << "\n\nTesting operator=, push_back() and getSize():\n\n";

	q1.push_back(5);
	q1.push_back(15);
	q1.push_back(25);
	q1.push_back(35);
	q1.push_back(45);
	q1.push_back(55);
	q1.push_back(65);
	q1.push_back(75);
	q1.push_back(85);

	Queue<int> q4;

	q4 = q1;

	std::cout << "Size before = " << q4.getSize() << std::endl;

	q4.print();

	std::cout << "\nSize after = " << q4.getSize() << std::endl;

	std::cout << "\n\nTesting front():\n\n";

	Queue<char> q10;

	q10.push_back('S');
	q10.push_back('i');
	q10.push_back('m');
	q10.push_back('o');
	
	std::cout << "Index 0 = " << q10.front(); q10.pop_front(); std::cout << "\n";
	std::cout << "Index 1 = " << q10.front(); q10.pop_front(); std::cout << "\n";
	std::cout << "Index 2 = " << q10.front(); q10.pop_front(); std::cout << "\n";
	std::cout << "Index 3 = " << q10.front(); std::cout << "\n";

	std::cout << "\nCalling print() (expect only 'o'):\n";
	q10.print();

	std::cout << "\n\n";

	return 0;
}