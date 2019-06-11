#include "pch.h"
#include "Catalog.hpp"
#include <iostream>

void Catalog::copy(const Catalog& other)
{
	setName(other.getName());

	for (const File* f : other.m_files)
	{
		m_files.push_back(f->clone());
	}
}

void Catalog::del()
{
	for (const File* f : m_files)
	{
		delete f;
	}
}

Catalog::Catalog(const std::string& _name) : File(_name) {}

Catalog::Catalog(const std::vector<File*> _files, const std::string& _name) : File(_name)
{
	for (const File* f: _files)
	{
		m_files.push_back(f->clone());
	}
}

Catalog::Catalog(const Catalog& other) : File(other)
{
	copy(other);
}

Catalog& Catalog::operator=(const Catalog& other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}
	return *this;
}

Catalog::~Catalog()
{
	del();
}

void Catalog::addFile(const File& addMe)
{
	m_files.push_back(addMe.clone());
}

size_t Catalog::size() const
{
	size_t sum = 0;
	for (size_t i = 0; i < m_files.size(); i++)
	{
		sum += m_files[i]->size();
	}
	return sum;
}

void Catalog::print() const
{
	std::cout << "\n";
	std::cout << "Name: " << getName() << "\nSize: " << size();
	std::cout << "\nnumber of files: " << m_files.size() << "\n";
	for (const File* f : m_files)
	{
		f->print();
	}
	std::cout << "\n";
}

std::string Catalog::getName() const
{
	return File::getName();
}
Catalog* Catalog::clone() const
{
	return new Catalog(*this);
}

bool Catalog::operator==(const Catalog& other) const // When all of their folders (if any) have the same names.
{
	for (const File* f : other.m_files)
	{
		auto cPtr = dynamic_cast<Catalog const*>(f);

		if (cPtr)
		{
			if (!(isPresent(cPtr->getName())))
			{
				return false;
			}
		}
	}
	return true;
}

bool Catalog::isPresent(const std::string& folder) const
{
	for (const File* f: m_files)
	{
		auto cPtr = dynamic_cast<Catalog const*>(f);

		if (cPtr)
		{
			if (cPtr->getName() == folder)
			{
				return true;
			}
		}
	}
	return false;
}

void Catalog::helper(std::vector<std::string>& s, size_t i, const File& source)
{
	if (i == s.size())
	{
		addFile(source);
		return;
	}

	for (File* f : m_files)
	{
		auto cPtr = dynamic_cast<Catalog*>(f);

		if (cPtr)
		{
			if (cPtr->getName() == s[i])
			{
				cPtr->helper(s, i + 1, source);
				return;
			}
		}		
	}
	std::cout << "\n\nERROR: Invalid path!\n\n";
	return;	
}