#include "pch.h"
#include "Bookstore.hpp"
#include <iostream>
#include <cstring>

void Bookstore::copy(const Bookstore& other)
{
	if (!other.m_name || !other.m_books)
	{
		std::cout << "\n\n\tERROR: Bookstore copy() detected a nullptr!\n";
		return;
	}

	m_size = other.m_size;
	m_CAPACITY = other.m_CAPACITY;

	m_name = new char[strlen(other.m_name) + 1];
	strcpy_s(m_name, strlen(other.m_name) + 1, other.m_name);

	m_books = new Book[m_CAPACITY];
	for (size_t i = 0; i < m_size; i++)
	{
		m_books[i] = other.m_books[i];
	}
}

void Bookstore::resize()
{
	m_CAPACITY *= 2;

	Book* temp = new Book[m_CAPACITY];
	for (size_t i = 0; i < m_size; i++)
	{
		temp[i] = m_books[i];
	}

	delete[] m_books;
	m_books = temp;
}

void Bookstore::del()
{
	delete[] m_name;
	delete[] m_books;
}

bool Bookstore::isFull() const
{
	return m_size == m_CAPACITY;
}

bool Bookstore::isEmpty() const
{
	return m_size == 0;
}

Bookstore::Bookstore(const char* _name, const Book* _books, const size_t& _size)
{	
	if (!_books)
	{
		m_size = 0;
		m_CAPACITY = 8;

		m_books = new Book[m_CAPACITY];
	}
	else
	{
		m_size = _size;
		m_CAPACITY = m_size * 2;

		m_books = new Book[m_CAPACITY];
		for (size_t i = 0; i < m_size; i++)
		{
			m_books[i] = _books[i];
		}
	}

	if (!_name) { _name = "N/A"; }

	m_name = new char[strlen(_name) + 1];
	strcpy_s(m_name, strlen(_name) + 1, _name);
}

Bookstore::Bookstore(const Bookstore& other)
{
	copy(other);
}

Bookstore& Bookstore::operator=(const Bookstore& other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}

	return *this;
}

Bookstore::~Bookstore() { del(); }

Bookstore Bookstore::operator+(const Book& addMe)
{
	Bookstore temp = *this;

	if (temp.isFull())
	{
		temp.resize();
	}

	temp.m_books[temp.m_size++] = addMe;

	return temp;
}

Bookstore& Bookstore::operator+=(const Book& addMe)
{
	return *this = *this + addMe;
}

Bookstore Bookstore::operator-(const Book& removeMe)
{
	Bookstore temp = *this;

	if (temp.isEmpty())
	{
		std::cout << "\n\n\tERROR: Bookstore operator- detected an empty books array!\n";
		return *this;
	}

	temp.m_books[temp.m_size--] = removeMe;

	return temp;
}

Bookstore& Bookstore::operator-=(const Book& removeMe)
{
	return *this = *this - removeMe;
}

Book* Bookstore::operator[](const char* _name)
{
	for (size_t i = 0; i < m_size; i++)
	{
		if (m_books[i] == _name)
		{
			return &m_books[i];
		}
	}

	return NULL;
}

bool Bookstore::operator<(const Bookstore& other)
{
	double sum1, sum2;
	sum1 = sum2 = 0;

	for (size_t i = 0; i < m_size; i++)
	{
		sum1 += m_books[i].getPrice();
	}

	for (size_t i = 0; i < other.m_size; i++)
	{
		sum2 += other.m_books[i].getPrice();
	}

	return sum1 < sum2;
}

void Bookstore::print() const
{
	std::cout << "\tBookstore " << m_name << "\n";
	for (size_t i = 0; i < m_size; i++)
	{
		std::cout << m_books[i] << std::endl;
	}
}