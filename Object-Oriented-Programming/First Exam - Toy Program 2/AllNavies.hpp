#pragma once
#include "Ship.hpp"
#include "Navy.hpp"

class AllNavies
{
private:
	Navy* m_navies;

	size_t m_size;
	size_t m_CAPACITY;

	void copy(const AllNavies&);
	void resize();
	void del();

	bool isFull() const;

public:
	AllNavies(const Navy* _navies = nullptr, size_t _size = 1);
	AllNavies(const AllNavies&);
	AllNavies& operator=(const AllNavies&);
	~AllNavies();

	AllNavies& operator+=(const Navy&);

	void sort();

	void print() const;
};