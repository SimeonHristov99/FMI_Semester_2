#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;
const int MAX_SIZE = 25;

struct Doctor
{
	char familyName[MAX_SIZE];
	char hospital[MAX_SIZE];
	bool gender;
	int experience;
	void setInput()
	{
		cout << "Last Name: ";
		cin.getline(familyName, MAX_SIZE);
		cout << "Hospital: ";
		cin.getline(hospital, MAX_SIZE);
		cout << "Gender (1 - male, 0 - female): ";
		cin >> gender;
		cout << "Experience: ";
		cin >> experience;
	}
	void print()
	{
		cout << "Last Name" << setw(MAX_SIZE) << "Hospital" << setw(MAX_SIZE) << "Gender" << setw(MAX_SIZE) << "Experience" << endl;
		cout << familyName << setw(MAX_SIZE) << hospital << setw(MAX_SIZE) << (gender == 1 ? "Male" : "Female") <<
			setw(MAX_SIZE) << experience << endl;
	}

	void myStringCopy(char* arr1, char* arr2)
	{
		int i = 0;
		do
		{
			arr1[i] = arr2[i];
			++i;
		} while (arr2[i]);

		arr1[i] = '\0';
	}

	void setFN(char newFN[])
	{
		myStringCopy(familyName, newFN);
	}
	void setHN(char newHN[])
	{
		myStringCopy(hospital, newHN);
	}
};



int main()
{
	Doctor doc;

	char x = 'x';

	doc.setInput();
	cout << endl;
	doc.print();
	cout << endl;
	cout << "\nWould you like to change the last name? (Y, N) ";
	cin >> x;
	if (x == 'Y' || x == 'y')
	{
		char newFN[MAX_SIZE] = "";
		cout << "\nNew last name";
		cin.ignore();
		cout << ":" << endl;
		cin.getline(newFN, MAX_SIZE);
		doc.setFN(newFN);
		cout << endl;
		doc.print();
	}

	cout << "\nWould you like to change the hospital name? (Y, N) ";
	cin >> x;
	if (x == 'Y' || x == 'y')
	{
		char newHN[MAX_SIZE] = "";
		cout << "\nNew name";
		cin.ignore();
		cout << ":" << endl;
		cin.getline(newHN, MAX_SIZE);
		doc.setHN(newHN);
		cout << endl;
		doc.print();
	}

	cout << endl;

	return 0;
}