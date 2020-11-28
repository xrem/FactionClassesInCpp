#pragma once
// ���������� ������
class FractionClass
{
public:
	// ��������
	int upper;
	int down;

	// ������������
	explicit FractionClass();
	explicit FractionClass(int n);
	explicit FractionClass(int n, int m);
	FractionClass(double);
	

	// ���������
	void print();
	double toDouble();

	FractionClass* add(const FractionClass* other);
	FractionClass* div(const FractionClass* other);
	FractionClass* mul(const FractionClass* other);
	FractionClass* mul(const int other);
	FractionClass* sub(const FractionClass* other);

	// Friend - ������������� ������� ������������ ������ ����� ������������� (��� ������)
	friend FractionClass operator*(const FractionClass& left, const FractionClass& right);
	friend FractionClass operator*(const FractionClass& left, const int right);
	friend FractionClass operator*(const int left, const FractionClass& right);

	operator double();

//	operator=

private:
	bool is_valid;
	
	int minDivider();
	void printNormalized();
};
