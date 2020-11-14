#include <iostream>
#include "FractionStruct.h"
#include "FractionClass.h"

void main()
{
	Fraction halfStruct = { 1, 2 };
	printFraction(halfStruct);

	FractionClass quarter = { 1, 4 };
	FractionClass notNormalizedQuarter = { 2, 8 };

	FractionClass* half = quarter.add(&notNormalizedQuarter);
	half->print();
	std::cout << half->toDouble() << std::endl;
	
	quarter.print();
	std::cout << quarter.toDouble() << std::endl;
	notNormalizedQuarter.print();
}