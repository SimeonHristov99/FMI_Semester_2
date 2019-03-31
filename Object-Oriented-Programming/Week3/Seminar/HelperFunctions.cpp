#include "pch.h"
#include <iostream>

int getSizeStr(const char str[])
{
	if (str[0] == '\0')
		return 1;

	return 1 + getSizeStr(str + 1);
}

void copyStr(char to[], const char from[])
{
	if (from[0] == '\0')
	{
		to[0] = '\0';
		return;
	}

	to[0] = from[0];

	return copyStr(to + 1, from + 1);
}

bool eqStr(const char* str0, const char* str1)
{
	if (str0[0] == '\0' && str1[0] == '\0')
		return true;

	if (str0[0] != str1[0])
		return false;

	return eqStr(str0 + 1, str1 + 1);
}