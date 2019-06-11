#include "pch.h"
#include "TextFile.hpp"
#include "Catalog.hpp"
#include <iostream>

void getNames(const std::string& path, std::vector<std::string>& names)
{
	std::string name;

	for (size_t i = 0; i < path.size() + 2; i++)
	{
		if (path[i] == '\0')
		{
			names.push_back(name);
			return;
		}
		if (path[i] == '/')
		{
			names.push_back(name);
			name.clear();
		}
		else
		{
			name.push_back(path[i]);
		}
	}
}

void insert(Catalog& destination, const File& source, const std::string& path)
{
	std::vector<std::string> names; // The path but only the names.
	getNames(path, names);

	if (!(destination.isPresent(names[0])))
	{
		std::cout << "\n\nERROR: Insert() detected an invalid path!\n\n";
		return;
	}
	else
	{
		destination.helper(names, 0, source);
	}
}

int main()
{
	Catalog root("oop");
	Catalog sub("hw");
	sub.addFile(TextFile("vector", "#include <vector>"));
	sub.addFile(TextFile("filesystem", "TODO"));
	root.addFile(TextFile("test1", "web server"));
	root.addFile(TextFile("test2", "... as if"));
	root.addFile(sub);

	std::cout << sub.size() << std::endl;
	std::cout << root.size() << std::endl;

	root.print();
	
	std::cout << std::endl;

	insert(root, TextFile("New File", "Content"), "hw");
	insert(root, TextFile("New File2", "Content"), "hw/non-existant");  // Non-existant file in path
	insert(root, TextFile("New File3", "Content"), "hw/vector"); // Non-catalog in path

	std::cout << std::endl;
	
	std::cout << root.size() << std::endl;
	root.print();

	return 0;
}