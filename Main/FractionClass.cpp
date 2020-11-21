#include <iostream>
#include "FractionClass.h"

// ������������� ������������

// �� ���������
FractionClass::FractionClass()
{
	this->upper = 0;
	this->down = 1;
	this->is_valid = true;
}

// ������������ � �����������.
FractionClass::FractionClass(int n)
{
	this->upper = n;
	this->down = 1;
	this->is_valid = true;
}

FractionClass::FractionClass(int n, int m)
{
	this->upper = n;
	this->down = m;
	this->is_valid = m != 0;
}


// ������������� ������ print ������ ������ FractionClass
void FractionClass::print()
{
	if (this->is_valid == false)
	{
		std::cout << "Fraction with denominator 0 cannot exist" << std::endl;
	}
	else 
	{
		this->printNormalized();
	}
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
	return new FractionClass {
		(this->upper * other->down) + (other->upper * this->down),
		this->down * other->down
	};	
}

FractionClass* FractionClass::sub(const FractionClass* other)
{
	return new FractionClass {
		(this->upper * other->down) - (other->upper * this->down),
		this->down * other->down
	};
}

FractionClass* FractionClass::mul(const FractionClass* other)
{
	return new FractionClass {
		this->upper * other->upper,
		this->down * other->down
	};
}

// ���������� ������ ���������
FractionClass* FractionClass::mul(const int other)
{
	return new FractionClass {
		this->upper * other,
		this->down
	};
}

FractionClass* FractionClass::div(const FractionClass* other)
{
	return new FractionClass {
		this->upper * other->down,
		this->down * other->upper
	};
}

// � ������������� ��� ��������� friend
// ��������� ������� �� ������ ������, � ��������� ��� ��������� �������
FractionClass operator*(const FractionClass& left, const FractionClass& right)
{
	return FractionClass {
		left.upper * right.upper,
		left.down * right.down
	};
}

FractionClass operator*(const FractionClass& left, const int right)
{
	return FractionClass {
		left.upper * right,
		left.down
	};
}

FractionClass operator*(const int left, const FractionClass& right)
{
	// Implict (������)
	return right * left;

	// Explicit (����)
	return operator*(right, left);
}


int FractionClass::minDivider()
{
	int minDivider = 1;
	int n = this->upper;
	int m = this->down;
	int simpleNumbers[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };
	const int totalSimpleNumbers = sizeof(simpleNumbers) / sizeof(int);
	
	bool divisionPerformed = false;
	do {
		divisionPerformed = false;
		// ��������� ��������
		int min = n < m ? n : m;

		/* ��������� ������� ��������� �������� � ���� ������� ��������� �������� �����������:
		if (n < m)
		{
			min = n;
		} else
		{
			min = m;
		}
		*/
		int index = 0;
		for ( ; index < totalSimpleNumbers - 1; index++)
		{
			if (simpleNumbers[index] >= min)
			{
				if (index > 0)
				{
					index--;
				}
				break;
			}
		}

		for (; index >= 0; index--)
		{
			const int divider = simpleNumbers[index];
			if ((m % divider == 0) && (n % divider == 0)) {
				minDivider *= divider;
				n /= divider;
				m /= divider;
				divisionPerformed = true;
				break;
			}
		}
	} while (divisionPerformed);
	
	return minDivider;
}
