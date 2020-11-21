#include <iostream>
#include "FractionClass.h"

void main()
{
	FractionClass f1 = { 1, 2 };
	FractionClass f2 = { 2 };
	FractionClass f3 = { };
	FractionClass f4 = { 2,0 };

	f1.print();
	f2.print();
	f3.print();
	f4.print();

}