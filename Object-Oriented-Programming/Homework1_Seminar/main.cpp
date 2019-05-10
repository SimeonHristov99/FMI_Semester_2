/* --------------------------------------------------------------------------------------------------------------------------------------
 * Created by: Simeon Hristov
 *
 * Group: III
 *
 * Faculty Number: 71845
 * --------------------------------------------------------------------------------------------------------------------------------------
 */

#include "pch.h"
#include <iostream>
#include <initializer_list>

template <typename T>
class Vector
{
public:

	class Iterator
	{
	public:

		explicit Iterator(T* _ptr = nullptr) : m_ptr{ _ptr } {}

		Iterator& operator++()
		{
			if (!m_ptr)
			{
				std::cout << "\n\n\tERROR: Iterator operator++ detected a nullptr!\n";
			}

			m_ptr = m_ptr + 1;
			return *this;
		}

		Iterator operator++(int)
		{
			Iterator temp = *this;
			++(*this);
			return temp;
		}

		Iterator& operator--()
		{
			if (!m_ptr)
			{
				std::cout << "\n\n\tERROR: Iterator operator++ detected a nullptr!\n";
			}

			--m_ptr;
			return *this;
		}

		Iterator operator--(int)
		{
			Iterator temp = *this;
			--m_ptr;
			return temp;
		}

		T& operator*()
		{
			if (!m_ptr)
			{
				std::cout << "\n\n\tERROR: Iterator operator* detected a nullptr!\n";
			}

			return *m_ptr;
		}

		const T& operator*() const
		{
			return *m_ptr;
		}

		T* operator->()
		{
			return m_ptr;
		}

		const T* operator->() const
		{
			return m_ptr;
		}

		bool operator==(const Iterator& other) const
		{
			return (other.m_ptr == m_ptr);
		}

		bool operator!=(const Iterator& other) const
		{
			return !(*this == other);
		}

		bool operator<(const Iterator& other) const
		{
			return (m_ptr < other.m_ptr);
		}

		bool operator<=(const Iterator& other) const
		{
			return (*this < other || *this == other);
		}

		bool operator>(const Iterator& other) const
		{
			return !(*this <= other);
		}

		bool operator>=(const Iterator& other) const
		{
			return (*this == other || *this > other);
		}

		Iterator operator+(const unsigned& moveWith) const
		{
			Iterator temp = *this;
			temp.m_ptr += moveWith;
			return temp;
		}

		friend Iterator operator+(const unsigned& moveWith, const Iterator& moveMe)
		{
			return moveMe + moveWith;
		}

		Iterator operator-(const unsigned& moveWith)
		{
			Iterator temp = *this;
			temp.m_ptr -= moveWith;
			return temp;
		}

		Iterator& operator-=(const unsigned& moveWith)
		{
			return *this - moveWith;
		}

		unsigned operator-(const Iterator& other)
		{
			return (m_ptr > other.m_ptr ? m_ptr - other.m_ptr : other.m_ptr - m_ptr);
		}

		Iterator& operator+=(const unsigned& moveWith)
		{
			return *this = *this + moveWith;
		}

		unsigned operator-=(const Iterator& other)
		{
			return *this = *this - other;
		}

	private:
		T* m_ptr;
	};

	Vector(const T* _data = nullptr, const size_t& _size = 1)
	{
		if (!_data)
		{
			m_CAPACITY = 8;
			m_size = 0;

			m_data = new T[m_CAPACITY];
		}

		else
		{
			m_size = _size;
			m_CAPACITY = m_size * 2;

			m_data = new T[m_CAPACITY];

			for (size_t i = 0; i < m_size; i++)
			{
				m_data[i] = _data[i];
			}
		}
	}

	Vector(const Vector& other)
	{
		copy(other);
	}

	Vector& operator=(const Vector& other)
	{
		if (this != &other)
		{
			del();
			copy(other);
		}

		return *this;
	}

	~Vector() { del(); }

	Vector(const std::initializer_list<T>& _data)
	{
		m_size = 0;
		m_CAPACITY = 8;

		m_data = new T[m_CAPACITY];

		for(auto it = _data.begin(); it != _data.end(); ++it)
		{
			push_back(*it);
		}
	}

	Vector(const unsigned& _CAPACITY)
	{
		m_size = 0;
		m_CAPACITY = _CAPACITY;

		m_data = new T[m_CAPACITY];
	}

	Vector(const unsigned& _size, const T& _element)
	{
		m_size = _size;
		m_CAPACITY = m_size * 2;

		m_data = new T[m_CAPACITY];

		for (size_t i = 0; i < m_size; i++)
		{
			m_data[i] = _element;
		}
	}

	T& operator[](const unsigned& index) const
	{
		return m_data[index];
	}

