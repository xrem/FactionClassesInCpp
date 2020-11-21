#pragma once
// ���������� ������
class FractionClass
{
public:
	// ��������
	int upper;
	int down;

	// ������������
	FractionClass();
	FractionClass(int n);
	FractionClass(int n, int m);

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

private:
	bool is_valid;
	
	int minDivider();
	void printNormalized();
};
