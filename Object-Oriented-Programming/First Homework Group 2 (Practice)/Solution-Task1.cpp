#include "pch.h"
#include <iostream>
const size_t NAME = 32;
const size_t MAX_ICE_CREAMS = 50;

struct IceCreamFlavour
{
	char name[NAME];
	double ballPrice;
};

class IceCream
{
private: //change the order!
	size_t numberofBalls;
	double fullPrice;
	char name[NAME];
	IceCreamFlavour flavour;

public:
	void setName() //you don't have these do you ? :D
	{
		std::cin.getline(name, NAME);
	}

	void setFlname()
	{
		std::cin.getline(flavour.name, NAME);
	}

	void setBallPrice()
	{
		std::cin >> flavour.ballPrice;
	}

	void setFullPrice()
	{
		fullPrice = flavour.ballPrice * numberofBalls;
	}

	double getFullPrice() const
	{
		return fullPrice;
	}

	void setBallNumber()
	{
		std::cin >> numberofBalls;
	}

	const char* getName() const
	{
		return name;
	}

	const char* getFlName() const
	{
		return flavour.name;
	}

	size_t getNBalls() const
	{
		return numberofBalls;
	}

	void print()
	{
		std::cout << name << " " << fullPrice << std::endl;
	}
};

IceCream* getBestIcecream(IceCream* ptrIceCeams[], size_t size, double& money, IceCream* dptrBest) // is not **
{
	if (size < 2) // changed!
		return *ptrIceCeams; //is not **

	if (ptrIceCeams[size - 2]->getFullPrice() < money && ptrIceCeams[size - 2]->getNBalls() >= dptrBest->getNBalls() && ptrIceCeams[size - 2]->getFullPrice() >= dptrBest->getFullPrice())
		dptrBest = ptrIceCeams[size - 2];

	return getBestIcecream(ptrIceCeams, size--, money, dptrBest); // the last two are in reverse
}

bool equalStr(const char str1[], const char str2[])
{
	if (str1[0] == '\0' && str2[0] == '\0')
		return true;

	if (str1[0] != str2[0] || str1[0] == '\0' || str2[0] == '\0')
		return false;

	return equalStr(str1 + 1, str2 + 1);
}

void bonusFunction(IceCream* ptrIceCreams[], size_t size, char flavour[])
{
	bool is = false;
	for (size_t i = 0; i < size; ++i)
	{
		if (equalStr(ptrIceCreams[i]->getFlName(), flavour))
		{
			is = true;
			std::cout << ptrIceCreams[i]->getName() << std::endl;
		}
	}

	if (!is)
		std::cout << "There are no such ice creams." << std::endl;
}

int main()
{	
	char proceed = 'x';
	size_t size = 0;
	double pocketMoney;
	IceCream currentlyAvailableIceCreams[MAX_ICE_CREAMS];
	
	do // this will create the difference ice creams
	{
		std::cout << "Enter name of ice cream: ";
		currentlyAvailableIceCreams[size].setName();
		// in list you are going to a private variable
		std::cout << "Ice cream " << currentlyAvailableIceCreams[size].getName() << ":\n";
		std::cout << "    Enter flavour name: ";
		currentlyAvailableIceCreams[size].setFlname();

		do
		{
			std::cout << "    Enter price per ball: ";
			currentlyAvailableIceCreams[size].setBallPrice();
			std::cout << "    Enter number of balls: ";
			currentlyAvailableIceCreams[size].setBallNumber();
			currentlyAvailableIceCreams[size].setFullPrice();
			std::cout << "    Ice cream will cost " << currentlyAvailableIceCreams[size].getFullPrice();

			std::cout << "    Proceed? (Y/N) ";
			std::cin >> proceed;
		} while (proceed == 'N' || proceed == 'n');

		std::cout << "Create new ice cream? (Y/N) ";
		++size;
		std::cin >> proceed;
		std::cin.ignore();
	} while (proceed == 'Y' || proceed == 'y');
	
	std::cout << "\nEnter child's pocket money: ";
	std::cin >> pocketMoney;

	IceCream* ptrIceCreams[MAX_ICE_CREAMS];
	for (size_t i = 0; i < size; ++i)
	{
		*ptrIceCreams = &currentlyAvailableIceCreams[i];
	}

	bool flag = true;

	for (size_t i = 0; i < size && flag; i++)
		if (pocketMoney > ptrIceCreams[i]->getFullPrice())
			flag = false;

	if (flag)
	{
		std::cout << "\n\n    Result: Child cannot buy any ice cream.";
	}
	else
	{
		IceCream* dptrBest = &currentlyAvailableIceCreams[0];

		std::cout << "\n\n    Result: ";
		(getBestIcecream(ptrIceCreams, size, pocketMoney, dptrBest))->print();
	}

	std::cin.ignore();

	char _flavour[NAME];
	std::cout << "Show ice cream with flavour: (write the name of the flavour) ";
	std::cin.getline(_flavour, NAME);

	bonusFunction(ptrIceCreams, size, _flavour);

	return 0;
}