	T& at(const unsigned& index) const
	{
		if (index < 0 || index >= m_size)
		{
			std::cout << "\n\n\tERROR: Vector at() detected an invalid index!\n\n";
		}

		return m_data[index];
	}

	T& front() const
	{
		return m_data[0];
	}

	T& back() const
	{
		return m_data[m_size - 1];
	}

	Iterator begin() const
	{
		Iterator i(m_data);
		return i;
	}

	Iterator end() const
	{
		Iterator i(m_data + m_size);
		return i;
	}

	bool empty() const
	{
		return m_size == 0;
	}

	unsigned size() const
	{
		return m_size;
	}

	unsigned capacity() const
	{
		return m_CAPACITY;
	}

	void reserve(const unsigned& _CAPACITY)
	{
		if (_CAPACITY > m_CAPACITY)
		{
			m_CAPACITY = _CAPACITY;

			resizeHelper();
		}
	}

	void shrink_to_fit()
	{
		if (m_size == 0) 
		{
			m_CAPACITY = 1;
		}

		else
		{
			m_CAPACITY = m_size;
		}

		resizeHelper();
	}

	Iterator insert(const Iterator& next, const T& element)
	{
		for (size_t i = 0; i <= m_size; i++)
		{
			Iterator i1(&m_data[i]);

			if (next == i1)
			{
				if (m_size + 1 == m_CAPACITY)
				{
					resize();
				}

				for (size_t j = m_size; j > i; --j)
				{
					m_data[j] = m_data[j - 1];
				}

				++m_size;

				m_data[i] = element;

				*i1 = m_data[i];
				
				return i1;
			}
		}

		return next;
	}

	Iterator erase(const Iterator& removeMe)
	{
		for (Iterator i1 = begin(); i1 != end(); i1++)
		{
			if (i1 == removeMe)
			{
				for (Iterator i2 = i1; i2 != end(); i2++)
				{
					*i2 = *(1 + i2);
				}

				--m_size;

				return ++i1;
			}
		}

		return removeMe;
	}

	void push_back(const T& element)
	{
		if (m_size == m_CAPACITY)
		{
			resize();
		}

		m_data[m_size] = element;

		++m_size;
	}

	void pop_back()
	{
		--m_size;
	}

	void swap(Vector& other)
	{
		Vector temp = *this;
		*this = other;
		other = temp;
	}

	bool operator==(const Vector& other) const // true if the contents of the containers are equal, false otherwise
	{
		if (m_size != other.m_size)
		{
			return false;
		}

		for (size_t i = 0; i < m_size; i++)
		{
			if (m_data[i] != other.m_data[i])
			{
				return false;
			}
		}

		return true;
	}

	bool operator!=(const Vector& other) const // true if the contents of the containers are not equal, false otherwise
	{
		return !(*this == other);
	}

	bool operator<(const Vector& other) const // true if the contents of the lhs are lexicographically less than the contents of rhs, false otherwise
	{
		for (size_t i = 0; i < m_size; i++)
		{
			if (m_data[i] >= other.m_data[i])
			{
				return false;
			}
		}

		return true;
	}

	bool operator<=(const Vector& other) const // true if the contents of the lhs are lexicographically less than or equal the contents of rhs, false otherwise
	{
		return *this < other || *this == other;
	}

	bool operator>(const Vector& other) const // true if the contents of the lhs are lexicographically greater than the contents of rhs, false otherwise
	{
		return !(*this <= other);
	}

	bool operator>=(const Vector& other) const // true if the contents of the lhs are lexicographically greater than or equal the contents of rhs, false otherwise
	{
		return !(*this < other);
	}
	
	void erase(T& removeAllMe)
	{
		Vector temp;

		for (size_t i = 0; i < m_size; i++)
		{
			if (m_data[i] != removeAllMe)
			{
				temp.push_back(m_data[i]);
			}
		}

		copy(temp);
	}

	void erase_if(bool(*predicate)(const T&)) // takes in a lambda. Ex.: [](const int& value) {return value % 2 == 0; }
	{
		for (size_t i = 0; i < m_size; i++)
		{
			if (predicate(m_data[i]))
			{
				erase(begin() + i);
			}
		}
	}
	

private:
	T* m_data;

	size_t m_size;
	size_t m_CAPACITY;

	void copy(const Vector& other)
	{
		if (!other.m_data)
		{
			std::cout << "\n\n\tERROR: Vector copy() detected a source with a nullptr!\n";
			return;
		}

		m_CAPACITY = other.capacity();
		m_size = other.size();

		m_data = new T[m_CAPACITY];

		for (size_t i = 0; i < other.size(); i++)
		{
			m_data[i] = other.m_data[i];
		}
	}

	void resizeHelper()
	{
		T* _data = new T[m_CAPACITY];

		for (size_t i = 0; i < m_size; i++)
		{
			_data[i] = m_data[i];
		}

		delete[] m_data;
		m_data = _data;
	}

