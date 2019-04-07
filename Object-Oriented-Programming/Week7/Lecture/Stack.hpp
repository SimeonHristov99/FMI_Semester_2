#pragma once

const size_t MAX_SIZE = 100;

class Stack
{
private:
	size_t top;
	char str[MAX_SIZE];

public:
	Stack();
	void push(const char&);
	void pop(char&);
	bool empty() const;
	bool full() const;
	void print();
};