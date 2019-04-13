#include "pch.h"
#include "MyString.hpp"
#include "Student.hpp"
#include <iostream>

void Student::copy(const Student& other)
{
	m_course = other.m_course;
	m_facultyNumber = other.m_facultyNumber;
	m_firstname = other.m_firstname;
	m_lastname = other.m_lastname;
	m_major = other.m_major;
	m_group = other.m_group;
}

Student::Student(const MyString& _major, unsigned _course, unsigned _group, unsigned _facultyNumber, const MyString& _fname, const MyString& _lname)
{
	m_course = _course;
	m_facultyNumber = _facultyNumber;
	m_firstname = _fname;
	m_lastname = _lname;
	m_major = _major;
	m_group = _group;
}

Student::Student(const Student& other)
{
	copy(other);
}

Student& Student::operator=(const Student& other)
{
	if (this != &other)
	{
		copy(other);
	}

	return *this;
}

bool Student::operator<(const Student& other) const
{
	if (m_major == other.m_major)
	{
		if (m_course == other.m_course)
		{
			if (m_group == other.m_group)
				return m_facultyNumber < other.m_facultyNumber;	

			return m_group < other.m_group;
		}

		return m_course < other.m_course;
	}

	return m_major < other.m_major;
}

bool Student::operator==(const unsigned& _facultyNumber) const
{
	return m_facultyNumber == _facultyNumber;
}

std::ostream& operator<<(std::ostream& out, const Student& data)
{
	return out << data.m_major << "\t" << data.m_course << "\t" << data.m_group << "\t" << data.m_facultyNumber << "\t" << data.m_firstname << "\t" << data.m_lastname;
}