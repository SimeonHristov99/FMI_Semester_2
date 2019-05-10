#include "pch.h"
#include "Elf.hpp"
#include <iostream>

Elf::Elf(const char* _name, const unsigned& _health, const unsigned& _defence, const unsigned& _attack)
	: Creature(_name, _health, _defence, _attack) {}

void Elf::effect()
{
	setDefence(getDefence() + 100);
}

std::ostream& operator<<(std::ostream& out, const Elf& data)
{
	return out << data.getName() << " "
		<< data.getHealth() << " "
		<< data.getAttack() << " "
		<< data.getDefence();
}