#pragma once
#include <string>

class File
{
public:
	virtual File* clone() const = 0;
	virtual size_t size() const = 0;
	virtual void print() const = 0;	

	virtual ~File() = default;
	virtual std::string getName() const;

	File(const std::string& _name = "N/A");
	File(const File&);

protected:
	void setName(const std::string&);

private:
	std::string m_name;
};