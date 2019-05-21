#include "pch.h"
#include "YesNoQuestion.hpp"
#include "MultipleChoiceQuestion.hpp"
#include <iostream>

template<typename T>
class Exam
{
public:
	Exam(const T* _questions = nullptr, const size_t& _size = 1)
	{
		if (!_questions)
		{
			m_questions = nullptr;
			m_size = 0;
			m_CAPACITY = 8;
		}
		else
		{
			m_size = _size;
			m_CAPACITY = m_size * 2;

			m_questions = new T[m_CAPACITY];

			for (size_t i = 0; i < m_size; i++)
			{
				m_questions[i] = _questions[i];
			}
		}
	}
	Exam(const Exam& other)
	{
		copy(other);
	}
	Exam& operator=(const Exam& other)
	{
		if (this != &other)
		{
			del();
			copy(other);
		}

		return *this;
	}
	~Exam()
	{
		del();
	}

	void add(const Question& addMe)
	{
		if (m_size == m_CAPACITY)
		{
			resize();
		}

		m_questions[m_size++] = addMe;
	}
	void answer() const
	{
		for (size_t i = 0; i < m_size; i++)
		{
			m_questions[i].ask();
		}
	}
	double grade() const
	{
		double total = 0;
		for (size_t i = 0; i < m_size; i++)
		{
			double gr = m_questions[i].grade();
			total += gr;
			std::cout << "On question " << i << " you received " << gr << " points." << std::endl;
		}
		return total;
	}

private:
	T* m_questions;

	size_t m_size;
	size_t m_CAPACITY;

	void copy(const Exam& other)
	{
		m_size = other.m_size;
		m_CAPACITY = other.m_CAPACITY;

		m_questions = new T[m_CAPACITY];
		for (size_t i = 0; i < m_size; i++)
		{
			m_questions[i] = other.m_questions[i];
		}
	}
	void resize()
	{
		m_CAPACITY *= 2;

		T* temp = new T[m_CAPACITY];
		for (size_t i = 0; i < m_size; i++)
		{
			temp[i] = m_questions[i];
		}

		delete[] m_questions;
		m_questions = temp;
	}
	void del()
	{
		delete[] m_questions;
	}
};

int main()
{
	/*
	std::cout << "Testing YesNo default contructor\n\n";

	YesNoQuestion y1;

	//y1.ask();

	std::cout << "\n\nTesting YesNo parametric contructor\n\n";

	YesNoQuestion y2("<Text here>", 1, 1);

	y2.ask();

	std::cout << "You received: " << y2.grade() << " point(s)." << std::endl;

	std::cout << "\n\nTesting YesNo operator= contructor\n\n";

	y1 = y2;

	y1.ask();

	std::cout << "You received: " << y1.grade() << " point(s)." << std::endl;
	*/

	std::cout << "Testing Multiple default contructor\n\n";

	MultipleChoiceQuestion m1;

	m1.ask();

	std::cout << "\n\nTesting Multiple parametric contructor\n\n";

	unsigned correct[2] = { 1, 3 };

	MultipleChoiceQuestion m2("<text here>", 5, "\n1. answer1.\n2. answer2.\n3. answer3", correct);

	m2.ask();

	std::cout << "You received: " << m2.grade() << " point(s)." << std::endl;

	std::cout << "\n\n";

	Exam<MultipleChoiceQuestion> e1;

	return 0;
}