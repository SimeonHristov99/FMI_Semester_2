#include "pch.h"
#include "YesNoQuestion.hpp"
#include <iostream>

void YesNoQuestion::copy(const YesNoQuestion& other)
{
	size_t len = strlen(other.m_text) + 1;
	m_text = new char[len];
	for (size_t i = 0; i < len; i++)
	{
		m_text[i] = other.m_text[i];
	}

	m_answer = other.m_answer;
	m_points = other.m_points;
}

void YesNoQuestion::del()
{
	delete[] m_text;
}

YesNoQuestion::YesNoQuestion(const char* _text, unsigned _points, bool _answer)
{
	if (!_text)
	{
		_text = "N/A";
	}

	size_t len = strlen(_text) + 1;
	m_text = new char[len];
	for (size_t i = 0; i < len; i++)
	{
		m_text[i] = _text[i];
	}

	m_answer = _answer;
	m_points = _points;
}

YesNoQuestion::YesNoQuestion(const YesNoQuestion& other)
{
	copy(other);
}

YesNoQuestion& YesNoQuestion::operator=(const YesNoQuestion& other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}

	return *this;
}

YesNoQuestion::~YesNoQuestion()
{
	del();
}

void YesNoQuestion::ask()
{
	std::cout << "\n\nQuestion: " << m_text << "\n\t(1)True\t(0)False\nYour answer (1 or 0): ";
	std::cin >> m_answer;
}

double YesNoQuestion::grade() const
{
	return m_answer * m_points;
}