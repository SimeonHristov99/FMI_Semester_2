#include "pch.h"
#include "Org.hpp"
#include <iostream>
#include <cstring>

Org::Org(const char* _name, const unsigned& _health, const unsigned& _defence, const unsigned& _attack, const unsigned& _power) : Creature(_name, _health + _power, _defence, _attack + _power)
{
	m_power = _power;
}

bool Org::operator==(const Org& other)
{
	return !(strcmp(getName(), other.getName()))
		&& getHealth() == other.getHealth()
		&& getDefence() == other.getDefence()
		&& getAttack() == other.getAttack()
		&& m_power == other.m_power;
}

bool Org::operator<(const Org& other)
{
	return getHealth() < other.getHealth()
		&& getDefence() < other.getDefence()
		&& getAttack() < other.getAttack()
		&& m_power < other.m_power;
}

bool Org::operator!=(const Org& other)
{
	return !(*this == other);
}

bool Org::operator<=(const Org& other)
{
	return *this == other || *this < other;
}

bool Org::operator>(const Org& other)
{
	return !(*this <= other);
}

bool Org::operator>=(const Org& other)
{
	return *this == other || *this > other;
}

std::ostream& operator<<(std::ostream& out, const Org& data)
{
	return out << data.getName() << " "
		<< data.getHealth() << " "
		<< data.getAttack() << " "
		<< data.getDefence() << " "
		<< data.m_power;
}