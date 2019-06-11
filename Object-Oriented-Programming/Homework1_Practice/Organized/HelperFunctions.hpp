#pragma once

size_t getSizeStr(const char str[]); // modified to count the '\0' as well

void copyStr(char to[], const char from[]);

bool eqStr(const char str0[], const char str1[]);

char actionMenu();