#pragma once
#include <iostream>

template <typename T>
class Queue
{
public:
	Queue(const T* _data = nullptr, const int& _size = 1);
	Queue(const Queue&);
	Queue& operator=(const Queue&);
	~Queue();

	void push_back(const T&);
	void pop_front();

	T front() const;
	bool isEmpty() const;
	unsigned getSize() const;

	void print();

private:
	T* m_data;

	T m_front;
	T m_rear;

	size_t m_CAPACITY;

	void copy(const Queue&);
	void resize();
	void del();
};