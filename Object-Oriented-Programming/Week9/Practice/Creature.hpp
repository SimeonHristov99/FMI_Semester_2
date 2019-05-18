#pragma once
#include <iostream>

class Creature
{
public:
	Creature(const char* _name = "N/A", const unsigned& _health = 100, const unsigned& _defence = 100, const unsigned& _attack = 100);
	Creature(const Creature&);
	Creature& operator=(const Creature&);
	~Creature();

	bool operator==(const Creature&) const;
	bool operator<(const Creature&) const;
	bool operator!=(const Creature&) const;
	bool operator<=(const Creature&) const;
	bool operator>(const Creature&) const;
	bool operator>=(const Creature&) const;

	void setName(const char* _name = "N/A");
	const char* getName() const;

	void setHealth(const unsigned& _health = 100);
	unsigned getHealth() const;

	void setDefence(const unsigned& _defence = 100);
	unsigned getDefence() const;

	void setAttack(const unsigned& _attack = 100);
	unsigned getAttack() const;

	friend std::ostream& operator<<(std::ostream& out, const Creature& data);

private:
	char* m_name;
	unsigned m_health;
	unsigned m_defence;
	unsigned m_attack;

	void copy(const Creature&);
	void del();
};