#pragma once
#include <iostream>
#include "MyString.hpp"

class Student
{
private:
	unsigned m_course;
	unsigned m_facultyNumber;
	unsigned m_group;

	MyString m_firstname;
	MyString m_lastname;

	MyString m_major;

	void copy(const Student&);
public:

	Student(const MyString& _major = "N/A", unsigned _course = 1, unsigned _group = 1, unsigned _facultyNumber = 11111, const MyString& _fname = "N/A", const MyString& _lname = "N/A");
	Student(const Student& other);
	Student& operator=(const Student& other);
	~Student() = default;

	bool operator<(const Student& other) const;
	bool operator==(const unsigned&) const;

	friend std::ostream& operator<<(std::ostream& out, const Student& data);
};