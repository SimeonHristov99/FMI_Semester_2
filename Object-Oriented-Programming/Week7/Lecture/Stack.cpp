#include "pch.h"
#include <iostream>

#include "Stack.hpp"

Stack::Stack() { top = 0; str[0] = 'E'; }

bool Stack::empty() const
{
	return top == 0;
}

bool Stack::full() const
{
	return top == MAX_SIZE - 1;
}

void Stack::push(const char& newMember)
{
	if (!full())
	{
		++top;
		str[top] = newMember;
		
	}
	else exit(1);
}

void Stack::pop(char& result)
{
	if (!empty())
	{
		result = str[top];
		--top;
	}
	else exit(1);
}

void Stack::print()
{
	char c = str[0];
	while (!empty())
	{
		pop(c);
		std::cout << c << " ";
	}
}