#pragma once
#include "Creature.hpp"
#include <iostream>

class Elf : public Creature
{
public:
	Elf(const char* _name = "N/A", const unsigned& _health = 100, const unsigned& _defence = 100, const unsigned& _attack = 100);

	void effect();

	friend std::ostream& operator<<(std::ostream& out, const Elf& data);
};