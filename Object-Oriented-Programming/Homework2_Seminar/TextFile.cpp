#include "pch.h"
#include "TextFile.hpp"
#include <iostream>

TextFile::TextFile(const std::string& _name, const std::string& _content) : File(_name)
{
	m_content = _content;
}

TextFile* TextFile::clone() const
{
	return new TextFile(*this);
}

size_t TextFile::size() const
{
	return m_content.length();
}

void TextFile::print() const
{
	std::cout << "\n";
	std::cout << "Content: " << m_content;
	std::cout << "\nName: " << getName() << "\nSize: " << size();
	std::cout << "\n";
}

std::string TextFile::getName() const
{
	return File::getName();
}

void TextFile::addContent(const std::string& replaceWithMe)
{
	m_content = replaceWithMe;
}