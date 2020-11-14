#include <iostream>
#include "FractionStruct.h"

// Имплементация
void printFraction(Fraction f)
{
	std::cout << f.upper << "/" << f.down << std::endl;
}