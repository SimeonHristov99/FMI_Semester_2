#pragma once
#include "File.hpp"
#include <string>
#include <vector>

class Catalog: public File
{
public:
	Catalog(const std::string& _name = "N/A");
	Catalog(const std::vector<File*> _files, const std::string& _name = "N/A");
	Catalog(const Catalog&);
	Catalog& operator=(const Catalog&);
	~Catalog();

	size_t size() const override;

	void addFile(const File&);

	void print() const override;
	std::string getName() const override;
	Catalog* clone() const override;

	bool operator==(const Catalog&) const;

	bool isPresent(const std::string& folder) const;

	void helper(std::vector<std::string>& s, size_t i, const File& source);

private:
	std::vector<File*> m_files;

	void copy(const Catalog&);
	void del();
};