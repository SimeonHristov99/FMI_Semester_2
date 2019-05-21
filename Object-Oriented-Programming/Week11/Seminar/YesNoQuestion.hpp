#pragma once
#include "Question.hpp"

class YesNoQuestion : public Question
{
public:
	YesNoQuestion(const char* _text = nullptr, unsigned _points = 0, bool _answer = 0);
	YesNoQuestion(const YesNoQuestion&);
	YesNoQuestion& operator=(const YesNoQuestion&);
	~YesNoQuestion();

	virtual void ask();
	virtual double grade() const;

private:
	bool m_answer;
	unsigned m_points;
	char* m_text;

	void copy(const YesNoQuestion&);
	void del();
};