#include "pch.h"
#include "Queue.hpp"
#include <iostream>

template <typename T>
void Queue<T>::copy(const Queue& other)
{
	if (!other.m_data)
	{
		std::cout << "\n\n\t\tERROR: Queue copy() detected a nullptr!\n";
		return;
	}

	m_rear = other.m_rear;
	m_CAPACITY = other.m_CAPACITY;

	m_data = new T[m_CAPACITY];

	m_front = other.m_front;
	m_rear = other.m_rear;

	for (T i = m_front; i <= m_rear; i++)
	{
		m_data[i] = other.m_data[i];
	}
}

template <typename T>
void Queue<T>::resize()
{
	m_CAPACITY *= 2;

	T* temp = new T[m_CAPACITY];

	for (T i = 0; i < m_rear; i++)
	{
		temp[i] = m_data[i];
	}

	delete[] m_data;
	m_data = temp;
}

template <typename T>
void Queue<T>::del() { delete[] m_data; }

template <typename T>
Queue<T>::Queue(const T* _data, const int& _size)
{
	if (!_data)
	{
		m_CAPACITY = 8;

		m_data = new T[m_CAPACITY];

		m_front = m_rear = -1;
	}

	else
	{
		m_rear = _size;
		m_CAPACITY = m_rear * 2;

		m_data = new T[m_CAPACITY];

		for (T i = 0; i < m_rear; i++)
		{
			m_data[i] = _data[i];
		}

		m_front = 0;
	}
}

template <typename T>
Queue<T>&  Queue<T>::operator=(const Queue& other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}

	return *this;
}

template <typename T>
Queue<T>::Queue(const  Queue& other)
{
	copy(other);
}

template <typename T>
Queue<T>::~Queue()
{
	del();
}

template <typename T>
void  Queue<T>::push_back(const T& addMe)
{
	if (isEmpty())
	{
		m_front = m_rear = 0;
	}

	else if (m_rear == m_CAPACITY)
	{
		resize();
	}

	m_data[m_rear++] = addMe;
}

template <typename T>
void  Queue<T>::pop_front()
{
	++m_front;
}

template <typename T>
T  Queue<T>::front() const
{
	return m_data[m_front];
}

template <typename T>
bool  Queue<T>::isEmpty() const
{
	return m_front == -1 && m_rear == -1 || m_front == m_rear;
}

template <typename T>
unsigned  Queue<T>::getSize() const
{
	return m_rear - m_front;
}

template <typename T>
void  Queue<T>::print()
{
	while (!isEmpty())
	{
		std::cout << front() << " ";
		pop_front();
	}

	m_front = m_rear = -1;
}