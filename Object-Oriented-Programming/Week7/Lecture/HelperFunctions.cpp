#include "pch.h"
#include <iostream>

#include "HelperFunctions.hpp"
#include "Stack.hpp"

size_t getSizeStr(const char* str)
{
	if (str[0] == '\0')
		return 1;

	return 1 + getSizeStr(str + 1);
}

void simplify(char* str)
{
	Stack booleanStack;
	Stack operationsStack;

	for (char* c = str; *c; ++c)
	{
		if (*c == '+' || *c == '*' || *c == '!')
		{
			operationsStack.push(*c);
		}

		else if (*c == 't' || *c == 'f')
		{
			char exclamation;

			operationsStack.pop(exclamation);

			if (exclamation == '!')
			{
				if (*c == 't')
				{
					char temp = 'f';
					booleanStack.push(temp);
				}
				else
				{
					char temp = 't';
					booleanStack.push(temp);
				}
				if (!operationsStack.empty())
				{
					operationsStack.pop(exclamation);

					char operand2, operand1, result;

					
					booleanStack.pop(operand1);
					booleanStack.pop(operand2);

					operand1 == 't' ? operand1 = '1' : operand1 = '0';
					operand2 == 't' ? operand2 = '1' : operand2 = '0';

					if (exclamation == '+')
					{
					
						result = ((operand2 - '0') || (operand1 - '0'));
					}
					else
					{
						result = ((operand2 - '0') && (operand1 - '0'));
					}
					if (result)
					{
						result = 't';
					}
					else
					{
						result = 'f';
					}
					booleanStack.push(result);
				}
			}			
		}
	}

	booleanStack.print();
}