#include "pch.h"
#include <iostream>

const unsigned int MAX_SIZE = 100;

class Stack
{
private:
	unsigned int capacity;
	unsigned int arr[MAX_SIZE];

public:
	Stack();
	bool isEmpty() const;
	bool isFull() const;

	void push(int x);
	void pop();

	void print();
};


Stack::Stack() : capacity(0) { arr[0] = 0; }

inline bool Stack::isEmpty() const { return capacity == 0; }

inline bool Stack::isFull() const { return capacity == MAX_SIZE - 1; }

void Stack::push(int x)
{
	if (!(isFull()))
	{
		arr[capacity] = x;
		++capacity;
	}
	else
		std::cout << "\n\n\tERROR: Stack overflow! Program may behave unexpectedly after this message!\n";
}

void Stack::pop()
{
	std::cout << arr[capacity - 1];
	--capacity;
}

void Stack::print()
{
	while (capacity > 0)
	{
		pop();
	}

}

int main()
{
	int number = -1;
	Stack result;

	do
	{
		std::cout << "Enter a positive number: ";
		std::cin >> number;
	} while (number <= 0);

	std::cout << "\n\tThe number " << number << " in binary is ";

	while (number != 0)
	{
		result.push(number % 2);
		number /= 2;
	}

	result.print();

	std::cout << std::endl;

	return 0;
}