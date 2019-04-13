#pragma once
#include <iostream>

size_t getSizeStr(const char*);

class MyString
{
private:
	char* m_str;

	void copy(const char*);

	void del();
	
public:
	MyString(const char* _str = "");
	MyString(const MyString&);
	MyString& operator=(const MyString&);
	~MyString();

	bool operator==(const MyString&) const;
	bool operator<(const MyString&) const;

	friend std::ostream& operator<<(std::ostream&, const MyString&);
};