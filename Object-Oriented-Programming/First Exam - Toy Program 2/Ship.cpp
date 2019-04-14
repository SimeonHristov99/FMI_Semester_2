#include "pch.h"
#include "Ship.hpp"
#include <iostream>
#include <cstring>

void Ship::copy(const Ship& other)
{
	if (!(other.m_type[0] == 'b' && (other.m_type[1] != 'b' || other.m_type[1] != 'c') && other.m_type[2] == '\0'))
	{
		std::cout << "\n\n\tERROR: Invalid ship type detected by ship copy()!\n";
		return;
	}

	m_name = new char[strlen(other.m_name) + 1];

	strcpy_s(m_name, strlen(other.m_name) + 1, other.m_name);
	strcpy_s(m_type, 3, other.m_type);

	m_year = other.m_year;
	m_weapons = other.m_weapons;
}

void Ship::del()
{
	delete[] m_name;
}

Ship::Ship(const char* _name, unsigned _year, unsigned _weapons, const char* _type)
{
	if (!(_type[0] == 'b' && (_type[1] != 'b' || _type[1] != 'c') && _type[2] == '\0'))
	{
		std::cout << "\n\n\tERROR: Invalid ship type detected by ship copy()!\n";
		return;
	}

	if (!_name)
	{
		_name = "N/A";
	}

	m_name = new char[strlen(_name) + 1];

	strcpy_s(m_name, strlen(_name) + 1, _name);
	strcpy_s(m_type, 3, _type);

	m_year = _year;
	m_weapons = _weapons;
}

Ship::Ship(const Ship& other)
{
	copy(other);
}

Ship& Ship::operator=(const Ship& other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}

	return *this;
}

Ship::~Ship() { del(); }

bool Ship::operator<(const Ship& other) const
{
	return m_weapons < other.m_weapons;
}

unsigned Ship::getNumWeapons() const
{
	return m_weapons;
}

bool Ship::operator==(const Ship& other) const
{
	return strcmp(m_name, other.m_name) == 0;
}

bool Ship::operator==(const char* _name) const
{
	return strcmp(m_name, _name) == 0;
}

std::ostream& operator<<(std::ostream& out, const Ship& data)
{
	return out << data.m_type << "\t" << data.m_year << "\t" << data.m_name << "\t" << data.m_weapons;
}