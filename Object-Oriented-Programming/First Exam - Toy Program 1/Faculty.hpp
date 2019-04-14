#pragma once
#include "Student.hpp"

class Faculty
{
private:
	MyString m_name;
	Student* m_students;

	size_t m_size;
	size_t m_CAPACITY;

	bool isFull() const;
	bool isEmpty() const;

	void copy(const Faculty& other);
	void resize();
	void del();

public:
	Faculty(const MyString& _name = "N/A", Student* students = nullptr, size_t size = 0, size_t _capacity = 8);
	Faculty(const Faculty& other);
	Faculty& operator=(const Faculty& other);
	~Faculty();

	void sortStudents();

	Faculty& operator-=(const unsigned&); // Remove a student through their faculty number
	Faculty& operator+=(const Student&); // Add a student

	void print() const;
};