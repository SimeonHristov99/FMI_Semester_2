#include "pch.h"
#include "Function.hpp"
#include <iostream>

void simplify(char str[])
{
	Stack st;

	for (size_t i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ')')
		{
			char operand1, operand2, operation;
			st.pop(operand2);
			st.pop(operand1);
			st.pop(operation);
			st.push(operation == 'M' ? (operand1 > operand2 ? operand1 : operand2) : (operand1 > operand2 ? operand2 : operand1));
		}

		else if (str[i] == 'M' || str[i] == 'm' || (str[i] >= '0' && str[i] <= '9')) st.push(str[i]);
	}

	st.print();
}