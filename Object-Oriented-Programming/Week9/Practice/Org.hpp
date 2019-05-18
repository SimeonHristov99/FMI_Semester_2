#pragma once
#include "Creature.hpp"
#include <iostream>

class Org : public Creature
{
public:
	Org(const char* _name = "N/A", const unsigned& _health = 100, const unsigned& _defence = 100, const unsigned& _attack = 100, const unsigned& _power = 100);

	bool operator==(const Org&);
	bool operator<(const Org&);
	bool operator!=(const Org&);
	bool operator<=(const Org&);
	bool operator>(const Org&);
	bool operator>=(const Org&);

	friend std::ostream& operator<<(std::ostream& out, const Org& data);
private:
	unsigned m_power;
};