#pragma once
#include "Book.hpp"

class Bookstore
{
public:
	Bookstore(const char* _name = nullptr, const Book* _books = nullptr, const size_t& size = 1);
	Bookstore(const Bookstore&);
	Bookstore& operator=(const Bookstore&);
	~Bookstore();

	Bookstore operator+(const Book&);
	Bookstore& operator+=(const Book&);

	Bookstore operator-(const Book&);
	Bookstore& operator-=(const Book&);

	Book* operator[](const char*);

	bool operator<(const Bookstore&);

	void print() const;

private:
	char* m_name;

	Book* m_books;

	size_t m_size;
	size_t m_CAPACITY;

	void copy(const Bookstore&);
	void resize();
	void del();

	bool isFull() const;
	bool isEmpty() const;
};