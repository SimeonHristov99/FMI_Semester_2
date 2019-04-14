#include "pch.h"
#include <iostream>
#include "AllNavies.hpp"

void AllNavies::copy(const AllNavies& other)
{
	if (!other.m_navies)
	{
		std::cout << "\n\n\tERROR: AllNavies copy() detected that the source has a nullptr!\n";
		return;
	}

	m_size = other.m_size;
	m_CAPACITY = other.m_CAPACITY;

	m_navies = new Navy[m_CAPACITY];

	for (size_t i = 0; i < m_size; i++)
	{
		m_navies[i] = other.m_navies[i];
	}
}

void AllNavies::resize()
{
	m_CAPACITY *= 2;

	Navy* temp = new Navy[m_CAPACITY];

	for (size_t i = 0; i < m_size; i++)
	{
		temp[i] = m_navies[i];
	}

	delete[] m_navies;
	m_navies = temp;
}

void AllNavies::del() { delete[] m_navies; }

bool AllNavies::isFull() const { return m_size == m_CAPACITY; }

AllNavies::AllNavies(const Navy* _navies, size_t _size)
{
	if (!_navies)
	{
		m_navies = nullptr;
		m_size = 0;
		m_CAPACITY = 8;
	}
	else
	{
		m_size = _size;
		m_CAPACITY = m_size * 2;

		m_navies = new Navy[m_CAPACITY];

		for (size_t i = 0; i < m_size; i++)
		{
			m_navies[i] = _navies[i];
		}
	}	
}

AllNavies::AllNavies(const AllNavies& other)
{
	copy(other);
}

AllNavies& AllNavies::operator=(const AllNavies& other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}

	return *this;
}

AllNavies::~AllNavies() { del(); }

AllNavies& AllNavies::operator+=(const Navy& other)
{
	if (isFull())
	{
		resize();
	}

	if (!m_navies)
	{
		m_navies = new Navy[m_CAPACITY];
	}

	m_navies[m_size++] = other;

	return *this;
}

void AllNavies::sort()
{
	for (size_t i = 0; i < m_size - 1; i++)
	{
		unsigned minIndex = i;
		for (size_t j = i + 1; j < m_size; j++)
		{
			if (m_navies[j] < m_navies[minIndex])
			{
				minIndex = j;
			}
		}
		Navy temp = m_navies[i];
		m_navies[i] = m_navies[minIndex];
		m_navies[minIndex] = temp;
	}
}

void AllNavies::print() const
{
	for (size_t i = 0; i < m_size; i++)
	{
		m_navies[i].print();
	}
}