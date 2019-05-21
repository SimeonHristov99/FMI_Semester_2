#pragma once

class Question
{
public:
	virtual void ask() = 0;
	virtual double grade() const = 0;

	virtual ~Question() = default;
};