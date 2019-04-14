#pragma once
#include "Ship.hpp"

class Navy
{
private:
	char* m_country;
	Ship* m_ships;

	size_t m_size;
	size_t m_CAPACITY;

	void copy(const Navy&);
	void resize();
	void del();

	bool isFull() const;
	bool isEmpty() const;

public:
	Navy(const Ship* _ships = nullptr, const char* _country = "N/A", size_t _size = 1);
	Navy(const Navy& other);
	Navy& operator=(const Navy& other);
	~Navy();

	Navy operator+(const Ship&) const;
	Navy& operator+=(const Ship&);

	Navy operator-(const Ship&) const;
	Navy& operator-=(const Ship&);

	Ship* operator[](const char*) const;

	bool operator<(const Navy& other) const;

	void print() const;
};