/* Created by: Simeon Hristov
 *
 * Faculty Number: 71845
 *
 * Major: Information Systems
 *
 * Group: III
*/

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

void simplify(const char arr[], const size_t& size)
{
	Stack boolean, operations;

	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == 't' || arr[i] == 'f')
		{
			boolean.push(arr[i]);

			while (!operations.isEmpty())
			{
				char operation;

				operations.pop(operation);

				switch (operation)
				{
				case '+':
				{
					char operand2;
					boolean.pop(operand2);

					char operand1;
					boolean.pop(operand1);

					if (operand2 == 't' || operand1 == 't')
					{
						boolean.push('t');
					}

					else
					{
						boolean.push('f');
					}

					break;
				}

				case '*':
				{
					char operand2;
					boolean.pop(operand2);

					char operand1;
					boolean.pop(operand1);

					if (operand2 == 't')
					{
						if (arr[i] == 't')
						{
							boolean.push('t');
						}

						else
						{
							boolean.push('f');
						}
					}

					else
					{
						boolean.push('f');
					}

					break;
				}
				default:
					char operand;
					boolean.pop(operand);

					if (operand == 't')
					{
						boolean.push('f');
					}

					else
					{
						boolean.push('t');
					}
				}
			}
				
		}

		else
		{
			operations.push(arr[i]);
		}
	}

	boolean.print();
}

int main()
{
	/*
		std::cout << "Testing default constructor:\n\n";

		Stack s1;

		s1.print();

		std::cout << "\n\nTesting push():\n\n";

		s1.push('t');
		s1.push('f');
		s1.push('t');
		s1.push('t');
		s1.push('f');
		s1.push('f');

		s1.print();

	
		// char temp;
		// s1.pop(temp);
		// std::cout << temp;
	

		std::cout << "\n\nTesting pop():\n\n";

		s1.push('S');
		char fst;
		s1.pop(fst);
		std::cout << fst;

		std::cout << "\n\nTesting isEmpty():\n\n";

		std::cout << std::boolalpha << "Should be true: " << s1.isEmpty();

		std::cout << "\n\nTesting isFull():\n\n";

		std::cout << std::boolalpha << "Should be false: " << s1.isFull();
	*/

	char test[] = "!t*!f";

	simplify(test, 5);

	std::cout << "\n\n";

	return 0;
}