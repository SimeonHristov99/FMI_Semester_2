#include "pch.h"
#include <iostream>
const size_t MAX_SIZE_NAME = 51;
const size_t MAX_PATIENTS = 100;
const size_t MAX_NURSES = 100;

class Nurse
{
private:
	size_t patients = 0;
	char name[MAX_SIZE_NAME];

public:
	/*
	void setPatients()
	{
		std::cin >> patients;
	}*/

	const size_t getPatients() const
	{
		return this->patients;
	}

	void setNameN()
	{
		std::cin.getline(this->name, MAX_SIZE_NAME);
	}

	const char* getName() const
	{
		return this->name;
	}

	void print() const
	{
		std::cout << "Name: " << name << std::endl
			<< "Number of patients: " << patients << std::endl;
	}
};

class Patient
{
private:
	size_t room;
	char name[MAX_SIZE_NAME];
	Nurse* nurse;

public:
	void setRoom()
	{
		do
		{
			std::cout << "Assing a room number between 100 and 999: ";
			std::cin >> room;
		} while (!(room >= 100 && room <= 999));
	}

	const int getRoom() const
	{
		return this->room;
	}

	void setNameP()
	{
		std::cin.getline(this->name, MAX_SIZE_NAME);
	}

	const char* getName() const
	{
		return this->name;
	}

	void assignNurse(const Nurse* assignedNurse)
	{
		*nurse = *assignedNurse;
	}

	void print() const
	{
		std::cout << this->getName() << "        " << this->getRoom();

		if (this->nurse != nullptr)
		{
			std::cout << "\n    Nurse: " << this->nurse->getName() << std::endl;
			std::cout << "\n    Number of patients she has: " << this->nurse->getPatients() << std::endl;
		}
	}
};

class Hospital
{
private:
	Patient patientsArr[MAX_PATIENTS];
	Nurse nurseArr[MAX_NURSES];

	const Nurse* findNurse(const size_t& size) const
	{
		for (size_t i = 0; i < size; i++)
		{
			if (nurseArr[i].getPatients() < 2)
			{
				return &nurseArr[i];
			}
		}

		return NULL;
	}

	bool equalNames(char name[], Patient& p) const
	{
		for (size_t i = 0; name[i]; ++i)
		{
			if (name[i] != p.getName()[i])
			{
				return false;
			}
		}

		return true;
	}

public:
	void addNurse(size_t& size)
	{
		std::cout << "\nNurse " << size + 1 << ":\n";
		std::cout << "    Enter nurse name: ";
		nurseArr[size].setNameN();
	

		++size;
	}

	void addPatient(size_t& size)
	{
		std::cout << "\nPatient " << size + 1 << ":\n";
		std::cout << "    Enter patient name: ";
		patientsArr[size].setNameP();

		std::cout << "    Enter patient room: ";
		patientsArr[size].setRoom();

		patientsArr[size].assignNurse(findNurse(size));	
	}

	void removePatient(size_t& size, char* name)
	{
		for (size_t i = 0; i < size; i++)
		{
			if (equalNames(name, patientsArr[i]))
			{
				Patient temp = patientsArr[i];
				patientsArr[i] = patientsArr[size - 1];
				patientsArr[size - 1] = temp;

				--size;
				break;
			}
		}
	}

	void print(const size_t& size) const
	{
		for (size_t i = 0; i < size; i++)
		{
			std::cout << "\n\n        Table of patients\n\n";
			patientsArr[i].print();
		}
	}
};

int main()
{
	Hospital hospital;
	size_t sizeNurses = 0;
	size_t sizePatients = 0;
	char proceed = 'x';

	std::cout << "                        This is your hospital!\n\n";
	std::cout << "            What would you like to do? Choose an option 1 or 2 from the menu.\n\n";

	std::cout << "        MENU\n\n";
	std::cout << "1. Add a nurse.\n";
	std::cout << "2. Add a patient.\n";
	std::cout << "3. Remove a patient.\n";
	std::cout << "  Your choice: ";

	std::cin >> proceed;

	switch (proceed)
	{
	case '1':
	{
		do
		{
			std::cin.ignore(80, '\n');
			hospital.addNurse(sizeNurses);

			std::cout << "Add new nurse? (Y/N) ";
			std::cin >> proceed;
			
		} while (proceed == 'Y' || proceed == 'y');

		break;
	}
	case '2':
	{
		do
		{
			hospital.addPatient(sizePatients);

			std::cout << "Add new patient? (Y/N) ";
			std::cin >> proceed;
			std::cin.ignore(80, '\n');
		} while (proceed == 'Y' || proceed == 'y');

		break;
	}
	case '3':
	{
		char remove[MAX_SIZE_NAME];
		std::cout << "Enter name of patient to be removed: ";
		std::cin.getline(remove, MAX_SIZE_NAME);

		hospital.removePatient(sizePatients, remove);

		break;
	}
	default:
	{
		std::cout << "\n\nERROR: No suitable option found!\n\n";
	}
	}

	return 0;
}