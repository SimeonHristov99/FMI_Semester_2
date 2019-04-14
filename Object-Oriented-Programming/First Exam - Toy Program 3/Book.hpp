#pragma once
#include <iostream>

class Book
{
public:
	Book(const char* _name = nullptr, const char* _author = nullptr, unsigned year = 1500, double price = 1);
	Book(const Book&);
	Book& operator=(const Book&);
	~Book();

	bool operator==(const Book&) const; // Eq names
	bool operator==(const char*) const;

	double getPrice() const;

	friend std::ostream& operator<<(std::ostream& out, const Book& data);

private:
	char* m_name;
	char* m_author;
	unsigned m_year;
	double m_price;

	void copy(const Book&);
	void del();
};