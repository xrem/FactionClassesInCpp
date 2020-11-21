#pragma once
// Объявление клааса
class FractionClass
{
public:
	// Свойства
	int upper;
	int down;

	// Конструкторы
	FractionClass();
	FractionClass(int n);
	FractionClass(int n, int m);

	// Поведение
	void print();
	double toDouble();

	FractionClass* add(const FractionClass* other);
	FractionClass* div(const FractionClass* other);
	FractionClass* mul(const FractionClass* other);
	FractionClass* mul(const int other);
	FractionClass* sub(const FractionClass* other);

	// Friend - Дружественная функция раскрывающая детали своей имплементации (для друзей)
	friend FractionClass operator*(const FractionClass& left, const FractionClass& right);
	friend FractionClass operator*(const FractionClass& left, const int right);
	friend FractionClass operator*(const int left, const FractionClass& right);

private:
	bool is_valid;
	
	int minDivider();
	void printNormalized();
};
