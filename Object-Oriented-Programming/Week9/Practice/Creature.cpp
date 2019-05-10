#include "pch.h"
#include "Creature.hpp"
#include <iostream>
#include <cstring>

void Creature::setName(const char* _name)
{
	if (!_name)
	{
		_name = "N/A";
	}

	m_name = new char[strlen(_name) + 1];
	strcpy_s(m_name, strlen(_name) + 1, _name);
}
const char* Creature::getName() const
{
	return m_name;
}
void Creature::setHealth(const unsigned& _health)
{
	m_health = _health;
}
unsigned Creature::getHealth() const
{
	return m_health;
}
void Creature::setDefence(const unsigned& _defence)
{
	m_defence = _defence;
}
unsigned Creature::getDefence() const
{
	return m_defence;
}
void Creature::setAttack(const unsigned& _attack)
{
	m_attack = _attack;
}
unsigned Creature::getAttack() const
{
	return m_attack;
}

void Creature::copy(const Creature& other)
{
	setName(other.m_name);
	setHealth(other.m_health);
	setDefence(other.m_defence);
	setAttack(other.m_attack);
}
void Creature::del()
{
	delete[] m_name;
}

Creature::Creature(const char* _name, const unsigned& _health, const unsigned& _defence, const unsigned& _attack)
{
	setName(_name);
	setHealth(_health);
	setDefence(_defence);
	setAttack(_attack);
}
Creature::Creature(const Creature& other)
{
	copy(other);
}
Creature& Creature::operator=(const Creature& other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}

	return *this;
}
Creature::~Creature()
{
	del();
}

bool Creature::operator==(const Creature& other) const
{
	return !strcmp(other.m_name, m_name)
		&& other.m_health == m_health
		&& other.m_attack == m_attack
		&& other.m_defence == m_defence;
}
bool Creature::operator<(const Creature& other) const
{
	return m_health < other.m_health && m_attack < other.m_attack && m_defence < other.m_defence;
}
bool Creature::operator<=(const Creature& other) const
{
	return *this < other || *this == other;
}
bool Creature::operator!=(const Creature& other) const
{
	return !(*this == other);
}
bool Creature::operator>(const Creature& other) const
{
	return !(*this <= other);
}

bool Creature::operator>=(const Creature& other) const
{
	return *this == other || *this > other;
}

std::ostream& operator<<(std::ostream& out, const Creature& data)
{
	return out << data.m_name << " "
		<< data.m_health << " "
		<< data.m_attack << " "
		<< data.m_defence;
}