	void resize()
	{
		m_CAPACITY *= 2;

		resizeHelper();
	}

	void del()
	{
		delete[] m_data;
	}
};

int main()
{
	std::cout << "------------------------------------------------------------Testing default constructor\n";

	Vector<char> v0;

	for (size_t i = 0; i < v0.size(); i++)
	{
		std::cout << v0[i] << "WhiteSpace1";
	}

	std::cout << "whitespace";

	std::cout << "\n\nPush 'S' & 'P'\n";

	v0.push_back('S');
	v0.push_back('P');

	for (size_t i = 0; i < v0.size(); i++)
	{
		std::cout << v0[i];
	}

	std::cout << "\n\nPop 'P'\n";

	v0.pop_back();

	for (size_t i = 0; i < v0.size(); i++)
	{
		std::cout << v0[i] << " ";
	}

	std::cout << "\n\n------------------------------------------------------------Testing initializer list of ints\n";

	Vector<int> v1 = { 1, 2, 3, 4, 5 };

	for (size_t i = 0; i < 5; i++)
	{
		std::cout << v1[i] << " ";
	}

	std::cout << "\n\n------------------------------------------------------------Testing initializer list of char\n";

	Vector<char> v2 = { 'T', 'h', 'i', 's', ' ', 'i', 's' };

	for (size_t i = 0; i < 7; i++)
	{
		std::cout << v2[i];
	}

	std::cout << "\n\n------------------------------------------------------------Testing erase on 1 element\n";

	v1.erase(v1.begin() + 1);
	
	for (size_t i = 0; i < v1.size(); i++)
	{
		std::cout << v1[i] << " ";
	}

	std::cout << "\n\n------------------------------------------------------------Testing erase on Vector<char>\n";

	Vector<char> v3 = { 'S', 'a', 'm', 'o', 'L', 'e', 'v', 's', 'k', 'i' };

	v3.erase(v3[2]);

	for (size_t i = 0; i < v3.size(); i++)
	{
		std::cout << v3[i];
	}

	std::cout << "\n\n------------------------------------------------------------Testing erase on Vector<int>\n";

	Vector<int> v4 = { 2, 2, 2, 2, 77, 2, 2, 2, 2, 2, 2, 2, 2 };

	v4.erase(v4[1]);

	for (size_t i = 0; i < v4.size(); i++)
	{
		std::cout << v4[i] << " ";
	}

	std::cout << "\n\n------------------------------------------------------------Testing repeating number constructor\n";

	Vector<char> v5(50, 'L');

	for (size_t i = 0; i < v5.size(); i++)
	{
		std::cout << v5[i] << " ";
	}

	std::cout << "\n\n------------------------------------------------------------Testing constructor which takes capacity(73)\n";

	Vector<int> v6(73);

	std::cout << "v6 capacity: " << v6.capacity();

	/*
	for (size_t i = 0; i < 73; i++)
	{
		v6.push_back(77);
	}

	std::cout << "\tPrinting\n\n";

	for (size_t i = 0; i < 73; i++)
	{
		std::cout << v6[i] << " ";
	}

	v6.push_back(77);
	std::cout << "\n\tPrinting2\n\n";

	for (size_t i = 0; i < 74; i++)
	{
		std::cout << v6[i] << " ";
	}
	*/

	std::cout << "\n\n------------------------------------------------------------Testing at[]\n";

	std::cout << "Should be L: " << v5.at(5) << std::endl;
	std::cout << "Should be 77: " << v4.at(0) << std::endl;
	std::cout << "Expected an error above: " << v4.at(1) << std::endl;
	std::cout << "Expected an error above: " << v4.at(-1) << std::endl;
	std::cout << "Should be o: " << v3.at(2) << std::endl;
	std::cout << "Should be h: " << v2.at(1) << std::endl;

	std::cout << "\n\n------------------------------------------------------------Testing front()\n";

	std::cout << "Should be L: " << v5.front() << std::endl;
	std::cout << "Should be 77: " << v4.front() << std::endl;
	std::cout << "Should be S: " << v3.front() << std::endl;
	std::cout << "Should be T: " << v2.front() << std::endl;
	std::cout << "Should be 1: " << v1.front() << std::endl;
	v0.pop_back();
	v0.push_back('F');
	std::cout << "Should be F: " << v0.front() << std::endl;

	std::cout << "\n\n------------------------------------------------------------Testing back()\n";

	std::cout << "Should be L: " << v5.back() << std::endl;
	std::cout << "Should be 77: " << v4.back() << std::endl;
	std::cout << "Should be i: " << v3.back() << std::endl;
	std::cout << "Should be s: " << v2.back() << std::endl;
	std::cout << "Should be 5: " << v1.back() << std::endl;
	v0.pop_back();
	v0.push_back('F');
	std::cout << "Should be F: " << v0.back() << std::endl;
	
	std::cout << "\n\n------------------------------------------------------------Testing end() and insert()\n";

	std::cout << "\nInserting in the beginning:\n";

	v2.insert(v2.begin(), 'B');

	for (size_t i = 0; i < v2.size(); i++)
	{
		std::cout << v2[i];
	}

	std::cout << "\nInserting some where else :D:\n";

	v2.insert(--v2.end(), 'T');

	for (size_t i = 0; i < v2.size(); i++)
	{
		std::cout << v2[i];
	}

	std::cout << "\nInserting some where else v2:\n";

	v2.insert(v2.end() - 4, 'T');

	for (size_t i = 0; i < v2.size(); i++)
	{
		std::cout << v2[i];
	}

	std::cout << "\nInserting in the end:\n";

	std::cout << "Pointer points to(E): " << *(v2.insert(v2.end(), 'E')) << std::endl;

	for (size_t i = 0; i < v2.size(); i++)
	{
		std::cout << v2[i];
	}

	std::cout << "\n\n------------------------------------------------------------Testing shrink_to_fit() and capacity()\n";

	std::cout << "\nv2 Capacity and size before: " << v2.size() << " " << v2.capacity() << std::endl;
	v2.shrink_to_fit();
	std::cout << "\nv2 Capacity and size after: " << v2.size() << " " << v2.capacity() << std::endl;

	std::cout << "\nv1 Capacity and size before: " << v1.size() << " " << v1.capacity() << std::endl;
	v1.shrink_to_fit();
	std::cout << "\nv1 Capacity and size after: " << v1.size() << " " << v1.capacity() << std::endl;

	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();

	std::cout << "\nv1 Capacity and size after removing all elements: " << v1.size() << " " << v1.capacity() << "\n\n------------------------------------------------------------Testing empty() on v1\n" << std::boolalpha << v1.empty() << std::endl;
	v1.shrink_to_fit();

	std::cout << "\nv1 Capacity and size after freeing memory: " << v1.size() << " " << v1.capacity() << std::endl;

	v1.push_back(8);
	v1.push_back(7);
	v1.push_back(6);
	v1.push_back(5);
	v1.push_back(4);

	std::cout << "\nv1 Capacity and size of v1 after pushing 5 elements: " << v1.size() << " " << v1.capacity() << std::endl;

	std::cout << "\n\n------------------------------------------------------------Testing reserve()\n";

	v1.reserve(16);

	std::cout << "\nv1 Capacity and size after reserving 16: " << v1.size() << " " << v1.capacity() << std::endl;
	v1.reserve(16);
	std::cout << "\nv1 Capacity and size after reserving 16 again (should stay 16): " << v1.size() << " " << v1.capacity() << std::endl;
	v1.reserve(15);
	std::cout << "\nv1 Capacity and size after reserving 15 (should stay 16): " << v1.size() << " " << v1.capacity() << std::endl;
	v1.reserve(32);
	std::cout << "\nv1 Capacity and size after reserving 32 (expected 32): " << v1.size() << " " << v1.capacity() << std::endl;

	std::cout << "\n\n------------------------------------------------------------Testing swap()\n";

	std::cout << "\tBefore:\n";
	std::cout << "v1: ";
	for (size_t i = 0; i < v1.size(); i++)
	{
		std::cout << v1[i] << " ";
	}
	std::cout << "\nv4: ";
	for (size_t i = 0; i < v4.size(); i++)
	{
		std::cout << v4[i] << " ";
	}

	v4.swap(v1);
	
	std::cout << "\nv1: ";
	for (size_t i = 0; i < v1.size(); i++)
	{
		std::cout << v1[i] << " ";
	}
	std::cout << "\nv4: ";
	for (size_t i = 0; i < v4.size(); i++)
	{
		std::cout << v4[i] << " ";
	}

	std::cout << "\n\n------------------------------------------------------------Testing comparisons\n";

	std::cout << std::boolalpha << (v1 == v4) << std::endl;
	std::cout << std::boolalpha << (v1 != v4) << std::endl;
	std::cout << std::boolalpha << (v1 < v4) << std::endl;
	std::cout << std::boolalpha << (v1 <= v4) << std::endl;
	std::cout << std::boolalpha << (v1 > v4) << std::endl;
	std::cout << std::boolalpha << (v1 >= v4) << std::endl;

	std::cout << "\n------------------------------------------------------------Testing erase_if\n";

	v4.erase_if([](const int& value) {return value % 2 == 0; });

	std::cout << "\nv4 after removing the even numbers: ";

	for (size_t i = 0; i < v4.size(); i++)
	{
		std::cout << v4[i] << " ";
	}

	std::cout << "\n\n";

	return 0;
}