#include "pch.h"
#include "Book.hpp"
#include <iostream>
#include <cstring>

void Book::copy(const Book& other)
{
	if (!other.m_name || !other.m_author)
	{
		std::cout << "\n\n\tERROR: Book copy() has detected a nullptr!\n";
		return;
	}

	m_name = new char[strlen(other.m_name) + 1];
	strcpy_s(m_name, strlen(other.m_name) + 1, other.m_name);

	m_author = new char[strlen(other.m_author) + 1];
	strcpy_s(m_author, strlen(other.m_author) + 1, other.m_author);

	m_year = other.m_year;
	m_price = other.m_price;
}

void Book::del()
{
	delete[] m_name; 
	delete[] m_author;
}

Book::Book(const char* _name, const char* _author, unsigned _year, double _price)
{
	if (!_name) { _name = "N/A"; }

	if (!_author) { _author = "N/A"; }

	m_name = new char[strlen(_name) + 1];
	strcpy_s(m_name, strlen(_name) + 1, _name);

	m_author = new char[strlen(_author) + 1];
	strcpy_s(m_author, strlen(_author) + 1, _author);

	m_year = _year;
	m_price = _price;
}

Book::Book(const Book& other)
{
	copy(other);
}

Book& Book::operator=(const Book& other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}

	return *this;
}

Book::~Book() { del(); }

bool Book::operator==(const Book& other) const
{
	return strcmp(m_name, other.m_name) == 0;
}

bool Book::operator==(const char* _name) const
{
	return strcmp(m_name, _name) == 0;
}

double Book::getPrice() const { return m_price; }

std::ostream& operator<<(std::ostream& out, const Book& data)
{
	return out << data.m_name << "\t" << data.m_author << "\t" << data.m_year << "\t" << data.m_price;
}