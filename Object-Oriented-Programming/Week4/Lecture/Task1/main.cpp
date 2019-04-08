#include "pch.h"
#include "Stack.hpp"
#include "Function.hpp"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";

	// Test Stack
	/*
		char c1 = 'S', c2 = 'i', c3 = 'm', c4 = 'o';
		Stack st;
	
		st.push(c1);
		st.push(c2);
		st.push(c3);
		st.push(c4);

		st.pop(c2);

		std::cout << c2 << "\n";

		st.print();
	*/

	char test[] = "m(M(9,2),m(4,M(5,2)))";

	simplify(test);

	std::cout << std::endl;

	return 0;
}