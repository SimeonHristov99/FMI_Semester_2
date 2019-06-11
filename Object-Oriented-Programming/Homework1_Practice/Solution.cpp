#include "pch.h"
#include <iostream>

size_t getSizeStr(const char str[]) // modified to count the '\0' as well
{
	if (str[0] == '\0')
		return 1;

	return 1 + getSizeStr(str + 1);
}

void copyStr(char to[], const char from[])
{
	if (from[0] == '\0')
	{
		to[0] = '\0';
		return;
	}

	to[0] = from[0];

	return copyStr(to + 1, from + 1);
}

bool eqStr(const char str0[], const char str1[])
{
	if (str0[0] == '\0' && str1[0] == '\0')
		return true;

	if (str0[0] != str1[0])
		return false;

	return eqStr(str0 + 1, str1 + 1);
}

class Employee
{
private:
	bool owner;
	char* firstname;
	char* lastname;
	char* SSN;
	unsigned short int experience;
	unsigned short int numberofSoldCars;

	void copy(const char _name[], const char _lastname[], const char _SSN[])
	{
		if (_name == nullptr || _name[0] == '\0' || _lastname == nullptr || _lastname[0] == '\0' || _SSN == nullptr || _SSN[0] == '\0')
		{
			std::cout << "\n\nERROR: Copying employee didn't work!\n"; exit(1);
		}

		firstname = new char[getSizeStr(_name)];
		copyStr(firstname, _name);

		lastname = new char[getSizeStr(_lastname)];
		copyStr(lastname, _lastname);

		SSN = new char[getSizeStr(_SSN)];
		copyStr(SSN, _SSN);
	}

	void del()
	{
		delete[] firstname; firstname = nullptr;
		delete[] lastname; lastname = nullptr;
		delete[] SSN; SSN = nullptr;
	}

public:
	Employee() : firstname(nullptr), lastname(nullptr), owner(false), SSN(nullptr), experience(0), numberofSoldCars(0) {}
	
	Employee(char _name[], char _lastname[], char _SSN[], unsigned short int _experience, unsigned short int _numberofSoldCars, bool _owner = false)
	{
		copy(_name, _lastname, _SSN);
		experience = _experience;
		numberofSoldCars = _numberofSoldCars;
		owner = _owner;
	}
	
	Employee(const Employee& other) : experience(other.experience), numberofSoldCars(other.numberofSoldCars)
	{
		copyStr(firstname, other.firstname);
		copyStr(lastname , other.lastname);
		copyStr(SSN, other.SSN);

		if (other.owner == true)
		{
			std::cout << "\n\nERROR: Trying to copy owner!\n\n"; exit(1);
		}

		owner = false;
	}
	
	Employee& operator=(const Employee& other)
	{
		if (this != &other)
		{
			del();
			copy(other.firstname, other.lastname, other.SSN);
			this->experience = other.experience;
			this->numberofSoldCars = other.numberofSoldCars;
		}

		return *this;
	}
	
	~Employee() { del(); }

	void increaseNumberofSoldCars()
	{
		++numberofSoldCars;
	}

	void print() const
	{
		std::cout << firstname << " " << lastname << " with " << experience << " years of experience and " << numberofSoldCars << " sales." << std::endl;
	}

	void setup()
	{
		char buffer1[1000], buffer2[1000], buffer3[1000];

		std::cout << "\nBe careful - any mistake here will restart the information input process!\n";

		do
		{
			std::cout << "    First name: "; std::cin >> buffer1;
			std::cout << "    Family name: "; std::cin >> buffer2;
			std::cout << "    SSN (10-digits): "; std::cin >> buffer3;
			std::cout << "    Experience (in years): "; std::cin >> experience;
			std::cout << "    Number of sold cars: "; std::cin >> numberofSoldCars;
		} while (buffer1 == nullptr || buffer1[0] == '\0' || buffer2 == nullptr || buffer2[0] == '\0' || buffer3 == nullptr || buffer3[0] == '\0' || getSizeStr(buffer3) != 11 || experience < 0 || experience > 80 || numberofSoldCars < 0);

		owner = false;

		copy(buffer1, buffer2, buffer3);
	}

