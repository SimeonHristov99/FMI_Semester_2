#include "pch.h"
#include "Faculty.hpp"
#include <iostream>

void Faculty::copy(const Faculty& other)
{
	m_name = other.m_name;
	m_size = other.m_size;
	m_CAPACITY = other.m_CAPACITY;

	m_students = new Student[other.m_CAPACITY];

	for (size_t i = 0; i < m_size; i++)
	{
		m_students[i] = other.m_students[i];
	}
}

void Faculty::resize()
{
	m_CAPACITY *= 3 + 1;

	Student* temp = new Student[m_CAPACITY];

	for (size_t i = 0; i < m_size; i++)
		temp[i] = m_students[i];

	delete[] m_students;
	m_students = temp;
}

void Faculty::del() { delete[] m_students; }

Faculty::Faculty(const MyString& _name, Student* _students, size_t _size, size_t _CAPACITY)
{
	if (!_students)
	{
		std::cout << "\n\n\tERROR: Faculty constructor detected a nullptr!\n";
		return;
	}

	m_name = _name;
	m_size = _size;
	m_CAPACITY = _CAPACITY;

	m_students = new Student[_CAPACITY];

	for (size_t i = 0; i < m_size; i++)
	{
		m_students[i] = _students[i];
	}
}

Faculty::Faculty(const Faculty& other)
{
	copy(other);
}

Faculty& Faculty::operator=(const Faculty& other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}

	return *this;
}

Faculty::~Faculty() { del(); }

bool Faculty::isFull() const
{
	return m_size == m_CAPACITY - 1;
}

bool Faculty::isEmpty() const
{
	return m_size == 0;
}

void Faculty::sortStudents()
{
	for (size_t i = 0; i < m_size - 1; i++)
	{
		unsigned minIndex = i;
		for (size_t j = i +1; j < m_size; j++)
		{
			if (m_students[j] < m_students[minIndex])
				minIndex = j;
		}

		Student temp = m_students[i];
		m_students[i] = m_students[minIndex];
		m_students[minIndex] = temp;
	}
}

Faculty& Faculty::operator-=(const unsigned& removeMe)
{
	if (isEmpty())
	{
		std::cout << "\n\n\t ERROR: A function detected an empty array of students!\n";
		return *this;
	}

	for (size_t i = 0; i < m_size; i++)
	{
		if (m_students[i] == removeMe)
		{
			for (size_t j = i + 1; j < m_size; j++)
			{
				m_students[j - 1] = m_students[j];
			}
			--m_size;
			std::cout << "\nStudent removed successfully!\n";
			return *this;
		}
	}

	std::cout << "\n\nCould not find a student with the factulty number of " << removeMe << "!\n";

	return *this;
}

Faculty& Faculty::operator+=(const Student& addMe)
{
	if (isFull())
		resize();

	m_students[m_size++] = addMe;

	return *this;
}

void Faculty::print() const
{
	for (size_t i = 0; i < m_size; i++)
	{
		std::cout << m_students[i] << std::endl;
	}
}