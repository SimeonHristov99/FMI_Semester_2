#pragma once
#include "File.hpp"

class TextFile: public File
{
public:
	TextFile(const std::string& _name = "N/A", const std::string& _content = "N/A");

	TextFile* clone() const override;
	size_t size() const override;
	void print() const override;
	std::string getName() const override;

	void addContent(const std::string&);

private:
	std::string m_content;
};