	void makeBoss(bool changed = false)
	{
		char buffer1[1000], buffer2[1000], buffer3[1000];

		if (changed)
			del();

		experience = 0;
		numberofSoldCars = 0;
		owner = true;

		std::cout << "\nBe careful - any mistake here will restart the information input process!\n";

		do
		{	std::cout << "    First name: "; std::cin >> buffer1;
			std::cout << "    Family name: "; std::cin >> buffer2;
			std::cout << "    SSN (10-digits): "; std::cin >> buffer3;
		} while (buffer1 == nullptr || buffer1[0] == '\0' || buffer2 == nullptr || buffer2[0] == '\0' || buffer3 == nullptr || buffer3[0] == '\0' || getSizeStr(buffer3) != 11);

		copy(buffer1, buffer2, buffer3);
	}

	const char* getFName() const
	{
		return firstname;
	}

	const char* getLName() const
	{
		return lastname;
	}

	const char* getSSN() const
	{
		return SSN;
	}

	unsigned short int getExperience() const
	{
		return experience;
	}

	unsigned short int getNumberofSoldCars() const
	{
		return numberofSoldCars;
	}
};

class Car
{
private:
	char* brand;
	char* model;
	unsigned short int yearMade;
	double price;
	double mileage;

	void copy(const char _brand[], const char _model[])
	{
		if (_brand == nullptr || _brand[0] == '\0' || _model == nullptr || _model[0] == '\0')
			exit(1);

		brand = new char[getSizeStr(_brand)];
		copyStr(brand, _brand);

		model = new char[getSizeStr(_model)];
		copyStr(model, _model);
	}

	void del()
	{
		delete[] brand; brand = nullptr;
		delete[] model; model = nullptr;
	}

public:
	Car() : brand(nullptr), model(nullptr), yearMade(1900), price(250), mileage(0) {}
	
	Car(char _brand[], char _model[], unsigned short int _yearMade, double _price, double _mileage) : yearMade(_yearMade), price(_price), mileage(_mileage)
	{
		copy(_brand, _model);
	}

	Car(const Car& other) : yearMade(other.yearMade), price(other.price), mileage(other.mileage)
	{
		copyStr(brand, other.brand);
		copyStr(model, other.model);
	}

	Car& operator=(const Car& other)
	{
		if (this != &other)
		{
			del();
			copy(other.brand, other.model);
			this->mileage = other.mileage;
			this->price = other.price;
			this->yearMade = other.yearMade;
		}

		return *this;
	}

	~Car() { del(); }

	void print() const	
	{	
		std::cout << brand << " " << model << " made in " << yearMade << " with mileage " << mileage << "km." << std::endl;
	}

	void setup()
	{
		char buffer1[1000], buffer2[1000];

		std::cout << "\nBe careful - any mistake here will restart the information input process!\n";

		do
		{	std::cout << "    Brand: "; std::cin >> buffer1;
			std::cout << "    Model: "; std::cin >> buffer2;
			std::cout << "    Year of production [1900 - 2019]: "; std::cin >> yearMade;
			std::cout << "    Price (must but greater than or equal to 250): "; std::cin >> price;
			std::cout << "    Mileage: "; std::cin >> mileage;
		} while (buffer1 == nullptr || buffer1[0] == '\0' || buffer2 == nullptr || buffer2[0] == '\0' || yearMade < 1900 || yearMade > 2019 || price < 250.0 || mileage < 0.0);

		copy(buffer1, buffer2);
	}

	const char* getBrand() const
	{
		return brand;
	}

	const char* getModel() const
	{
		return model;
	}

	unsigned short int getYearMade() const
	{
		return yearMade;
	}

	double getPrice() const
	{
		return price;
	}

	double getMileage() const
	{
		return mileage;
	}
};

class Dealership
{
private:
	Employee CEO;
	Employee* staff;
	Car* cars;
	size_t staffCapacity;
	size_t carsCapacity;

	void resizeStaff()
	{
		Employee* temp = new Employee[staffCapacity * 2];

		for (size_t i = 0; i < staffCapacity; ++i)
			temp[i] = staff[i];

		delete[] staff; staff = temp; staffCapacity *= 2;
	}

	void resizeCars()
	{
		Car* temp = new Car[carsCapacity * 2];

		for (size_t i = 0; i < carsCapacity; ++i)
			temp[i] = cars[i];

		delete[] cars; cars = temp; carsCapacity *= 2;
	}

