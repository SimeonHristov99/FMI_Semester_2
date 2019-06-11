#include "pch.h"
#include "File.hpp"
#include <iostream>

File::File(const std::string& _name)
{
	m_name = _name;
}

File::File(const File& other)
	: m_name{ other.m_name }
{ }

std::string File::getName() const
{
	return m_name;
}

void File::setName(const std::string& _name)
{
	m_name = _name;
}