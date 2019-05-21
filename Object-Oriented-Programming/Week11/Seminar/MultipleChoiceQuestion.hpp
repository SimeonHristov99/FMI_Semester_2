#pragma once
#include "Question.hpp"

class MultipleChoiceQuestion : public Question
{
public:
	MultipleChoiceQuestion(const char* _text = nullptr, unsigned _points = 0, const char* _answers = nullptr, const unsigned int* _correct = nullptr);
	MultipleChoiceQuestion(const MultipleChoiceQuestion&);
	MultipleChoiceQuestion& operator=(const MultipleChoiceQuestion&);
	~MultipleChoiceQuestion();

	virtual void ask();
	virtual double grade() const;

private:
	char* m_text;
	unsigned m_points;
	char* m_answers;
	unsigned* m_correct;
	size_t len3 = 0; // not the most pleasant way of doing this ...
	unsigned* m_given;
	size_t givenSize;

	void copy(const MultipleChoiceQuestion&);
	void del();
};