	void sellCarMain(char _brand[], char _model[], double _price, char _firstname[], char _lastname[], size_t& limit, size_t& limitStaff)
	{
		if (_brand == nullptr || _brand[0] == '\0' || _model == nullptr || _model[0] == '\0' || _price < 250.0 || _firstname == nullptr || _firstname == '\0' || _lastname == nullptr || _lastname == '\0')
			exit(1);

		bool flag = true, person = false;

		Car* temp = new Car[carsCapacity];

		for (size_t i = 0; i < limit; ++i)
		{
			if (eqStr(cars[i].getBrand(), _brand) && eqStr(cars[i].getModel(), _model) && cars[i].getPrice() == _price)
			{
				flag = false;

				std::cout << "\n\nNew sale: ";
				cars[i].print();
			}
			else
			{
				if (i < 1 && !flag)
				{
					std::cout << "\n\nERROR: Dealership must have at least one employee!\n";
					exit(1);
				}
				!flag ? temp[i - 1] = cars[i] : temp[i] = cars[i];
			}
		}

		delete[] cars; cars = temp;
				
		if (flag)
		{
			std::cout << "\n\nERROR: No such car!\n";
			exit(1);
		}

		size_t j = 0;
		for (; j < limitStaff && !person; ++j)
			if (eqStr(staff[j].getFName(), _firstname) && eqStr(staff[j].getLName(), _lastname))
				person = true;

		if (person == false)
		{
			std::cout << "\n\nERROR: No such employee!\n";
			exit(1);
		}

		std::cout << "Sold by " << _firstname << " " << _lastname << std::endl;

		staff[j - 1].increaseNumberofSoldCars();
	}

public:
	Dealership() : staffCapacity(2), carsCapacity(2)
	{
		staff = new Employee[staffCapacity];
		cars = new Car[carsCapacity];
	}

	void addEmployee(const unsigned int& i)
	{
		if (i >= staffCapacity)
			resizeStaff();

		staff[i].setup();

		if (i > 0)
		{
			for (size_t j = 0; j < i; ++j)
				if (eqStr(staff[j].getSSN(), staff[i].getSSN()) || eqStr(CEO.getSSN(), staff[i].getSSN()))
				{
					std::cout << "\n\nERROR: Social security number must be unique!\n";
					exit(1);
				}
		}
		else
		{
			if (eqStr(CEO.getSSN(), staff[i].getSSN()))
			{
				std::cout << "\n\nERROR: Social security number must be unique!\n";
				exit(1);
			}
		}

		std::cout << "\n\nNew employee: ";
		staff[i].print();
	}

	void addCar(const unsigned int& i)
	{
		if (i >= carsCapacity)
			resizeCars();

		cars[i].setup();

		std::cout << "\n\nNew car: ";
		cars[i].print();
	}

	void setupCEO(size_t& stafflimit, bool changed = 0)
	{
		CEO.makeBoss(changed);

		if (changed)
			for (size_t i = 0; i <= stafflimit; i++)
				if (eqStr(CEO.getSSN(), staff[i].getSSN()))
				{
					std::cout << "\n\nERROR: Social security number must be unique!\n";
					exit(1);
				}

		std::cout << "\n\nNew CEO: " << CEO.getFName() << " " << CEO.getLName() << " SSN(" << CEO.getSSN() << ")\n";
	}

	void sortEmployee(bool option, size_t& limit)
	{
		Employee** sorted = new Employee*[limit];

		for (size_t i = 0; i < limit; ++i)
			sorted[i] = &staff[i];

		for (size_t i = 0; i < limit - 1; ++i)
		{
			size_t minIndex = i;

			for (size_t j = i + 1; j < limit; ++j)
			{
				if (option == 0)
				{
					if (sorted[j]->getExperience() < sorted[minIndex]->getExperience())
						minIndex = j;
				}
				else
				{
					if (sorted[j]->getNumberofSoldCars() < sorted[minIndex]->getNumberofSoldCars())
						minIndex = j;
				}
			}
			Employee* temp = sorted[i];
			sorted[i] = sorted[minIndex];
			sorted[minIndex] = temp;
		}

		std::cout << (option == 0 ? "\nEmployees by experience:\n" : "\nEmployees by number of sales:\n");

		for (size_t k = 0; k < limit; ++k)
			sorted[k]->print();

		delete[] sorted; sorted = nullptr;

	}

	void sortCars(bool option, size_t limit)
	{

			Car** sorted = new Car*[limit];

			for (size_t i = 0; i < limit; ++i)
				sorted[i] = &cars[i];

			for (size_t i = 0; i < limit - 1; ++i)
			{
				size_t minIndex = i;
				for (size_t j = i + 1; j < limit; ++j)
				{
					if (option == 0)
					{
						if (sorted[j]->getPrice() < sorted[minIndex]->getPrice())
							minIndex = j;
					}
					else
					{
						if (sorted[j]->getMileage() < sorted[minIndex]->getMileage())
							minIndex = j;
					}
					
				}
				Car* temp = sorted[i];
				sorted[i] = sorted[minIndex];
				sorted[minIndex] = temp;
			}

			std::cout << (option == 0 ? "\nEmployees by price:\n" : "\nEmployees by number of mileage:\n");

			for (size_t k = 0; k < limit; ++k)
				sorted[k]->print();

			delete[] sorted; sorted = nullptr;
		
	}

