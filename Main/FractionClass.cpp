#include <iostream>
#include "FractionClass.h"

// Имплементация метода print внутри класса FractionClass
void FractionClass::print()
{
	this->printNormalized();
}

void FractionClass::printNormalized()
{
	std::cout << this->upper / this->minDivider() << "/" << this->down / this->minDivider() << std::endl;
}

double FractionClass::toDouble()
{
	return (double)this->upper / (double)this->down;
}

FractionClass* FractionClass::add(const FractionClass* other)
{
	FractionClass* result = new FractionClass();
	result->down = this->down * other->down;
	result->upper = (this->upper * other->down) + (other->upper * this->down);
	return result;
}

int FractionClass::minDivider()
{
	// TODO: Доделать нахождение наименьшего общего делителя.
	if ((this->upper % 2 == 0) && (this->down % 2 == 0)) {
		return 2;
	}
	else
	{
		return 1;
	}
}
