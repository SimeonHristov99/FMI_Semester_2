#include "pch.h"
#include <iostream>
const int MAX_SIZE = 100;

struct IntArray
{
	int arr[MAX_SIZE];
	size_t size;
};

using function = int(*)(int);
using predicate = bool(*)(int);

IntArray map(IntArray& iarr, function f)
{
	for (size_t i = 0; i < iarr.size; ++i)
	{
		iarr.arr[i] = f(iarr.arr[i]);
	}

	return iarr;
}

IntArray filter(IntArray& iarr, predicate pred)
{
	size_t k = 0;

	for (size_t i = 0; i < iarr.size; ++i)
	{
		if (pred(iarr.arr[i]))
		{
			iarr.arr[k] = iarr.arr[i];
			++k;
		}
	}

	iarr.size = k;

	return iarr;
}

void printIArr(IntArray& iarr)
{
	for (size_t i = 0; i < iarr.size; ++i)
	{
		std::cout << iarr.arr[i] << " ";
	}
}

int main()
{
	IntArray iarr = { {5, 6, 5, 2, 3, 2}, 6 };
	IntArray iarr2 = { {1, 2, 3, 8, 4, 5, 7, 6}, 8 };

	map(iarr, [](int value) {return value * 2; });

	filter(iarr2, [](int value) {return value % 2 == 0; });

	printIArr(iarr);

	std::cout << std::endl;

	printIArr(iarr2);

	return 0;
}