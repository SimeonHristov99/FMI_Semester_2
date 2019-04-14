#pragma once
#include <iostream>

const unsigned MAX_CLASS = 3;

class Ship
{
private:
	char* m_name;
	unsigned m_year;
	unsigned m_weapons;
	char m_type[MAX_CLASS];

	void copy(const Ship& other);
	void del();

public:
	Ship(const char* _name = "N/A", unsigned _year = 1500, unsigned _weapons = 0, const char* _type = "bb");
	Ship(const Ship& other);
	Ship& operator=(const Ship& other);
	~Ship();

	unsigned getNumWeapons() const;

	bool operator<(const Ship&) const; // When this has less number of weapons
	bool operator==(const Ship&) const; // When they have eq names
	bool operator==(const char*) const;

	friend std::ostream& operator<<(std::ostream&, const Ship&);
};