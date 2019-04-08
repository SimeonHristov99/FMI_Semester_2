#include "pch.h"
#include "Stack.hpp"
#include <iostream>

Stack::Stack() : capacity(0) {}

bool Stack::full() { return capacity == MAX_CAPACITY; }

bool Stack::empty() { return capacity == 0; }

void Stack::push(const char& c)
{
	if (!full())
	{
		str[capacity] = c;
		++capacity;
	}
	else std::cout << "Stack is full!\n";
}

void Stack::pop(char& c)
{
	if (!empty())
	{
		--capacity;
		c = str[capacity];
		
	}
	else std::cout << "Stack is empty!\n";

}

void Stack::print()
{
	char temp;

	while (!empty())
	{
		pop(temp);
		std::cout << temp << " ";
	}
}