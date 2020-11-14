#pragma once
// Объявление клааса
class FractionClass
{
public:
	// Свойства
	int upper;
	int down;

	// Поведение
	void print();
	double toDouble();

	FractionClass* add(const FractionClass* other);
	
	// TODO: Деление
	FractionClass* div(const FractionClass* other);
	
	// TODO: Вычитание
	FractionClass* sub(const FractionClass* other);

private:
	int minDivider();
	void printNormalized();
};