	void fireEmployee(size_t& limit)
	{
		char _SSN[11] = "";
		bool flag = true; // true = keep searching

		do
		{	std::cout << "\nEnter the social security number of the employee you wish to lay off: ";
			std::cin >> _SSN;
		} while (getSizeStr(_SSN) != 11);

		Employee* temp = new Employee[staffCapacity];

		for (size_t i = 0; i < limit; ++i)
		{
			if (eqStr(staff[i].getSSN(), _SSN))
			{
				std::cout << "\nFired ";
				staff[i].print();

				flag = false;
			}
			else
			{
				if (i < 1 && !flag)
				{
					std::cout << "\n\nERROR: Dealership must have at least one employee!\n";
					exit(1);
				}
				!flag ? temp[i - 1] = staff[i] : temp[i] = staff[i];		
			}			
		}
		
		delete[] staff; staff = temp;

		if (flag == true)
		{
			std::cout << "\n\nERROR: No such employee!\n"; exit(1);
		}
	}

	void sellCar(size_t& limit, size_t& limitStaff)
	{
		if (limit == 0)
		{
			std::cout << "\n\nERROR: Dealership cannot function without cars!\n";
			exit(1);
		}

		double price;
		char buffer1[1000], buffer2[1000], buffer3[1000], buffer4[1000];

		do
		{	std::cout << "\n    Car brand: "; std::cin >> buffer1;
			std::cout << "    Car model: "; std::cin >> buffer2;
			std::cout << "    Car price: "; std::cin >> price;
			std::cout << "    First name of employee who sold it: "; std::cin >> buffer3;
			std::cout << "    Their second name: "; std::cin >> buffer4;
		} while (buffer1 == nullptr || buffer1[0] == '\0' || buffer2 == nullptr || buffer2[0] == '\0' || buffer3 == nullptr || buffer3[0] == '\0' || buffer4 == nullptr || buffer4[0] == '\0' || price < 250);

		sellCarMain(buffer1, buffer2, price, buffer3, buffer4, limit, limitStaff);
	}
};

char actionMenu()
{
	char choice = 'x';

	do
	{	std::cout << "\nWhat would you like to do next? Choose a number from the menu. (if write \"K\" you will close the program)\n";
		std::cout << "\n        MENU        \n\n";
		std::cout << "1. Change CEO.\n2. Add a new employee.\n3. Fire an employee.\n4. Add a new car.\n5. Mark sold car.\n6. Sort employees by experience.\n7. Sort employees by sales.\n8. Sort cars by price.\n9. Sort cars by mileage.\n    Your choice: ";
		std::cin >> choice;
	} while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8' && choice != '9' && choice != 'K');

	return choice;
}

int main()
{
	size_t employeeNumber = 0;
	size_t carNumber = 0;
	Dealership myDealership;

	std::cout << "        WELCOME TO YOUR DEALERSHIP\n";

	std::cout << "\nAn organization cannot function without an employer so let us set them up.\n";
	myDealership.setupCEO(employeeNumber);

	std::cout << "\nOk, great! Similarly, we have to know who will sell the cars - enter in your first employee.\n";
	myDealership.addEmployee(employeeNumber);
	++employeeNumber;

	std::cout << "\nPerfect! Your dealership can start working now, just add one car.\n";
	myDealership.addCar(carNumber);
	++carNumber;

	std::cout << "Awesome! You are all set and done!\n";

	while (true)
	{
		switch (actionMenu())
		{
		case '1': {myDealership.setupCEO(employeeNumber, 1); break; }
		case '2': {myDealership.addEmployee(employeeNumber); ++employeeNumber; break; }
		case '3': {myDealership.fireEmployee(employeeNumber); --employeeNumber; break; }
		case '4': {myDealership.addCar(carNumber); ++carNumber; break; }
		case '5': {myDealership.sellCar(carNumber, employeeNumber); --carNumber; break; }
		case '6': {myDealership.sortEmployee(0, employeeNumber); break; }
		case '7': {myDealership.sortEmployee(1, employeeNumber); break; }
		case '8': {myDealership.sortCars(0, carNumber); break; }
		case '9': {myDealership.sortCars(1, carNumber); break; }
		default: return 0;
		}
	}

	return 0;
}