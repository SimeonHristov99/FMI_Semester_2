#include "pch.h"
#include "MyString.hpp"
#include <iostream>

size_t getSizeStr(const char* str)
{
	if (!str)
	{
		std::cout << "\n\n\tERROR:The function getSizeStr detected a nullptr!\n";
		return 0;
	}

	size_t i = 0;
	while (str[i] != '\0')
		++i;

	return i + 1;
}

void MyString::copy(const char* str)
{
	if (!str)
	{
		std::cout << "\n\n\tERROR:The function copy detected a nullptr!\n";
		return;
	}

	m_str = new char[getSizeStr(str)];

	size_t i = 0;

	for (; str[i] != '\0'; i++)
		m_str[i] = str[i];

	m_str[i] = '\0';
}

void MyString::del()
{
	delete[] m_str;
}

MyString::MyString(const char* _str)
{
	copy(_str);
}

MyString::MyString(const MyString& other)
{
	copy(other.m_str);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		del();
		copy(other.m_str);
	}

	return *this;
}

MyString::~MyString() { del(); }

bool MyString::operator==(const MyString& other) const
{
	size_t i = 0;
	for (; m_str[i] != '\0'; i++)
	{
		if (m_str[i] != other.m_str[i])
			return false;
	}

	return m_str[i] == other.m_str[i];
}

bool MyString::operator<(const MyString& other) const
{
	size_t i = 0;
	for (; m_str[i] != '\0'; i++)
	{
		if (m_str[i] != other.m_str[i])
			return m_str[i] < other.m_str[i];
	}

	return m_str[i + 1] = other.m_str[i + 1];
}

std::ostream& operator<<(std::ostream& out, const MyString& data)
{
	return out << data.m_str;
}