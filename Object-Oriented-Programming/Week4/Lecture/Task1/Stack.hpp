#pragma once

const size_t MAX_CAPACITY = 100;

class Stack
{
	size_t capacity;
	char str[MAX_CAPACITY];

public:
	Stack();
	bool full();
	bool empty();
	void push(const char& c);
	void pop(char& c);

	void print();
};