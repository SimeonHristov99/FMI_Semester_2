#include "pch.h"
#include "MultipleChoiceQuestion.hpp"
#include <iostream>

void MultipleChoiceQuestion::copy(const MultipleChoiceQuestion& other)
{
	size_t len1 = strlen(other.m_text) + 1;
	m_text = new char[len1];
	for (size_t i = 0; i < len1; i++)
	{
		m_text[i] = other.m_text[i];
	}

	size_t len2 = strlen(other.m_answers) + 1;
	m_answers = new char[len2];
	for (size_t i = 0; i < len2; i++)
	{
		m_answers[i] = other.m_answers[i];
	}

	size_t len3 = 0;

	while (other.m_correct[len3] != 0)
	{
		++len3;
	}

	m_correct = new unsigned[len3];

	for (size_t i = 0; i < len3; i++)
	{
		m_correct[i] = other.m_correct[i];
	}

	m_points = other.m_points;
}

void MultipleChoiceQuestion::del()
{
	delete[] m_text;
	delete[] m_answers;
	delete[] m_correct;
}

MultipleChoiceQuestion::MultipleChoiceQuestion(const char* _text, unsigned _points, const char* _answers, const unsigned* _correct)
{
	if (!_text)
	{
		_text = "N/A";
	}
	if (!_answers)
	{
		_answers = "N/A";
	}

	size_t len1 = strlen(_text) + 1;
	m_text = new char[len1];
	for (size_t i = 0; i < len1; i++)
	{
		m_text[i] = _text[i];
	}

	size_t len2 = strlen(_answers) + 1;
	m_answers = new char[len2];
	for (size_t i = 0; i < len2; i++)
	{
		m_answers[i] = _answers[i];
	}

	len3 = 0;

	if (!_correct)
	{
		m_correct = new unsigned[1];
		m_correct[0] = 0;
		m_given = new unsigned[1];
	}
	else
	{
		while (_correct[len3] != 0)
		{
			++len3;
		}

		m_correct = new unsigned[len3];
		m_given = new unsigned[len3 * 2]; // Maybe the user inputs more

		for (size_t i = 0; i < len3; i++)
		{
			m_correct[i] = _correct[i];
		}
	}

	m_points = _points;
}

MultipleChoiceQuestion::MultipleChoiceQuestion(const MultipleChoiceQuestion& other)
{
	copy(other);
}

MultipleChoiceQuestion& MultipleChoiceQuestion::operator=(const MultipleChoiceQuestion& other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}

	return *this;
}

MultipleChoiceQuestion::~MultipleChoiceQuestion()
{
	del();
}

void MultipleChoiceQuestion::ask()
{
	std::cout << "Question: " << m_text << "\n" << m_answers
		<< "\nYour answers (1, 2, 3, ...; 0 - ends input): ";
	givenSize = 0;
	while(true)
	{
		unsigned n = 0;
		std::cin >> n;
		if (n == 0)
		{
			break;
		}
		m_given[givenSize] = n;
		++givenSize;
	}
}
double MultipleChoiceQuestion::grade() const
{
	double temp = 0;

	if (len3 != givenSize)
	{
		if (givenSize < len3)
		{
			for (size_t i = 0; i < givenSize; i++)
			{
				if (m_correct[i] != m_given[i])
				{
					temp -= static_cast<double>(m_points / len3);
				}
				else
				{
					temp += static_cast<double>(m_points / len3);
				}
			}

			temp -= static_cast<double>(m_points / len3) * (len3 - givenSize);
		}
		else
		{
			for (size_t i = 0; i < len3; i++)
			{
				if (m_correct[i] != m_given[i])
				{
					temp -= static_cast<double>(m_points / len3);
				}
				else
				{
					temp += static_cast<double>(m_points / len3);
				}
			}

			temp -= static_cast<double>(m_points / len3) * (givenSize - len3);
		}
	}
	
	for (size_t i = 0; i < len3; i++)
	{
		if (m_correct[i] != m_given[i])
		{
			temp -= static_cast<double>(m_points / len3);
		}
		else
		{
			temp += static_cast<double>(m_points / len3);
		}
	}

	return temp;
}