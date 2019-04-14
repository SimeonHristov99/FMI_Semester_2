#include "pch.h"
#include "Navy.hpp"
#include <iostream>
#include <cstring>

void Navy::copy(const Navy& other)
{
	if (!other.m_country)
	{
		std::cout << "\n\n\tERROR: Navy copy() detected that the source's country is nullptr!\n";
		return;
	}

	m_country = new char[strlen(other.m_country) + 1];
	strcpy_s(m_country, strlen(other.m_country) + 1, other.m_country);

	if (!other.m_ships)
	{
		m_ships = nullptr;
		m_size = 0;
		m_CAPACITY = 8;
	}
	else
	{
		m_size = other.m_size;
		m_CAPACITY = other.m_CAPACITY;

		m_ships = new Ship[m_CAPACITY];
		for (size_t i = 0; i < m_size; i++)
		{
			m_ships[i] = other.m_ships[i];
		}
	}
}

void Navy::resize()
{
	m_CAPACITY *= 2;

	Ship* temp = new Ship[m_CAPACITY];

	for (size_t i = 0; i < m_size; i++)
	{
		temp[i] = m_ships[i];
	}

	delete[] m_ships;
	m_ships = temp;
}

void Navy::del()
{
	delete[] m_ships;
	delete[] m_country;
}

bool Navy::isFull() const { return m_size == m_CAPACITY; }
bool Navy::isEmpty() const { return m_size == 0; }

Navy::Navy(const Ship* _ships, const char* _country, size_t _size)
{
	if (!_country)
	{
		std::cout << "\n\n\tERROR: Navy parametric constructor detected that country received nullptr!\n";
		return;
	}

	m_country = new char[strlen(_country) + 1];
	strcpy_s(m_country, strlen(_country) + 1, _country);

	if (!_ships)
	{
		m_ships = nullptr;
		m_size = 0;
		m_CAPACITY = 8;
	}
	else
	{
		m_CAPACITY = _size * 2;
		m_size = _size;

		m_ships = new Ship[m_CAPACITY];

		for (size_t i = 0; i < m_size; i++)
		{
			m_ships[i] = _ships[i];
		}
	}
}

Navy::Navy(const Navy& other)
{
	copy(other);
}

Navy& Navy::operator=(const Navy& other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}

	return *this;
}

Navy::~Navy() { del(); }

Navy Navy::operator+(const Ship& addMe) const
{
	for (size_t i = 0; i < m_size; i++)
	{
		if (m_ships[i] == addMe)
		{
			std::cout << "\n\n\tERROR: Navy operator+ detected that a ship with this name is already in the Navy!\n";
			return *this;
		}
	}

	Navy temp = *this;

	if (isFull()) { temp.resize(); }

	if (!m_ships)
	{
		temp.m_ships = new Ship[m_CAPACITY];
	}

	temp.m_ships[temp.m_size++] = addMe;

	return temp;
}

Navy& Navy::operator+=(const Ship& addMe)
{
	return *this = *this + addMe;
}

Navy Navy::operator-(const Ship& removeMe) const
{
	if (isEmpty())
	{
		std::cout << "\n\n\tERROR: Navy operator- detected an empty ship array!\n";
		return *this;
	}

	Navy temp = *this;
	for (size_t i = 0; i < temp.m_size; i++)
	{
		if (temp.m_ships[i] == removeMe)
		{
			temp.m_ships[i] = temp.m_ships[temp.m_size - 1];
			--temp.m_size;
			return temp;
		}
	}

	std::cout << "\n\n\tERROR: Navy operator- detected that there is no such ship to be removed!\n";
	return *this;
}

Navy& Navy::operator-=(const Ship& other)
{
	return *this = *this - other;
}

Ship* Navy::operator[](const char* _name) const
{
	for (size_t i = 0; i < m_size; i++)
	{
		if (m_ships[i] == _name)
		{
			return &m_ships[i];
		}
	}

	return NULL;
}

bool Navy::operator<(const Navy& other) const
{
	size_t limit = m_size < other.m_size ? other.m_size : m_size;
	unsigned sum1, sum2;
	sum1 = sum2 = 0;

	for (size_t i = 0; i < m_size; i++)
	{
		sum1 += m_ships[i].getNumWeapons();
	}

	for (size_t i = 0; i < other.m_size; i++)
	{
		sum2 += other.m_ships[i].getNumWeapons();
	}

	return sum1 < sum2;
}

void Navy::print() const
{
	std::cout << "\n\tNavy: " << m_country << "\n";
	for (size_t i = 0; i < m_size; i++)
	{
		std::cout << m_ships[i] << std::endl;
	}
}