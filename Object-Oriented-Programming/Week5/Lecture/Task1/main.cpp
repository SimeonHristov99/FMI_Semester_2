#include "pch.h"
#include <iostream>
const size_t CAPACITY = 301;

class Stack
{
public:
	Stack()
	{
		m_top = -1;
	}

	void push(const char& element)
	{
		if (isFull())
		{
			std::cout << "\n\n\t\tERROR: Stack push() detected a full stack!\n\n";
			return;
		}

		m_arr[++m_top] = element;
	}

	void pop(char& element)
	{
		if (isEmpty())
		{
			std::cout << "\n\n\t\tERROR: Stack pop() detected an empty stack!\n\n";
			return;
		}

		element = m_arr[m_top--];
	}

	bool isEmpty() const
	{
		return m_top == -1;
	}

	bool isFull() const
	{
		return m_top == CAPACITY - 1;
	}

	void print()
	{
		while (!isEmpty())
		{
			char temp;
			pop(temp);
			std::cout << temp;
		}
	}

private:
	char m_arr[CAPACITY];
	int m_top;

};

bool isDigit(const char& c)
{
	return c >= '0' && c <= '9';
}

void simplify(const char arr[], const size_t& size)
{
	Stack functions, digits;

	for (size_t i = 0; i < size; ++i)
	{		
		if (arr[i] == 'f' || arr[i] == 'g' || arr[i] == 'h')
		{
			functions.push(arr[i]);
		}
		else if (isDigit(arr[i]))
		{
			digits.push(arr[i]);
		}
		else if (arr[i] == ')')
		{
			char function;
			functions.pop(function);

			if (function == 'f')
			{
				char number;
				digits.pop(number);

				if (number - '0' == 9)
				{
					digits.push('0');
				}
				else
				{
					digits.push(((number - '0') + 1) + '0');
				}
			}
			else if(function == 'g')
			{
				char number;
				digits.pop(number);

				if (number - '0' == 0)
				{
					digits.push('9');
				}
				else
				{
					digits.push(((number - '0') - 1) + '0');
				}
			}
			else if (function == 'h')
			{
				char argument1;
				char argument2;

				digits.pop(argument2);
				digits.pop(argument1);

				digits.push((((argument1 - '0') + (argument2 - '0')) % 10) + '0');
			}
		}
	}

	digits.print();
}

int main()
{
	std::cout << "Hello World!\n";

	char expression[17] = { 'h', '(', 'g', '(', 'f', '(', '6', ')', ')', ',', 'h', '(', '5', ',', '4', ')', ')' };
	char expression2[4] = { 'f', '(','9', ')' };

	simplify(expression, 17);
	std::cout << "\n";
	simplify(expression2, 4);

	std::cout << "\n";

	return 0;
}